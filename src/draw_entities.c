/*
** EPITECH PROJECT, 2024
** draw_entities
** File description:
** draw_entities
*/

#include "my_paint.h"

void draw_pixels(sfRenderWindow *window, sfSprite *drawing)
{
    if (drawing == NULL)
        return;
    sfRenderWindow_drawSprite(window, drawing, NULL);
}

void draw_buttons(sfRenderWindow *window, button_t **buttons)
{
    for (size_t j = 0; buttons[j] != NULL; j++) {
        sfRenderWindow_drawRectangleShape(window,
        buttons[j]->rect, NULL);
        if (buttons[j]->menu != COLORS)
            sfRenderWindow_drawSprite(window, buttons[j]->sprite, NULL);
    }
}

void draw_drop_menus(sfRenderWindow *window, drop_menu_t **menus)
{
    for (size_t i = 0; menus[i] != 0; i++) {
        sfRenderWindow_drawRectangleShape(window,
        menus[i]->menu_button->rect, NULL);
        sfRenderWindow_drawSprite(window,
        menus[i]->menu_button->sprite, NULL);
        if (menus[i]->hide == sfFalse)
            draw_buttons(window, menus[i]->buttons);
    }
}

void draw_entities(sfRenderWindow *window, sfRectangleShape *background,
    paint_t *paint, sfSprite *drawing)
{
    sfRenderWindow_drawRectangleShape(window, background, NULL);
    draw_pixels(window, drawing);
    draw_drop_menus(window, paint->menus);
    draw_buttons(window, paint->buttons);
}
