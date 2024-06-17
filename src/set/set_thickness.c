/*
** EPITECH PROJECT, 2024
** set_thickness
** File description:
** set_thickness
*/

#include "graphical_tool.h"

void set_tiny_size(void *, graphical_tool_t *tools)
{
    tools->height = 10;
    tools->width = 10;
}

void set_small_size(void *, graphical_tool_t *tools)
{
    tools->height = 20;
    tools->width = 20;
}

void set_medium_size(void *, graphical_tool_t *tools)
{
    tools->height = 50;
    tools->width = 50;
}

void set_big_size(void *, graphical_tool_t *tools)
{
    tools->height = 100;
    tools->width = 100;
}
