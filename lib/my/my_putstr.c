/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
#include "lib.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
