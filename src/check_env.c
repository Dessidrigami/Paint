/*
** EPITECH PROJECT, 2024
** check_env
** File description:
** check_env
*/

#include "my_paint.h"
#include "lib.h"

sfBool check_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++){
        if (my_strcmp(env[i], "DISPLAY=:0") == 0)
            return sfTrue;
    }
    return sfFalse;
}
