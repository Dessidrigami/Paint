/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** import_file
*/

#include "my_paint.h"
#include "unistd.h"
#include "define.h"
#include <stdio.h>

void import_file(char *line, char *filename, sfImage *image, paint_t *paint)
{
    if (line != NULL) {
        filename = clear_str(line);
        free(line);
        image = sfImage_createFromFile(filename);
        if (filename != NULL)
            free(filename);
        if (image == NULL)
            return;
        sfImage_copyImage(paint->image, image, 0, 0, (sfIntRect){0}, sfTrue);
        sfImage_destroy(image);
    }
    return;
}

void import_image(void *arg, graphical_tool_t *)
{
    paint_t *paint = (paint_t *)arg;
    sfImage *image = NULL;
    char *filename = NULL;
    char *line = NULL;
    size_t nb = 0;

    write(1, "Choose a file to load: ", 23);
    getline(&line, &nb, stdin);
    import_file(line, filename, image, paint);
    write(1, "Successfully loaded\n", 20);
    return;
}
