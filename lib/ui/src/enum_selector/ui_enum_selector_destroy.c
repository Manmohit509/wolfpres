/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_enum_selector_destroy
*/

#include <stdlib.h>

#include "ui/enum_selector.h"

#include <stdlib.h>
#include "ui/enum_selector.h"

static void destroy_textures(ui_enum_selector_t *s)
{
    if (s->textures_off) {
        for (int i = 0; i < s->entry_count; ++i)
            sfTexture_destroy(s->textures_off[i]);
        free(s->textures_off);
    }
    if (s->textures_on) {
        for (int i = 0; i < s->entry_count; ++i)
            sfTexture_destroy(s->textures_on[i]);
        free(s->textures_on);
    }
    if (s->textures_hover) {
        for (int i = 0; i < s->entry_count; ++i)
            sfTexture_destroy(s->textures_hover[i]);
        free(s->textures_hover);
    }
}

void ui_enum_selector_destroy(ui_widget_t *widget)
{
    ui_enum_selector_t *s = NULL;

    if (!widget)
        return;
    s = widget->data;
    free(widget);
    if (!s)
        return;
    destroy_textures(s);
    if (s->sprite)
        sfSprite_destroy(s->sprite);
    free(s);
}
