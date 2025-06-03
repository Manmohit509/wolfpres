/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-nathan.billiouw
** File description:
** process_render_computer.c
*/

#include <math.h>
#include <string.h>

#include "process.h"
#include "utils.h"
#include "asset_manager.h"

static void set_sprite_pos(process_t *process, sfSprite *sprite, sfTexture *texture)
{
    sfVector2u windowSize = sfRenderWindow_getSize(process->window.window);
    sfVector2u texSize = sfTexture_getSize(texture);
    sfVector2f scale = {
        (windowSize.x * 0.75f) / texSize.x,
        (windowSize.y * 0.75f) / texSize.y
    };
    sfVector2f position = {
        (windowSize.x - (texSize.x * scale.x)) / 2,
        (windowSize.y - (texSize.y * scale.y)) / 2
    };
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
}

static void draw_assets(process_t *process, sfSprite *sprite, char *assets_name)
{
    texture_asset_t *texture = asset_manager_get_texture(process->assets, assets_name);

    if (texture && texture->texture) {
        set_sprite_pos(process, sprite, texture->texture);
        sfRenderWindow_drawSprite(process->window.window, sprite, NULL);
    }
}

static void render_asset(process_t *process, char *asset_name)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return;
    draw_assets(process, sprite, asset_name);
    sfSprite_destroy(sprite);
}

static void update_textbox_position(process_t *process)
{
    texture_asset_t *texture = asset_manager_get_texture(process->assets, "login_input");
    sfSprite *sprite = sfSprite_create();
    set_sprite_pos(process, sprite, texture->texture);
    sfVector2f inputPos = sfSprite_getPosition(sprite);
    sfVector2f inputScale = sfSprite_getScale(sprite);
    sfVector2u inputSize = sfTexture_getSize((sfTexture *)sfSprite_getTexture(sprite));

    float textbox_x = (float)inputPos.x +
        ((inputSize.x * inputScale.x) / 2) - 195;
    float textbox_y = (float)inputPos.y +
        ((inputSize.y * inputScale.y) / 2) - 18;
    sfText_setPosition(process->computer->textBox, (sfVector2f){textbox_x, textbox_y});
}

void process_render_computer(sfRenderWindow *window, process_t *process)
{
    jojo_computer_t *computer = process->computer;

    if (computer->started == false)
        return;

    render_asset(process, "windows");
    render_asset(process, "taskbar");
    render_asset(process, "intranet");
    if (!computer->pass_mdp) {
        if (strlen(computer->input_string) > 0) {
            render_asset(process, "login_input");
        } else {
            render_asset(process, "login");
        }
        update_textbox_position(process);
        sfRenderWindow_drawText(window, computer->textBox, NULL);
    }
    sfRenderWindow_display(window);
}
