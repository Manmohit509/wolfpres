/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** preview_widget_draw
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "render/widgets.h"
#include "process.h"

static double compute_pixel_size(sfVector2f win_size, const viewer_t *viewer)
{
    return win_size.x / (double)viewer->px_count;
}

static void correct_fish_eye(viewer_t const *viewer, ray_cast_result_t *ray)
{
    double correction = cos(viewer->angle - ray->angle);
    ray->dist *= correction;
}

static void apply_texture_coords(sfRectangleShape *shape, sfTexture *texture, const ray_cast_result_t *ray)
{
    sfVector2u tex_size = sfTexture_getSize(texture);
    double pos = ray->is_vertical_hit ? ray->coords.y : ray->coords.x;
    double offset = pos - floor(pos);

    if (ceil(ray->coords.x) != (int)ray->coords.x && ceil(ray->coords.y) != (int)ray->coords.y)
        offset = 1.0 - offset;

    sfIntRect rect = {
        .left = (int)(tex_size.x * offset),
        .top = 0,
        .width = 1,
        .height = (int)tex_size.y
    };

    sfRectangleShape_setTexture(shape, texture, sfFalse);
    sfRectangleShape_setTextureRect(shape, rect);
}

static void draw_wall_column(
    sfRenderTexture *target,
    const process_t *process,
    sfTexture *texture,
    ray_cast_result_t ray,
    double pixel_width,
    size_t column_index)
{
    sfVector2u win_size = sfRenderTexture_getSize(target);
    sfRectangleShape *rect = sfRectangleShape_create();

    if (!rect || ray.dist >= 10000) {
        if (rect) sfRectangleShape_destroy(rect);
        return;
    }

    apply_texture_coords(rect, texture, &ray);

    float wall_height = win_size.y / ray.dist;
    float y_pos = (win_size.y - wall_height) / 2.0f;

    sfRectangleShape_setPosition(rect, (sfVector2f){ pixel_width * column_index, y_pos });
    sfRectangleShape_setSize(rect, (sfVector2f){ pixel_width, wall_height });

    shader_asset_t *shader = asset_manager_get_shader(process->assets, "dark");
    sfRenderStates states = { sfBlendAlpha, sfTransform_Identity, NULL, NULL };

    if (shader && shader->shader) {
        sfShader_setFloatUniform(shader->shader, "rayDistance", ray.dist);
        sfShader_setFloatUniform(shader->shader, "maxDistance", 8.0f);
        states.shader = shader->shader;
    }

    sfRenderTexture_drawRectangleShape(target, rect, states.shader ? &states : NULL);
    sfRectangleShape_destroy(rect);
}

static void render_walls(process_t *process, sfRenderTexture *target, const viewer_t *viewer)
{
    double half_fov = DEG * ((double)viewer->fov / 2.0);
    double ray_angle = format_rotation(viewer->angle - half_fov);
    double angle_step = DEG * ((double)viewer->fov / (double)viewer->px_count);
    sfVector2f win_size = (sfVector2f){
        sfRenderTexture_getSize(target).x,
        sfRenderTexture_getSize(target).y
    };
    double pixel_width = compute_pixel_size(win_size, viewer);

    for (size_t col = 0; col < viewer->px_count; col++) {
        sfVector2f offset = { cos(ray_angle) * 0.1f, sin(ray_angle) * 0.1f };
        ray_cast_result_t ray = cast_ray(process->level->map, viewer, ray_angle, offset);
        correct_fish_eye(viewer, &ray);

        int block_id = process->level->map->tiles[ray.i_coords.y][ray.i_coords.x];
        char key[32];
        snprintf(key, sizeof(key), "block_%d", block_id);

        texture_asset_t *asset = asset_manager_get_texture(process->assets, key);
        if (asset && asset->texture)
            draw_wall_column(target, process, asset->texture, ray, pixel_width, col);

        ray_angle = format_rotation(ray_angle + angle_step);
    }
}

static void apply_player_render(
    player_data_t *data,
    shader_asset_t *shader)
{
    sfShader_setBoolUniform(shader->shader, "is_flashlight_on",
        data->has_flashlight);
}

void preview_widget_draw(ui_widget_t *self, sfRenderTexture *target)
{
    sfVector2u size = sfRenderTexture_getSize(target);
    if (!self || !target || !self->data)
        return;

    preview_data_t *data = self->data;
    process_t *process = data->process;
    shader_asset_t *shader = asset_manager_get_shader(process->assets, "dark");

    entity_t *player = entity_manager_get_by_tag(process->level->entities, "player");
    if (!player || !player->data)
        return;

    viewer_t viewer = {
        .direction = player->direction,
        .pos = player->pos,
        .angle = player->angle_deg,
        .fov = 75,
        .px_count =  size.x / process->settings.render_quality
    };
    if (shader)
        apply_player_render(player->data, shader);
    render_walls(process, target, &viewer);
    process_render_entities(process, &viewer);
    process_render_weapon(process, player, player->data);

    //process_render_player_interface(process, player);
    process_render(process, &viewer, player);
}
