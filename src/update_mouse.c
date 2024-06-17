/*
** EPITECH PROJECT, 2024
** update_mouse
** File description:
** update_mouse
*/

#include "my_paint.h"
#include "mouse_tool.h"

void set_mouse_sprite(sfRenderWindow *window, sfSprite *mouse_sprite,
    sfTexture **textures, int i)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    float size = 30.0;
    sfVector2u size_texture = sfTexture_getSize(
        textures[MOUSE_TOOLS[i].texture]);
    sfVector2f scale = {size / size_texture.x, size / size_texture.y};
    sfVector2f position = {mouse.x, mouse.y - size};

    sfSprite_setTexture(mouse_sprite,
                textures[MOUSE_TOOLS[i].texture], sfFalse);
    sfSprite_setScale(mouse_sprite, scale);
    sfSprite_setPosition(mouse_sprite, position);
    sfRenderWindow_drawSprite(window, mouse_sprite, NULL);
}

void update_mouse(sfRenderWindow *window, sfSprite *mouse_sprite,
    graphical_tool_t *tools, sfTexture **textures)
{
    for (size_t i = 0; i < SIZE_MOUSE_TOOLS; i++) {
        if (tools->tool == MOUSE_TOOLS[i].tool) {
            sfRenderWindow_setMouseCursorVisible(window, sfFalse);
            set_mouse_sprite(window, mouse_sprite, textures, i);
            return;
        }
    }
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
}
