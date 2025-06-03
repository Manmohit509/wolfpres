/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** page
*/

#ifndef UI_PAGE_H
    #define UI_PAGE_H

    #include "ui/widget.h"

typedef struct ui_page_s {
    ui_widget_t **widgets;
    int count;
    int capacity;
} ui_page_t;

ui_page_t *ui_page_create(void);
void ui_page_add_widget(ui_page_t *page, ui_widget_t *widget);
void ui_page_draw(ui_page_t *page, sfRenderTexture *target);
void ui_page_handle_event(
    ui_page_t *page,
    sfEvent *event,
    sfRenderTexture *target);
void ui_page_destroy(ui_page_t *page);

#endif /* UI_PAGE_H */
