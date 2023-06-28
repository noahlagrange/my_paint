/*
** EPITECH PROJECT, 2023
** files_action
** File description:
** ////////////
*/

#include "struct.h"

int file_actions1(nav_bar_t *nav, sfRenderWindow *win)
{
    draw_but(nav->file, win);
    if (nav->file->click == true) {
        draw_but(nav->f_save, win);
        nav->f_save->clc = true;
        draw_but(nav->f_open, win);
        nav->f_open->clc = true;
        draw_but(nav->f_new, win);
        nav->f_new->clc = true;
        return 0;
    }
    nav->f_save->clc = false;
    nav->f_open->clc = false;
    nav->f_new->clc = false;
    return 0;
}

int file_actions2(nav_bar_t *nav, sfRenderWindow *win)
{
    draw_but(nav->help, win);
    if (nav->help->click == true) {
        draw_but(nav->help_about, win);
        nav->help_about->clc = true;
        draw_but(nav->help_help, win);
        nav->help_help->clc = true;
        return 0;
    }
    if (nav->help_help->click == true) {
        draw_help_help(nav, win);
        return 0;
    }
    if (nav->help_about->click == true) {
        draw_about(nav, win);
        return 0;
    }
    nav->help_about->clc = false;
    nav->help_help->clc = false;
    return 0;
}
