/*
** EPITECH PROJECT, 2022
** window
** File description:
** ////////
*/

#include <SFML/Window.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <time.h>
#include <unistd.h>
#include "struct.h"

void create_win(window_t *win)
{
    win->mode = (sfVideoMode){1920, 1080, 32};
    win->win = sfRenderWindow_create(win->mode, "my_paint", sfClose, NULL);
}

void win_loop(init_t *init, pix_t *pix, mona_t *mona, color_t **col)
{
    while (sfRenderWindow_isOpen(init->win->win)) {
        game_loop(init, pix, mona, col);
    }
}
