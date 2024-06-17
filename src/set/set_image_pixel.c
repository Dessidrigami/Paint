/*
** EPITECH PROJECT, 2024
** set_pixel_image
** File description:
** set_pixel_image
*/

#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"
#include "texture.h"

void draw_square(paint_t *paint, sfVector2i *mouse, graphical_tool_t *tools)
{
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2f position = {(WIDTH - size_image.x) / 2.0,
    (HEIGHT - size_image.y) * (2.0 / 3.0)};
    int mouse_x = mouse->x - (tools->width / 2);
    int mouse_y = mouse->y - (tools->height / 2);

    for (int i = 0; i < tools->height; i++) {
        for (int j = 0; j < tools->width; j++) {
            sfImage_setPixel(paint->image, (mouse_x + j) - position.x,
            (mouse_y + i) - position.y, tools->color);
        }
    }
}

static void set_pixel_circle(paint_t *paint, sfVector2i *mouse,
    graphical_tool_t *tools, int i)
{
    int radius = tools->width / 2;
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2f position = {(WIDTH - size_image.x) / 2.0,
    (HEIGHT - size_image.y) * (2.0 / 3.0)};

    for (int j = mouse->y -radius; j <= radius + mouse->y; j++) {
        if ((i - mouse->x) * (i - mouse->x) + (j - mouse->y) *
        (j - mouse->y) < radius * radius) {
            sfImage_setPixel(paint->image, i - position.x,
            j - position.y, tools->color);
        }
    }
    return;
}

void draw_circle(paint_t *paint, sfVector2i *mouse, graphical_tool_t *tools)
{
    int radius = tools->width / 2;

    for (int i = mouse->x -radius; i <= radius + mouse->x; i++) {
        set_pixel_circle(paint, mouse, tools, i);
    }
}

static void check_square(sfVector2i *mouse,
    graphical_tool_t *tools, sfFloatRect *rect)
{
    if (mouse->x <= rect->left + (tools->width / 2))
        tools->width = (mouse->x - rect->left) * 2;
    if (mouse->x >= rect->left + rect->width - (tools->width / 2))
        tools->width = (rect->left + rect->width - mouse->x) * 2;
    if (mouse->y <= rect->top + (tools->height / 2))
        tools->height = (mouse->y - rect->top) * 2;
    if (mouse->y >= rect->top + rect->height - (tools->height / 2))
        tools->height = (rect->top + rect->height - mouse->y) * 2;
}

static void check_circle(sfVector2i *mouse,
    graphical_tool_t *tools, sfFloatRect *rect)
{
    if (mouse->x <= rect->left + (tools->width / 2))
        tools->width = (mouse->x - rect->left) * 2;
    if (mouse->x >= rect->left + rect->width - (tools->width / 2))
        tools->width = (rect->left + rect->width - mouse->x) * 2;
    if (mouse->y <= rect->top + (tools->width / 2))
        tools->width = (mouse->y - rect->top) * 2;
    if (mouse->y >= rect->top + rect->height - (tools->width / 2))
        tools->width = (rect->top + rect->height - mouse->y) * 2;
}

static sfBool check_collision(paint_t *paint, sfVector2i *mouse,
    graphical_tool_t *tools)
{
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2f position = {(WIDTH - size_image.x) / 2.0,
    (HEIGHT - size_image.y) * (2.0 / 3.0)};
    sfFloatRect rect = {position.x, position.y, size_image.x, size_image.y};

    if (!sfFloatRect_contains(&rect, mouse->x, mouse->y))
        return sfFalse;
    if (tools->shape == SQUARE)
        check_square(mouse, tools, &rect);
    else
        check_circle(mouse, tools, &rect);
    return sfTrue;
}

void set_pixel(sfRenderWindow *window, paint_t *paint,
    graphical_tool_t *tools)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    graphical_tool_t new_tools = *tools;

    if (check_collision(paint, &mouse, &new_tools) == sfFalse)
        return;
    if (new_tools.tool == ERASER)
        new_tools.color = sfTransparent;
    if (new_tools.tool == BUCKET || new_tools.tool == HAMMER)
        return fill_area(window, paint, tools);
    if (new_tools.shape == SQUARE)
        draw_square(paint, &mouse, &new_tools);
    else
        draw_circle(paint, &mouse, &new_tools);
    return;
}
