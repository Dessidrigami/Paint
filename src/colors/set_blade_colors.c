/*
** EPITECH PROJECT, 2024
** set_blade_colors
** File description:
** set_blade_colors
*/

#include "color.h"

void set_blade_yellow(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLADE_YELLOW];
}

void set_blade_green(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLADE_GREEN];
}

void set_blade_purple(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLADE_PURPLE];
}
