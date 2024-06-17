/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** set_shades
*/

#include "color.h"

void set_white(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[WHITE];
}

void set_grey(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[GREY];
}

void set_brown(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BROWN];
}

void set_black(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLACK];
}
