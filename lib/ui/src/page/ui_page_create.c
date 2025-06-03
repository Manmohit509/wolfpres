/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** page_create
*/

#include <stdlib.h>

#include "ui/page.h"

ui_page_t *ui_page_create(void)
{
    ui_page_t *page = calloc(1, sizeof(ui_page_t));

    if (!page)
        return NULL;
    page->capacity = 8;
    page->widgets = calloc(page->capacity, sizeof(ui_widget_t *));
    if (!page->widgets) {
        free(page);
        return NULL;
    }
    return page;
}
