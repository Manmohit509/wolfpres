/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** page_destroy
*/

#include <stdlib.h>

#include "ui/page.h"

void ui_page_destroy(ui_page_t *page)
{
    for (int i = 0; i < page->count; ++i) {
        if (page->widgets[i] && page->widgets[i]->destroy)
            page->widgets[i]->destroy(page->widgets[i]);
    }
    free(page->widgets);
    free(page);
}
