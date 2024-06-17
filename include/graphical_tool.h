/*
** EPITECH PROJECT, 2024
** graphial_tool
** File description:
** graphical_tool
*/

#ifndef GRAPHICAL_TOOL_H
    #define GRAPHICAL_TOOL_H
    #include <SFML/Graphics.h>

typedef enum e_tool {
    MOUSE = 0,
    PENCIL,
    BRUSH,
    ERASER,
    DROPPER,
    BUCKET,
    HAMMER
} e_tool;

typedef enum e_shape {
    CIRCLE = 0,
    SQUARE
} e_shape;

typedef struct graphical_tool_s {
    int height;
    int width;
    enum e_tool tool;
    enum e_shape shape;
    sfColor color;
} graphical_tool_t;

#endif /* !GRAPHICAL_TOOL_H */
