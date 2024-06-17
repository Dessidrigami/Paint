/*
** EPITECH PROJECT, 2024
** Robotfactory
** File description:
** clear
*/

#include <stddef.h>
#include <stdlib.h>

static int len_cleared_str(const char *str)
{
    int size = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '\n')
            size += 1;
    return size;
}

char *clear_str(const char *str)
{
    char *string = malloc(sizeof(char) * (len_cleared_str(str) + 1));
    int j = 0;

    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '\n') {
            string[j] = str[i];
            j += 1;
        }
    string[j] = '\0';
    return string;
}
