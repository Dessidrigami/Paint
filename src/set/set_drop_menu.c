/*
** EPITECH PROJECT, 2024
** set_drop_menu
** File description:
** set_drop_menu
*/

#include "my_paint.h"

void drop_menu_action(void *data, graphical_tool_t *)
{
    drop_menu_t *menu = (drop_menu_t *)data;

    if (menu->hide == sfTrue)
        menu->hide = sfFalse;
    else
        menu->hide = sfTrue;
}
