/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** app
*/

#ifndef UI_APP_H
    #define UI_APP_H

    #include "hashmap.h"
    #include "ui/page.h"

typedef struct {
    hashmap_t *pages;      // key = name, value = page_t *
    char **stack;          // page names stack
    int stack_size;
    int stack_capacity;
} ui_app_t;

ui_app_t *ui_app_create(void);
void ui_app_destroy(ui_app_t *app);

void ui_app_add_page(ui_app_t *app, const char *name, ui_page_t *page);
ui_page_t *ui_app_current_page(ui_app_t *app);

void ui_app_push_page(ui_app_t *app, const char *name);
void ui_app_pop_page(ui_app_t *app);
void ui_app_set_active_page(ui_app_t *app, const char *name);

void ui_app_draw(ui_app_t *app, sfRenderTexture *target);
void ui_app_handle_event(
    ui_app_t *app,
    sfEvent *event,
    sfRenderTexture *target);
void ui_app_draw_debug_outline(
    ui_app_t *app,
    sfRenderTexture *target,
    sfColor color);
char const *ui_app_get_current_page_name(ui_app_t *app);

#endif /* UI_APP_H */
