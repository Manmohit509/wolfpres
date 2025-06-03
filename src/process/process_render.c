/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_render
*/

#include <string.h>

#include "process.h"
#include "wolf3d.h"
#include "renderer.h"
#include "utils.h"

static void apply_player_render(
    entity_t *entity,
    shader_asset_t *shader)
{
    player_data_t *data = NULL;

    if (strcmp(entity->tag, "player") != 0 || entity->data == NULL) {
        return;
    }
    data = entity->data;
    sfShader_setBoolUniform(shader->shader, "is_flashlight_on",
        data->has_flashlight);
}

void process_render(process_t *process, viewer_t *viewer, entity_t *entity)
{
    shader_asset_t *shader = asset_manager_get_shader(process->assets, "dark");
    sfVector2u win_size = sfRenderWindow_getSize(process->window.window);

    if (shader && shader->shader) {
        sfShader_setVec2Uniform(shader->shader, "screenSize",
            (sfGlslVec2) {win_size.x, win_size.y});
        apply_player_render(entity, shader);
    }
    sfRenderTexture_clear(process->window.scene, sfBlack);
    process_render_roof_and_top(process);
    process_render_walls(process, viewer);
    process_render_entities(process, viewer);
    process_draw_scene_to_window(process, NULL);
    if (strcmp(entity->tag, "player") == 0) {
        process_render_player_interface(process, entity);
    }
    process_render_computer(process->window.window, process);
    music_switch(process, "bg_music");
}
