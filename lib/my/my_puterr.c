/*
** EPITECH PROJECT, 2024
** my_puterr
** File description:
** my_puterr
*/
#include <unistd.h>

void my_puterr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
}
