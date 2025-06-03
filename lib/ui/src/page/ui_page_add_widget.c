/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** page_add_widget
*/

#include <stdlib.h>

#include "ui/page.h"

void ui_page_add_widget(ui_page_t *page, ui_widget_t *widget)
{
    ui_widget_t **widgets = NULL;

    if (page->count >= page->capacity) {
        page->capacity *= 2;
        widgets = realloc(page->widgets, page->capacity
            * sizeof(ui_widget_t *));
        if (widgets == NULL) {
            return;
        }
        page->widgets = widgets;
    }
    page->widgets[page->count] = widget;
    page->count++;
}
