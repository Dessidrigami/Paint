/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** flip_image
*/

#include "my_paint.h"

void flip_horizontally(void *data, graphical_tool_t *)
{
    paint_t *paint = (paint_t *)data;

    if (paint->image == NULL)
        return;
    sfImage_flipHorizontally(paint->image);
    return;
}

void flip_vertically(void *data, graphical_tool_t *)
{
    paint_t *paint = (paint_t *)data;

    if (paint->image == NULL)
        return;
    sfImage_flipVertically(paint->image);
    return;
}
