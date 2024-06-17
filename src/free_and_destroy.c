/*
** EPITECH PROJECT, 2023
** free_variable
** File description:
** free_variable
*/
#include "my_paint.h"
#include "texture.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

static void destroy_textures(paint_t *paint)
{
    if (paint->textures == NULL)
        return;
    for (int i = 0; i < SIZE; i++) {
        sfTexture_destroy(paint->textures[i]);
    }
    free(paint->textures);
}

static void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfSprite_destroy(button->sprite);
    free(button);
}

static void destroy_buttons(button_t **buttons)
{
    if (buttons == NULL)
        return;
    for (int i = 0; buttons[i] != NULL; i++) {
        destroy_button(buttons[i]);
    }
    free(buttons);
}

static void destroy_drop_menus(paint_t *paint)
{
    if (paint->menus == NULL)
        return;
    for (int i = 0; paint->menus[i] != NULL; i++) {
        destroy_button(paint->menus[i]->menu_button);
        destroy_buttons(paint->menus[i]->buttons);
        free(paint->menus[i]);
    }
    free(paint->menus);
}

void destroy_entities(sfRectangleShape *background, sfSprite *drawing,
    sfSprite *mouse_sprite)
{
    sfRectangleShape_destroy(background);
    sfSprite_destroy(drawing);
    sfSprite_destroy(mouse_sprite);
}

void destroy_variable(sfRenderWindow *window, paint_t *paint)
{
    destroy_drop_menus(paint);
    destroy_buttons(paint->buttons);
    destroy_textures(paint);
    sfImage_destroy(paint->image);
    sfRenderWindow_destroy(window);
}
