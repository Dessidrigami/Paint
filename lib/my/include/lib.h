/*
** EPITECH PROJECT, 2023
** lib
** File description:
** lib
*/

#ifndef LIB_
    #define LIB_

// print

void my_putstr(char const *str);
void my_puterr(const char *);

// count

int my_strlen(char const *str);

// compare

int my_strcmp(char const *s1, char const *s2);

// copy

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

// Malloc

char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);

#endif /* !LIB_ */
