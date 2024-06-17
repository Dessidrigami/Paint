/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** central_loop
*/

#include "color.h"

void central_loop(sfRenderWindow *window, paint_t *paint)
{
    sfEvent event;
    graphical_tool_t tools = create_tools();
    sfRectangleShape *background = sfRectangleShape_create();
    sfSprite *drawing = init_drawing(paint);
    sfSprite *mouse_sprite = sfSprite_create();

    if (background == NULL || drawing == NULL || mouse_sprite == NULL)
        return;
    set_window_entities(background);
    while (sfRenderWindow_isOpen(window)) {
        if (analyze_events(window, &event, paint, &tools) == sfFalse)
            break;
        draw_entities(window, background, paint, drawing);
        update_mouse(window, mouse_sprite, &tools, paint->textures);
        sfTexture_updateFromImage(paint->textures[DRAWING],
            paint->image, 0, 0);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, color_tab[BACKGROUND_COLOR]);
    }
    destroy_entities(background, drawing, mouse_sprite);
}
