/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "color.h"
#include "define.h"

int main(int argc, char **argv, char **env)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = NULL;
    paint_t paint = {0};

    if (check_env(env) == sfFalse || argc > 2)
        return 84;
    window = sfRenderWindow_create(mode, "Paint", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    if (create_paint(&paint, argv[1]) == sfFalse) {
        sfRenderWindow_destroy(window);
        return 84;
    }
    sfRenderWindow_setFramerateLimit(window, FRAME);
    central_loop(window, &paint);
    sfRenderWindow_close(window);
    destroy_variable(window, &paint);
    return 0;
}
