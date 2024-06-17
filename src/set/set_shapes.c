/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** set_shapes
*/

#include "my_paint.h"

void set_square(void *, graphical_tool_t *tools)
{
    tools->shape = SQUARE;
    return;
}

void set_circle(void *, graphical_tool_t *tools)
{
    tools->shape = CIRCLE;
    return;
}
