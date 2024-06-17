/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** strncpy
*/

#include "lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_src = my_strlen(src);

    while (n > 0 && len_src > i) {
        dest[i] = src[i];
        i ++;
        n --;
    }
    dest[i] = '\0';
    return dest;
}
