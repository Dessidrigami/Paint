/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** fill_cross
*/

#include "my_paint.h"


void fill_right_side(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    sfVector2u size_image = sfImage_getSize(paint->image);

    pos.x++;
    while (pos.x < (int)size_image.x &&
    is_same_color(initial_area_color, paint, pos)) {
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.x += 1;
    }
}

void fill_left_side(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    pos.x--;
    while (pos.x > 0 && is_same_color(initial_area_color, paint, pos)) {
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.x -= 1;
    }
}

void fill_top_side(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    pos.y--;
    while (pos.y > 0 && is_same_color(initial_area_color, paint, pos)) {
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.y -= 1;
    }
}

void fill_bot_side(sfColor *initial_area_color, paint_t *paint,
    sfVector2i pos, sfColor *new_color)
{
    sfVector2u size_image = sfImage_getSize(paint->image);

    pos.y++;
    while (pos.y < (int)size_image.y &&
    is_same_color(initial_area_color, paint, pos)) {
        sfImage_setPixel(paint->image, pos.x, pos.y, *new_color);
        pos.y += 1;
    }
}

void fill_cross(sfColor *initial_area_color, paint_t *paint,
    sfColor *new_color, sfVector2i *pos)
{
    fill_top_side(initial_area_color, paint, *pos, new_color);
    fill_bot_side(initial_area_color, paint, *pos, new_color);
    fill_left_side(initial_area_color, paint, *pos, new_color);
    fill_right_side(initial_area_color, paint, *pos, new_color);
    return;
}
