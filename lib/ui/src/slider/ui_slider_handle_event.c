/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_slider_handle_event
*/

#include "ui/slider.h"

static float clamp(float val, float min, float max)
{
    if (val < min) {
        return min;
    }
    return val > max ? max : val;
}

static float project_mouse_on_axis(
    sfVector2f mouse,
    sfVector2f a,
    sfVector2f b)
{
    sfVector2f ab = {b.x - a.x, b.y - a.y};
    sfVector2f am = {mouse.x - a.x, mouse.y - a.y};
    float ab_len_sq = ab.x * ab.x + ab.y * ab.y;
    float dot = ab.x * am.x + ab.y * am.y;

    if (ab_len_sq == 0.0f)
        return 0.0f;
    return clamp(dot / ab_len_sq, 0.f, 1.f);
}

static float compute_scale(sfVector2f area, sfVector2u tex_size)
{
    float sx = area.x / (float)tex_size.x;
    float sy = area.y / (float)tex_size.y;

    return (sx < sy) ? sx : sy;
}

sfVector2f compute_sprite_size(sfVector2u tex_size, float scale)
{
    return (sfVector2f){tex_size.x * scale, tex_size.y * scale};
}

static sfVector2f compute_sprite_position(sfFloatRect rect, sfVector2f size)
{
    return (sfVector2f){
        rect.left + (rect.width - size.x) / 2.f,
        rect.top + (rect.height - size.y) / 2.f
    };
}

static void compute_slider_axis(
    ui_slider_t *s,
    sfVector2f *out_sprite_pos,
    sfVector2f *out_sprite_size,
    sfVector2f *out[2])
{
    sfVector2u tex_size = sfTexture_getSize(s->background_texture);
    float scale = compute_scale(
        (sfVector2f){s->abs_rect.width, s->abs_rect.height}, tex_size);

    *out_sprite_size = compute_sprite_size(tex_size, scale);
    *out_sprite_pos = compute_sprite_position(s->abs_rect, *out_sprite_size);
    *out[0] = (sfVector2f){
        out_sprite_pos->x + out_sprite_size->x * s->zero_point.x,
        out_sprite_pos->y + out_sprite_size->y * s->zero_point.y
    };
    *out[1] = (sfVector2f){
        out_sprite_pos->x + out_sprite_size->x * s->full_point.x,
        out_sprite_pos->y + out_sprite_size->y * s->full_point.y
    };
}

static void handle_mouse_pressed(
    ui_slider_t *s,
    const sfEvent *event,
    sfVector2f sprite_pos,
    sfVector2f sprite_size)
{
    sfVector2f mouse = {0};
    sfFloatRect sprite_bounds = {0};

    if (event->mouseButton.button != sfMouseLeft)
        return;
    mouse = (sfVector2f) {event->mouseButton.x, event->mouseButton.y};
    sprite_bounds = (sfFloatRect) {
        sprite_pos.x, sprite_pos.y,
        sprite_size.x, sprite_size.y
    };
    if (sfFloatRect_contains(&sprite_bounds, mouse.x, mouse.y))
        s->dragging = true;
}

static void handle_mouse_released(ui_slider_t *s, const sfEvent *event)
{
    if (event->mouseButton.button == sfMouseLeft)
        s->dragging = false;
}

static void handle_mouse_moved(
    ui_slider_t *s,
    const sfEvent *event,
    sfVector2f zero,
    sfVector2f full)
{
    sfVector2f mouse = {0};
    float new_value = 0;

    if (!s->dragging)
        return;
    mouse = (sfVector2f) {event->mouseMove.x, event->mouseMove.y};
    new_value = project_mouse_on_axis(mouse, zero, full);
    if (new_value != s->value) {
        s->value = new_value;
        if (s->on_change)
            s->on_change(s->value, s->user_data);
    }
}

void ui_slider_handle_event(
    ui_widget_t *widget,
    sfEvent *event,
    sfRenderTexture *target)
{
    ui_slider_t *s = widget->data;
    sfVector2f sprite_pos = {0};
    sfVector2f sprite_size = {0};
    sfVector2f zero = {0};
    sfVector2f full = {0};

    (void)target;
    compute_slider_axis(s, &sprite_pos, &sprite_size,
        (sfVector2f *[]) {&zero, &full});
    if (event->type == sfEvtMouseButtonPressed)
        handle_mouse_pressed(s, event, sprite_pos, sprite_size);
    if (event->type == sfEvtMouseButtonReleased)
        handle_mouse_released(s, event);
    if (event->type == sfEvtMouseMoved)
        handle_mouse_moved(s, event, zero, full);
}
