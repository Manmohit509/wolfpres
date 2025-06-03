/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** process_render_weapon
*/

#include "process.h"
#include "utils.h"

static void update_rect(animation_t *animation, size_t index)
{
    animation->frames.left = animation->frames.width * index;
}

static void setup_sprite_position(
    sfSprite *sprite,
    process_t *process)
{
    sfIntRect sprite_size = sfSprite_getTextureRect(sprite);
    sfVector2u win_size = sfRenderTexture_getSize(process->window.scene);

    sfSprite_setOrigin(sprite,
        (sfVector2f){sprite_size.width / 2, sprite_size.height});
    sfSprite_setPosition(sprite, (sfVector2f) {win_size.x / 2, win_size.y});
    sfSprite_setScale(sprite, (sfVector2f){2.0f, 2.0f});
}

static void display_sprite(
    process_t *process,
    animation_t *anim,
    size_t frame_index)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL) {
        return;
    }
    sfSprite_setTexture(sprite, anim->texture, sfTrue);
    update_rect(anim, frame_index);
    sfSprite_setTextureRect(sprite, anim->frames);
    setup_sprite_position(sprite, process);
    sfRenderTexture_drawSprite(process->window.scene, sprite, NULL);
    sfSprite_destroy(sprite);
}

static void handle_animation(
    entity_t *entity,
    player_data_t *data,
    process_t *process)
{
    animation_t *anim = NULL;
    size_t frame_index = 0;

    if (data->anim_state == ANIM_INSPECT)
        anim = &data->inspect_anim[data->current_weapon];
    if (data->anim_state == ANIM_ATTACK)
        anim = &data->attack_anim[data->current_weapon];
    if (!anim || !anim->texture || anim->frame_count == 0)
        return;
    frame_index = (size_t)(data->anim_timer / anim->frame_duration);
    if (frame_index >= anim->frame_count) {
        data->is_anim_playing = false;
        data->anim_state = ANIM_NONE;
        player_handle_attack(process, entity);
        return;
    }
    display_sprite(process, anim, frame_index);
    data->anim_timer += process->clock.delta_t;
}

static void handle_idle_animation(
    player_data_t *data,
    process_t *process)
{
    sfSprite *sprite = sfSprite_create();
    animation_t *anim = &data->attack_anim[data->current_weapon];

    if (!anim || !anim->texture)
        return;
    sfSprite_setTexture(sprite, anim->texture, sfTrue);
    update_rect(anim, 0);
    sfSprite_setTextureRect(sprite, anim->frames);
    setup_sprite_position(sprite, process);
    sfRenderTexture_drawSprite(process->window.scene, sprite, NULL);
    sfSprite_destroy(sprite);
}

void process_render_weapon(
    process_t *process,
    entity_t *player,
    player_data_t *data)
{
    weapon_type_t weapon = data->current_weapon;

    if (weapon >= WEAPON_NONE)
        return;
    if (data->is_anim_playing) {
        handle_animation(player, data, process);
        return;
    }
    handle_idle_animation(data, process);
}
