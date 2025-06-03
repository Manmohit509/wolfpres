/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_render_roof_and_top
*/

#include "utils.h"
#include "process.h"

void process_render_roof_and_top(process_t *process)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f const size = get_original_win_size(process->window.window);
    sfVector2f rect_size = {(float) size.x, (float) size.y / 2};

    if (shape == NULL) {
        return;
    }
    sfRectangleShape_setSize(shape, rect_size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(100, 100, 100));
    sfRenderWindow_drawRectangleShape(process->window.window, shape, NULL);
    rect_size.x = 0;
    sfRectangleShape_setPosition(shape, rect_size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(70, 70, 70));
    sfRenderWindow_drawRectangleShape(process->window.window, shape, NULL);
    sfRectangleShape_destroy(shape);
}
