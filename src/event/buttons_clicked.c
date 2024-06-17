/*
** EPITECH PROJECT, 2024
** buttons_clicked
** File description:
** buttons_clicked
*/

#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "color.h"

void outline_button(button_t *button)
{
    if (button->menu != DUMP && button->menu != FILES && button->menu != INFO)
        sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    return;
}

static void unset_outline(button_t **buttons, e_menu type)
{
    for (int i = 0; buttons[i] != NULL; i++)
        if (buttons[i]->menu == type)
            sfRectangleShape_setOutlineColor(buttons[i]->rect, sfTransparent);
    return;
}

static sfBool is_button_clicked(void *data, button_t *button,
    graphical_tool_t *tools, sfMouseButtonEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (button->state == INVALID)
        return sfFalse;
    if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
        button->function(data, tools);
        button->state = CLICKED;
        return sfTrue;
    }
    button->state = DEFAULT;
    return sfFalse;
}

static sfBool check_menu_buttons_clicked(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools, int i)
{
    for (size_t j = 0; paint->menus[i]->buttons[j] != NULL &&
    paint->menus[i]->hide == sfFalse; j++) {
        if (is_button_clicked(paint, paint->menus[i]->buttons[j],
        tools, &event->mouseButton)) {
            unset_outline(paint->menus[i]->buttons,
            paint->menus[i]->buttons[j]->menu);
            outline_button(paint->menus[i]->buttons[j]);
            return sfTrue;
        }
    }
    return sfFalse;
}

static sfBool are_buttons_clicked(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    for (size_t i = 0; paint->menus[i] != NULL; i++) {
        if (is_button_clicked(paint->menus[i], paint->menus[i]->menu_button,
            tools, &event->mouseButton))
            return sfTrue;
        if (check_menu_buttons_clicked(event, paint, tools, i)) {
            paint->menus[i]->hide = sfTrue;
            return sfTrue;
        }
    }
    for (size_t i = 0; paint->buttons[i] != NULL; i++) {
        if (is_button_clicked(paint, paint->buttons[i],
            tools, &event->mouseButton)) {
            unset_outline(paint->buttons, paint->buttons[i]->menu);
            outline_button(paint->buttons[i]);
                return sfTrue;
            }
    }
    return sfFalse;
}

void handle_pressed_button(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2u size_window = sfRenderWindow_getSize(window);
    sfVector2f position = {(size_window.x - size_image.x) / 2.0,
    (size_window.y - size_image.y) * (2.0 / 3.0)};
    sfFloatRect rect = {position.x, position.y, size_image.x, size_image.y};

    if (are_buttons_clicked(event, paint, tools))
        return;
    if (tools->tool == DROPPER &&
    sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        tools->color = sfImage_getPixel(paint->image, mouse.x - position.x,
        mouse.y - position.y);
    } else
        set_pixel(window, paint, tools);
    return;
}
