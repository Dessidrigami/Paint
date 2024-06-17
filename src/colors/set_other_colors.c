/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** set_secondary_colors
*/

#include "color.h"

void set_cyan(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[CYAN];
}

void set_orange(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[ORANGE];
}

void set_purple(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[PURPLE];
}

void set_pink(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[PINK];
}

void set_beige(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BEIGE];
}
