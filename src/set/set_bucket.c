/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** set_bucket
*/

#include "my_paint.h"
#include "define.h"

void set_bucket(void *, graphical_tool_t *tool)
{
    tool->tool = BUCKET;
    return;
}
