/*
** EPITECH PROJECT, 2024
** mouse_tool
** File description:
** mouse_tool
*/

#ifndef MOUSE_TOOL_H
    #define MOUSE_TOOL_H
    #include "texture.h"
    #include "graphical_tool.h"

typedef struct mouse_tool_s {
    e_tool tool;
    e_texture texture;
} mouse_tool_t;

static unsigned int SIZE_MOUSE_TOOLS = 6;

static const mouse_tool_t MOUSE_TOOLS[] = {
    {PENCIL, PENCIL_TEXTURE},
    {BRUSH, BRUSH_TEXTURE},
    {ERASER, ERASER_TEXTURE},
    {DROPPER, DROPPER_TEXTURE},
    {BUCKET, BUCKET_TEXTURE},
    {HAMMER, HAMMER_TEXTURE}
};

#endif /* !MOUSE_TOOL_H */
