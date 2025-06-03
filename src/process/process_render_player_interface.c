/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** process_render_player_interface
*/

#include "process.h"
#include "utils.h"
#include "wolf3d.h"

static void draw_empty_bar(
    process_t *process,
    sfSprite *sprite)
{
    texture_asset_t *empty =
        asset_manager_get_texture(process->assets, "health_bar_empty");

    if (empty && empty->texture) {
        sfSprite_setTexture(sprite, empty->texture, sfTrue);
        sfRenderWindow_drawSprite(process->window.window, sprite, NULL);
    }
}

void display_health_bar(
    process_t *process,
    entity_t *player,
    UNUSED player_data_t *data)
{
    texture_asset_t *full =
        asset_manager_get_texture(process->assets, "health_bar_full");
    sfSprite *sprite = sfSprite_create();
    sfFloatRect size = {0};

    if (sprite == NULL)
        return;
    draw_empty_bar(process, sprite);
    if (full && full->texture) {
        sfSprite_setTexture(sprite, full->texture, sfTrue);
        size = sfSprite_getGlobalBounds(sprite);
        sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0,
        size.width / 100 * player->health, size.height});
        sfRenderWindow_drawSprite(process->window.window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
}

static void setup_origin(sfSprite *sprite)
{
    sfFloatRect sprite_size = sfSprite_getLocalBounds(sprite);

    sfSprite_setOrigin(sprite, (sfVector2f)
            {sprite_size.height / 2, sprite_size.width / 2});
}

static void display_interact_message(
    process_t *process,
    player_data_t *player_data)
{
    sfSprite *sprite = NULL;
    sfVector2u win_size = sfRenderWindow_getSize(process->window.window);
    sfVector2f pos = {win_size.x / 2, win_size.y / 4 * 3};
    texture_asset_t *asset = asset_manager_get_texture(process->assets,
        "interact");

    if (player_data->interaction_type == INTERACTION_NONE || !asset ||
        !asset->texture) {
        return;
    }
    sprite = sfSprite_create();
    if (!sprite)
        return;
    sfSprite_setTexture(sprite, asset->texture, sfTrue);
    setup_origin(sprite);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(process->window.window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void process_render_player_interface(
    process_t *process,
    entity_t *player)
{
    player_data_t *data = player->data;

    if (!data) {
        return;
    }
    process_render_weapon(process, player, data);
    display_health_bar(process, player, data);
    display_interact_message(process, data);
}
