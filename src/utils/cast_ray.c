/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** cast_ray
*/

#include "utils.h"
#include "process.h"
#include <math.h>

static void run_simulation(
    game_map_t const *map,
    ray_cast_result_t *res,
    sfVector2f const pos,
    sfVector2f const offset)
{
    for (size_t dof = 0; dof < 64; dof++) {
        res->i_coords.x = (int)(res->ray.x);
        res->i_coords.y = (int)(res->ray.y);
        if (res->i_coords.x >= 0 && res->i_coords.y >= 0 &&
            res->i_coords.x < map->width && res->i_coords.y < map->height &&
            map->tiles[res->i_coords.y][res->i_coords.x] != 0) {
            res->coords = res->ray;
            res->dist = compute_distance(res->ray, pos);
            break;
        }
        res->ray.x += offset.x;
        res->ray.y += offset.y;
    }
}

static ray_cast_result_t cast_h_ray(
    game_map_t const *map,
    viewer_t const *view,
    double ra,
    sfVector2f offset)
{
    ray_cast_result_t h_res = {100000.0f, view->pos, {0, 0}, {0, 0}, false, 0};
    double atan_val = -1.0 / tan(ra);

    if (ra > M_PI) {
        h_res.ray.y = floor(view->pos.y) - 0.0001f;
        h_res.ray.x = (view->pos.y - h_res.ray.y) * atan_val + view->pos.x;
        offset.y = -1.0f;
        offset.x = -offset.y * atan_val;
    } else if (ra < M_PI) {
        h_res.ray.y = floor(view->pos.y) + 1.0f;
        h_res.ray.x = (view->pos.y - h_res.ray.y) * atan_val + view->pos.x;
        offset.y = 1.0f;
        offset.x = -offset.y * atan_val;
    } else {
        h_res.ray = view->pos;
        return h_res;
    }
    run_simulation(map, &h_res, view->pos, offset);
    return h_res;
}

static ray_cast_result_t cast_v_ray(
    game_map_t const *map,
    viewer_t const *view,
    double ra,
    sfVector2f offset)
{
    ray_cast_result_t v_res = {100000.0f, view->pos, {0, 0}, {0, 0}, true, 0};
    double ntan = -tan(ra);

    if (ra > M_PI_2 && ra < 3 * M_PI_2) {
        v_res.ray.x = floor(view->pos.x) - 0.0001f;
        v_res.ray.y = (view->pos.x - v_res.ray.x) * ntan + view->pos.y;
        offset.x = -1.0f;
        offset.y = -offset.x * ntan;
    } else if (ra < M_PI_2 || ra > 3 * M_PI_2) {
        v_res.ray.x = floor(view->pos.x) + 1.0f;
        v_res.ray.y = (view->pos.x - v_res.ray.x) * ntan + view->pos.y;
        offset.x = 1.0f;
        offset.y = -offset.x * ntan;
    } else {
        v_res.ray = view->pos;
        return v_res;
    }
    run_simulation(map, &v_res, view->pos, offset);
    return v_res;
}

ray_cast_result_t cast_ray(
    game_map_t const *map,
    viewer_t const *viewer,
    double ra,
    sfVector2f offset)
{
    ray_cast_result_t h_res = cast_h_ray(map, viewer, ra, offset);
    ray_cast_result_t v_res = cast_v_ray(map, viewer, ra, offset);
    ray_cast_result_t res = (h_res.dist < v_res.dist) ? h_res : v_res;

    res.angle = ra;
    return res;
}

bool is_wall_between(
    game_map_t const *map,
    viewer_t const *viewer,
    sfVector2f target)
{
    sfVector2f c = viewer->pos;
    sfVector2f dir = {target.x - c.x, target.y - c.y};
    float dist = compute_distance(c, target);
    float step = 0.05f;
    float traveled = 0.0f;
    sfVector2i m = {0};

    if (dist <= 0.1f)
        return false;
    dir = (sfVector2f) {dir.x / dist, dir.y / dist};
    while (traveled < dist) {
        c = (sfVector2f) {c.x + dir.x * step, c.y + dir.y * step};
        traveled += step;
        m = (sfVector2i) {(int) c.x, (int) c.y};
        if (m.x < 0 || m.y < 0 || m.x >= map->width || m.y >= map->height)
            return true;
        if (map->tiles[m.y][m.x] != 0)
            return true;
    }
    return false;
}
