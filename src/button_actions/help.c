/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** help
*/

#include <unistd.h>
#include "my_paint.h"
#include "lib.h"

char *help_text(void)
{
    char *advice = "You can choose your tool in the second drop menu, and so "
    "can you with color, shape and thickness on the right side of drop menus."
    "\n\nThe chosen color/size/shape/tool is outlined with magenta.\n\nYou can"
    " click the trash to erase all your drawing.\n\nThe drip tool will allow "
    "you to pick up a color. Once your done with the drip, take back the "
    "pencil or brush.\n\nThe first menu allow to save, open a file or import "
    "an image.\n\n\t\t\t\tEnjoy and have fun :)\n";

    return advice;
}

void help(void *, graphical_tool_t *)
{
    char *advice = help_text();
    int size = my_strlen(advice);

    write(1, advice, size);
    return;
}
