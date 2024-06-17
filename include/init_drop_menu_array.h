/*
** EPITECH PROJECT, 2024
** init_drop_menu_array
** File description:
** init_drop_menu_array
*/

#ifndef INIT_DROP_MENU_ARRAY_H
    #define INIT_DROP_MENU_ARRAY_H
    #include <SFML/Graphics.h>
    #include "button_state.h"
    #include "button.h"
    #include "texture.h"
    #include "drop_menu.h"
    #include "menu.h"

static const int INIT_DROP_MENU_SIZE = 3;

static const init_buttons_t INIT_DROP_MENU[] = {
    {{45, 45}, {350, 50}, drop_menu_action, FILE_EDITOR_TEXTURE, DEFAULT,
        FILES, &sfWhite, sfTrue},
    {{45, 45}, {475, 50}, drop_menu_action, TOOL_MENU_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {600, 50}, drop_menu_action, HELP_TEXTURE, DEFAULT,
        INFO, &sfWhite, sfTrue},
};

#endif /* !INIT_DROP_MENU_ARRAY_H */
