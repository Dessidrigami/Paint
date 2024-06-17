/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** color
*/

#ifndef COLOR_H_
    #define COLOR_H_
    #include "my_paint.h"

enum colors {
    RED = 0,
    GREEN,
    BLADE_GREEN,
    BLUE,
    CYAN,
    YELLOW,
    BLADE_YELLOW,
    ORANGE,
    PURPLE,
    BLADE_PURPLE,
    PINK,
    BEIGE,
    BROWN,
    GREY,
    WHITE,
    BLACK,
    BACKGROUND_COLOR,
    NB_COLORS
};

static const sfColor color_tab[NB_COLORS] = {
    {.r = 255, .g = 0, .b = 0, .a = 255},
    {.r = 0, .g = 153, .b = 0, .a = 255},
    {.r = 0, .g = 255, .b = 0, .a = 255},
    {.r = 0, .g = 0, .b = 255, .a = 255},
    {.r = 0, .g = 255, .b = 255, .a = 255},
    {.r = 255, .g = 255, .b = 0, .a = 255},
    {.r = 255, .g = 255, .b = 203, .a = 255},
    {.r = 255, .g = 128, .b = 0, .a = 255},
    {.r = 127, .g = 0, .b = 255, .a = 255},
    {.r = 255, .g = 153, .b = 255, .a = 255},
    {.r = 255, .g = 102, .b = 178, .a = 255},
    {.r = 255, .g = 204, .b = 153, .a = 255},
    {.r = 153, .g = 76, .b = 0, .a = 255},
    {.r = 128, .g = 128, .b = 128, .a = 255},
    {.r = 255, .g = 255, .b = 255, .a = 255},
    {.r = 0, .g = 0, .b = 0, .a = 255},
    {.r = 224, .g = 224, .b = 224, .a = 255},
};

#endif /* !COLOR_H_ */
