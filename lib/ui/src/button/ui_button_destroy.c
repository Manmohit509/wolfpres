/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_button_destroy
*/

#include <stdlib.h>
#include "ui/button.h"

void ui_button_destroy(ui_widget_t *widget)
{
    ui_button_t *btn = NULL;

    if (!widget || !widget->data)
        return;
    btn = widget->data;
    if (btn->label)
        sfText_destroy(btn->label);
    if (btn->font)
        sfFont_destroy(btn->font);
    free(btn);
    free(widget);
}
