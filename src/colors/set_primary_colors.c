/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** set_colors
*/

#include "color.h"

void set_red(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[RED];
}

void set_blue(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLUE];
}

void set_green(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[GREEN];
}

void set_yellow(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[YELLOW];
}
