/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_render_walls
*/

#include "process.h"
#include "renderer.h"
#include "utils.h"
#include "viewer.h"

static double compute_p_size(sfVector2f win_size, viewer_t const *viewer)
{
    return win_size.x / (double)viewer->px_count;
}

static double compute_rotation(viewer_t const *viewer)
{
    return DEG * (double)viewer->fov / (double)viewer->px_count;
}

static void correct_fish_eye_effect(
    viewer_t const *viewer,
    ray_cast_result_t *ray)
{
    double correction = cos(viewer->angle - ray->angle);

    ray->dist *= correction;
}

static void setup_image_texture(
    sfRectangleShape *shape,
    sfTexture *texture,
    ray_cast_result_t const *ray)
{
    sfVector2u texture_size = sfTexture_getSize(texture);
    double pos = ray->is_vertical_hit ? ray->coords.y : ray->coords.x;
    double start_perc = pos - floor(pos);
    sfIntRect rect = {0};

    if (ceil(ray->coords.x) != (int)ray->coords.x &&
        ceil(ray->coords.y) != (int)ray->coords.y) {
        start_perc = 1.0 - start_perc;
    }
    rect = (sfIntRect){
        .left = (int)(texture_size.x * start_perc),
        .top = 0,
        .width = 1,
        .height = (int)texture_size.y
    };
    sfRectangleShape_setTexture(shape, texture, sfFalse);
    sfRectangleShape_setTextureRect(shape, rect);
}

static void setup_texture(
    sfRectangleShape *shape,
    asset_manager_t *assets,
    int tile_id,
    ray_cast_result_t const *ray)
{
    char tile_key[32] = {0};
    texture_asset_t *tex = NULL;

    snprintf(tile_key, sizeof(tile_key), "block_%d", tile_id);
    tex = asset_manager_get_texture(assets, tile_key);
    if (!tex || !tex->texture) {
        sfRectangleShape_setFillColor(shape, sfRed);
        return;
    }
    setup_image_texture(shape, tex->texture, ray);
}

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

static void display_line(
    process_t *process,
    double p_size,
    ray_cast_result_t res,
    size_t r)
{
    sfVector2f win = get_original_win_size(process->window.window);
    sfRectangleShape *rect = sfRectangleShape_create();
    shader_asset_t *shader = asset_manager_get_shader(process->assets, "dark");
    sfRenderStates states = { sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    if ((res.dist >= 10000 || rect == NULL) && rect)
        sfRectangleShape_destroy(rect);
    if ((res.dist >= 10000 || rect == NULL) || !rect)
        return;
    if (res.i_coords.x >= 0 && res.i_coords.x < process->level->map->width &&
        res.i_coords.y >= 0 && res.i_coords.y < process->level->map->height)
        setup_texture(rect, process->assets,
            process->level->map->tiles[res.i_coords.y][res.i_coords.x], &res);
    sfRectangleShape_setPosition(rect, (sfVector2f){
        p_size * (double)r, (win.y - win.y / res.dist) / 2.0});
    sfRectangleShape_setSize(rect, (sfVector2f){p_size, win.y / res.dist});
    load_shader(&states, shader, res.dist);
    sfRenderTexture_drawRectangleShape(process->window.scene, rect,
        shader ? &states : NULL);
    sfRectangleShape_destroy(rect);
}

void process_render_walls(process_t *process, viewer_t *viewer)
{
    double ra = viewer->angle - DEG * (double)viewer->fov / 2.0;
    sfVector2f win_size = get_original_win_size(process->window.window);
    double p_size = compute_p_size(win_size, viewer);
    double rot_step = compute_rotation(viewer);
    sfVector2f offset = {0};
    ray_cast_result_t ray = {0};

    if (!process->level || !process->window.scene)
        return;
    for (size_t r = 0; r < viewer->px_count; r++) {
        offset = (sfVector2f){
            cos(ra) * 0.1f,
            sin(ra) * 0.1f
        };
        ray = cast_ray(process->level->map, viewer, ra, offset);
        correct_fish_eye_effect(viewer, &ray);
        display_line(process, p_size, ray, r);
        ra = format_rotation(ra + rot_step);
    }
}
