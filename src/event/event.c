/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/
#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"
#include "texture.h"

sfBool analyze_events(sfRenderWindow *window, sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return sfFalse;
        are_buttons_hover(event, paint);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            handle_pressed_button(event, paint, tools, window);
        if (event->type == sfEvtResized)
            resize_window(window);
    }
    return sfTrue;
}
