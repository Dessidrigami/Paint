/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** fill_drawing
*/

#include "my_paint.h"
#include "define.h"

sfBool is_same_color(sfColor *color, paint_t *paint, sfVector2i pos)
{
    sfColor current_color = sfImage_getPixel(paint->image, pos.x, pos.y);

    if (current_color.r != color->r)
        return sfFalse;
    if (current_color.g != color->g)
        return sfFalse;
    if (current_color.b != color->b)
        return sfFalse;
    if (current_color.a != color->a)
        return sfFalse;
    return sfTrue;
}

static void fill_bot_right(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2i middle = pos;

    while (pos.x < (int)size_image.x && pos.y < (int)size_image.y &&
    is_same_color(initial_area_color, paint, pos)) {
        if (pos.x == middle.x && pos.y == middle.y) {
            pos.x += 1;
            pos.y += 1;
            continue;
        }
        fill_right_side(initial_area_color, paint, pos, new_color);
        fill_bot_side(initial_area_color, paint, pos, new_color);
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.x += 1;
        pos.y += 1;
    }
    return;
}

static void fill_top_right(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2i middle = pos;

    while (pos.x < (int)size_image.x && pos.y > 0 &&
    is_same_color(initial_area_color, paint, pos)) {
        if (pos.x == middle.x && pos.y == middle.y) {
            pos.x += 1;
            pos.y -= 1;
            continue;
        }
        fill_right_side(initial_area_color, paint, pos, new_color);
        fill_top_side(initial_area_color, paint, pos, new_color);
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.x += 1;
        pos.y -= 1;
    }
    return;
}

static void fill_bot_left(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2i middle = pos;

    while (pos.x > 0 && pos.y < (int)size_image.y &&
    is_same_color(initial_area_color, paint, pos)) {
        if (pos.x == middle.x && pos.y == middle.y) {
            pos.x -= 1;
            pos.y += 1;
            continue;
        }
        fill_left_side(initial_area_color, paint, pos, new_color);
        fill_bot_side(initial_area_color, paint, pos, new_color);
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.x -= 1;
        pos.y += 1;
    }
    return;
}

static void fill_top_left(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    sfVector2i middle = pos;

    while (pos.x > 0 && pos.y > 0 &&
    is_same_color(initial_area_color, paint, pos)) {
        if (pos.x == middle.x && pos.y == middle.y) {
            pos.x -= 1;
            pos.y -= 1;
            continue;
        }
        fill_left_side(initial_area_color, paint, pos, new_color);
        fill_top_side(initial_area_color, paint, pos, new_color);
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.x -= 1;
        pos.y -= 1;
    }
    return;
}

void fill_area(sfRenderWindow *window, paint_t *paint, graphical_tool_t *tool)
{
    sfColor new_color = tool->color;
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfColor initial_area_color;

    pos.x = pos.x - (WIDTH - (int)size_image.x) / 2.0;
    pos.y = pos.y - (HEIGHT - (int)size_image.y) * (2.0 / 3.0);
    initial_area_color = sfImage_getPixel(paint->image, pos.x, pos.y);
    fill_top_right(&initial_area_color, paint, pos, &new_color);
    fill_bot_right(&initial_area_color, paint, pos, &new_color);
    fill_top_left(&initial_area_color, paint, pos, &new_color);
    fill_bot_left(&initial_area_color, paint, pos, &new_color);
    if (tool->tool == BUCKET)
        fill_cross(&initial_area_color, paint, &new_color, &pos);
    sfImage_setPixel(paint->image, pos.x, pos.y, new_color);
    return;
}
