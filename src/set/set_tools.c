/*
** EPITECH PROJECT, 2024
** set_bin
** File description:
** set_bin
*/

#include "color.h"

void set_eraser(void *, graphical_tool_t *tools)
{
    tools->tool = ERASER;
    return;
}

void set_brush(void *, graphical_tool_t *tools)
{
    tools->tool = BRUSH;
    return;
}

void set_pencil(void *, graphical_tool_t *tools)
{
    tools->tool = PENCIL;
    return;
}

void set_dropper(void *, graphical_tool_t *tools)
{
    tools->tool = DROPPER;
    return;
}
