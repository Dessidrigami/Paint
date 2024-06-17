/*
** EPITECH PROJECT, 2024
** set_window
** File description:
** set_window
*/

#include "my_paint.h"
#include "define.h"
#include "color.h"
#include "texture.h"

void set_window_entities(sfRectangleShape *background)
{
    sfVector2f position = {(WIDTH - WIDTH_IMAGE) / 2.0,
    (HEIGHT - HEIGHT_IMAGE) * (2.0 / 3.0)};
    sfVector2f size = {WIDTH_IMAGE, HEIGHT_IMAGE};

    sfRectangleShape_setSize(background, size);
    sfRectangleShape_setPosition(background, position);
    sfRectangleShape_setFillColor(background, sfWhite);
    return;
}
