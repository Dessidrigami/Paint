/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** save_file
*/

#include "my_paint.h"
#include "lib.h"
#include <stdio.h>

sfBool check_format(char *file_name)
{
    for (int i = 0; file_name[i] != '\0'; i++) {
        if (file_name[i] == '.')
            return sfFalse;
    }
    return sfTrue;
}

char *concat_str(char const *str1, char const *str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);
    char *new_str = malloc(sizeof(char) * (len_str1 +
    len_str2 + 1));

    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < len_str1; i ++)
        new_str[i] = str1[i];
    for (int j = 0; j < len_str2; j ++)
        new_str[len_str1 + j] = str2[j];
    new_str[len_str1 + len_str2] = '\0';
    return new_str;
}

sfBool create_file_name(paint_t *paint, char *input, sfImage *new_image)
{
    char *file_name = my_strndup(input, my_strlen(input) - 1);
    char *file_name_jpg = NULL;

    if (file_name == NULL)
        return sfFalse;
    if (check_format(file_name)) {
        file_name_jpg = concat_str(file_name, ".jpg");
        sfImage_copyImage(new_image, paint->image, 0, 0,
        (sfIntRect){}, sfTrue);
        sfImage_saveToFile(new_image, file_name_jpg);
        free(file_name_jpg);
    } else {
        sfImage_copyImage(new_image, paint->image, 0, 0,
        (sfIntRect){}, sfTrue);
        sfImage_saveToFile(new_image, file_name);
    }
    free(file_name);
    return sfTrue;
}

void save_drawing(void *data, graphical_tool_t *)
{
    paint_t *paint = (paint_t *)data;
    sfVector2u size = sfImage_getSize(paint->image);
    sfImage *new_image = sfImage_createFromColor(size.x, size.y, sfWhite);
    char *input = NULL;
    size_t i = 0;
    int input_size = 0;

    my_putstr("Enter file name: ");
    input_size = getline(&input, &i, stdin);
    if (input_size == -1 ||
    create_file_name(paint, input, new_image) == sfFalse) {
        my_putstr("\nFailed to save image\n");
        free(input);
        sfImage_destroy(new_image);
        return;
    }
    my_putstr("Successfully saved\n");
    free(input);
    sfImage_destroy(new_image);
}
