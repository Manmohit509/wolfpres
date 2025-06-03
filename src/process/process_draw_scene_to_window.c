/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** process_draw_scene_to_window
*/

#include <SFML/Graphics.h>

#include "process.h"

void process_draw_scene_to_window(process_t *process, sfShader *shader)
{
    sfSprite *sprite = sfSprite_create();
    sfRenderStates states = {
        .shader = shader,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL
    };

    sfRenderTexture_display(process->window.scene);
    if (!sprite)
        return;
    sfSprite_setTexture(sprite,
        sfRenderTexture_getTexture(process->window.scene), sfTrue);
    sfRenderWindow_drawSprite(process->window.window, sprite,
        shader ? &states : NULL);
    sfSprite_destroy(sprite);
}
