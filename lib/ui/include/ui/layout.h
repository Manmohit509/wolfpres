/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** layout
*/

#ifndef UI_LAYOUT_H
    #define UI_LAYOUT_H

    #include <stdbool.h>

    #include "ui/page.h"
    #include "ui/geometry.h"

typedef enum {
    UI_ALIGN_LEFT,
    UI_ALIGN_CENTER,
    UI_ALIGN_RIGHT
} ui_align_x_t;

typedef enum {
    UI_ALIGN_TOP,
    UI_ALIGN_MIDDLE,
    UI_ALIGN_BOTTOM
} ui_align_y_t;

typedef struct {
    ui_rect_t rect;          // global layout area
    float padding_x;
    float padding_y;
    int count;               // widget count
    ui_widget_t **widgets;      // widgets array to place
    ui_align_x_t align_x;    // horizontal alignment
    ui_align_y_t align_y;    // vertical alignment
    bool use_fixed_size;     // define if the layout use fixed size
} ui_layout_config_t;

/// apply a vertical / horizontal layout automatically in the page
void ui_layout_col(ui_page_t *page, ui_layout_config_t *config);
void ui_layout_row(ui_page_t *page, ui_layout_config_t *config);

#endif /* UI_LAYOUT_H */
