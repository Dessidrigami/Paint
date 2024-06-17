/*
** EPITECH PROJECT, 2024
** my_strndup
** File description:
** my_strndup
*/

#include <stdlib.h>
#include "lib.h"

char *my_strndup(char const *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));

    dest = my_strncpy(dest, src, n);
    return dest;
}
