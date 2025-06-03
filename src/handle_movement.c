/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_movement
*/

#include "utils.h"
#include "wolf3d.h"

void stamina_usage(process_t *p)
{
    if (!p || !p->level) {
        return;
    }
    entity_t *e = entity_manager_get_by_tag(p->level->entities, "player");
    player_data_t *data = NULL;
    if (e == NULL || e->data == NULL) {
        return;
    }
    data = e->data;
    if (data->player_speed == 6.5f)
        data->stamina -= p->clock.delta_t * 10;
    if (data->stamina < 0)
        data->stamina = 0;
}

static int negatived_value(double const value)
{
    return value > 0 ? (int) (value) : (int) (value - 1.0);
}

static void handle_x_backward_move(
    entity_t *player,
    process_t *data,
    int ipy,
    int ip_sub_xo)
{
    player_data_t *player_data = NULL;
    if (player == NULL || player->data == NULL) {
        return;
    }
    player_data = player->data;
    if (data->inputs.backward_key && !data->inputs.forward_key &&
        (ipy >= (int) data->level->map->height ||
        ip_sub_xo >= (int) data->level->map->width ||
        ipy < 0 || ip_sub_xo < 0 ||
        data->level->map->tiles[ipy][ip_sub_xo] == 0)) {
        player->pos.x -= player->direction.x * player_data->player_speed *
            data->clock.delta_t;
        stamina_usage(data);
    }
}

static void handle_x_forward_move(
    entity_t *player,
    process_t *data,
    int ipy,
    int ip_add_xo)
{
    player_data_t *player_data = NULL;

    if (player == NULL || player->data == NULL) {
        return;
    }
    player_data = player->data;
    if (data->inputs.forward_key && !data->inputs.backward_key &&
        (ipy >= (int) data->level->map->height ||
        ip_add_xo >= (int) data->level->map->width ||
        ip_add_xo < 0 || ipy < 0 ||
        data->level->map->tiles[ipy][ip_add_xo] == 0)) {
        player->pos.x += player->direction.x * player_data->player_speed *
            data->clock.delta_t;
        stamina_usage(data);
    }
}

static void handle_y_backward_move(
    entity_t *player,
    process_t *data,
    int ip_sub_yo,
    int ipx)
{
    player_data_t *player_data = NULL;

    if (player == NULL || player->data == NULL) {
        return;
    }
    player_data = player->data;
    if (data->inputs.backward_key && !data->inputs.forward_key &&
        (ip_sub_yo >= (int) data->level->map->height ||
        ipx >= (int) data->level->map->width ||
        ipx < 0 || ip_sub_yo < 0 ||
        data->level->map->tiles[ip_sub_yo][ipx] == 0)) {
        player->pos.y -= player->direction.y * player_data->player_speed *
            data->clock.delta_t;
        stamina_usage(data);
    }
}

static void handle_y_forward_move(
    entity_t *player,
    process_t *data,
    int ip_add_yo,
    int ipx)
{
    player_data_t *player_data = NULL;

    if (player == NULL || player->data == NULL) {
        return;
    }
    player_data = player->data;
    if (data->inputs.forward_key && !data->inputs.backward_key &&
        (ip_add_yo >= (int) data->level->map->height ||
        ipx >= (int) data->level->map->width ||
        ipx < 0 || ip_add_yo < 0 ||
        data->level->map->tiles[ip_add_yo][ipx] == 0)) {
        player->pos.y += player->direction.y * player_data->player_speed *
            data->clock.delta_t;
        stamina_usage(data);
    }
}

static void update_direction(entity_t *entity)
{
    entity->direction.x = (float) cos(entity->angle_deg);
    entity->direction.y = (float) sin(entity->angle_deg);
}

void handle_movement(entity_t *player, process_t *d)
{
    double x_offset = player->direction.x < 0 ? -0.1 : 0.1;
    double y_offset = player->direction.y < 0 ? -0.1 : 0.1;
    int ipx = negatived_value(player->pos.x);
    int ipy = negatived_value(player->pos.y);
    int ip_add_xo = negatived_value(player->pos.x + x_offset);
    int ip_sub_xo = negatived_value(player->pos.x - x_offset);
    int ip_add_yo = negatived_value(player->pos.y + y_offset);
    int ip_sub_yo = negatived_value(player->pos.y - y_offset);

    if (d->inputs.left_key && !d->inputs.right_key)
        player->angle_deg = format_rotation(player->angle_deg -
            ROTATE_SPEED * d->clock.delta_t);
    if (d->inputs.right_key && !d->inputs.left_key)
        player->angle_deg = format_rotation(player->angle_deg +
            ROTATE_SPEED * d->clock.delta_t);
    update_direction(player);
    handle_x_backward_move(player, d, ipy, ip_sub_xo);
    handle_y_backward_move(player, d, ip_sub_yo, ipx);
    handle_x_forward_move(player, d, ipy, ip_add_xo);
    handle_y_forward_move(player, d, ip_add_yo, ipx);
}
