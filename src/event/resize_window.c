/*
** EPITECH PROJECT, 2024
** rezise_window
** File description:
** resize_window
*/

#include "my_paint.h"
#include "define.h"

void resize_window(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfFloatRect rect = {0, 0, size.x, size.y};
    sfView *view = sfView_createFromRect(rect);

    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}
