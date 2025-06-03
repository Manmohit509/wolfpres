/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_render_entities
*/

#include <math.h>
#include <string.h>

#include "process.h"
#include "utils.h"
#include "asset_manager.h"

static void load_shader(
    sfRenderStates *states,
    shader_asset_t *shader,
    float dist)
{
    if (shader && shader->shader) {
        sfShader_setFloatUniform(shader->shader, "rayDistance", dist);
        sfShader_setFloatUniform(shader->shader, "maxDistance", 8.0f);
        states->shader = shader->shader;
    }
}

static void setup_scale(
    float distance,
    sfVector2u win_size,
    sfSprite *sprite,
    entity_asset_t *asset)
{
    float scale = win_size.y / distance / asset->height;

    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
}

static void setup_part(
    entity_t *entity,
    viewer_t *viewer,
    sfSprite *sprite,
    entity_asset_t *asset)
{
    sfVector2f entity_dir = {
        cosf(DEG_TO_RAD(entity->angle_deg)),
        sinf(DEG_TO_RAD(entity->angle_deg))
    };
    sfVector2f to_viewer = {
        viewer->pos.x - entity->pos.x,
        viewer->pos.y - entity->pos.y
    };
    float angle_diff = compute_angle(to_viewer, entity_dir) + 180.0f;
    int part = (int)(roundf(angle_diff / (360.0f / (float)asset->face_count)))
        % asset->face_count;

    sfSprite_setTextureRect(sprite, (sfIntRect) {
        part * asset->width, entity->sprite_state * asset->height,
        asset->width, asset->height});
}

static void setup_origin(sfSprite *sprite, entity_asset_t *asset)
{
    sfSprite_setOrigin(sprite, (sfVector2f){
        asset->width / 2.0f, asset->height / 2.0f});
}

static void setup_position(sfSprite *sprite, sfVector2u win_size, float angle)
{
    sfSprite_setPosition(sprite, (sfVector2f){
        angle * win_size.x, win_size.y / 2.0f});
}

static void draw_entity(
    entity_t *e,
    viewer_t *view,
    process_t *process,
    entity_asset_t *asset)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2u win_size = sfRenderWindow_getSize(process->window.window);
    sfVector2f to_entity = {e->pos.x - view->pos.x, e->pos.y - view->pos.y};
    float angle = compute_angle(to_entity, view->direction);
    float distance = compute_distance(e->pos, view->pos);
    shader_asset_t *shader = asset_manager_get_shader(process->assets, "dark");
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    if (!sprite)
        return;
    angle = 1.0f - ((angle + view->fov / 2.0f) / view->fov);
    sfSprite_setTexture(sprite, asset->texture, sfTrue);
    setup_part(e, view, sprite, asset);
    setup_origin(sprite, asset);
    setup_position(sprite, win_size, angle);
    setup_scale(distance, win_size, sprite, asset);
    load_shader(&states, shader, distance);
    sfRenderTexture_drawSprite(process->window.scene, sprite,
        shader ? &states : NULL);
    sfSprite_destroy(sprite);
}

void process_render_entities(process_t *process, viewer_t *viewer)
{
    entity_node_t *node = NULL;
    entity_asset_t *asset = NULL;
    entity_t *e = NULL;

    entity_manager_sort(process->level->entities, viewer->pos);
    node = process->level->entities->head;
    while (node) {
        e = &node->entity;
        if (e->tag && strcmp(e->tag, "player") != 0 &&
            !is_wall_between(process->level->map, viewer, e->pos)) {
            asset = asset_manager_get_entity(process->assets, e->tag);
        }
        if (asset) {
            draw_entity(e, viewer, process, asset);
        }
        node = node->next;
        asset = NULL;
    }
}
