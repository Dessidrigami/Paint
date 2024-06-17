/*
** EPITECH PROJECT, 2024
** set_bin
** File description:
** set_bin
*/

#include "define.h"
#include "color.h"

void set_bin(void *data, graphical_tool_t *)
{
    paint_t *paint = (paint_t *)data;
    sfVector2u size_image = sfImage_getSize(paint->image);

    sfImage_destroy(paint->image);
    paint->image = sfImage_createFromColor(size_image.x, size_image.y,
        sfTransparent);
    return;
}
