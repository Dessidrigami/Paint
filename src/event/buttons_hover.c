/*
** EPITECH PROJECT, 2024
** buttons_hover
** File description:
** buttons_hover
*/

#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"
#include "color.h"

static void is_button_hover(button_t *button, sfMouseMoveEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (button->state == INVALID || button->menu == COLORS)
        return;
    if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
        sfRectangleShape_setFillColor(button->rect, color_tab[CYAN]);
        button->state = HOVER;
        return;
    }
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    button->state = DEFAULT;
    return;
}

void are_buttons_hover(sfEvent *event, paint_t *paint)
{
    for (size_t i = 0; paint->menus[i] != NULL; i++) {
        is_button_hover(paint->menus[i]->menu_button,
            &event->mouseMove);
        for (size_t j = 0; paint->menus[i]->buttons[j] != NULL &&
        paint->menus[i]->hide == sfFalse; j++) {
            is_button_hover(paint->menus[i]->buttons[j],
                &event->mouseMove);
        }
    }
    for (size_t i = 0; paint->buttons[i] != NULL; i++)
        is_button_hover(paint->buttons[i], &event->mouseMove);
    return;
}
