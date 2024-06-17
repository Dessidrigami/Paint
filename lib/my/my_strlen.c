/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** strlen
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return 0;
    while (str[len] != '\0')
        len += 1;
    return len;
}
