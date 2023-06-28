/*
** EPITECH PROJECT, 2023
** nav
** File description:
** ///////////////
*/

#include "struct.h"

int changes_states_click_nav_file(nav_bar_t *but, sfVector2i pos)
{
    sfFloatRect rec = sfSprite_getGlobalBounds(but->file->button);
    sfFloatRect rec_help = sfSprite_getGlobalBounds(but->help->button);
    if (sfFloatRect_contains(&rec, pos.x, pos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        but->file->click = true;
        return 1;
    } else {
        but->file->click = false;
    }
    if (sfFloatRect_contains(&rec_help, pos.x, pos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        but->help->click = true;
        return 1;
    } else {
        but->help->click = false;
    }
    return 0;
}

int changes_states_click_nav_help(nav_bar_t *but, sfVector2i pos)
{
    sfFloatRect rec_about = sfSprite_getGlobalBounds(but->help_about->button);
    sfFloatRect rec_help = sfSprite_getGlobalBounds(but->help_help->button);
    if (sfFloatRect_contains(&rec_about, pos.x, pos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        but->help_about->click = true;
        return 1;
    } else
        but->help_about->click = false;
    if (sfFloatRect_contains(&rec_help, pos.x, pos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        but->help_help->click = true;
        return 1;
    } else
        but->help_help->click = false;
    return 0;
}

int nav_actions(nav_bar_t *nav, sfRenderWindow *win)
{
    if (nav->file->click == true) {
        draw_but(nav->f_open, win);
        draw_but(nav->f_new, win);
        draw_but(nav->f_save, win);
    }
    if (nav->help->click == true) {
        draw_but(nav->help_about, win);
        draw_but(nav->help_help, win);
    }
    return 0;
}

int changes_states_click_edit_file(bar_t *but, sfVector2i pos)
{
    sfFloatRect rec = sfSprite_getGlobalBounds(but->edit->button);
    if (sfFloatRect_contains(&rec, pos.x, pos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        but->edit->click = true;
        return 1;
    } else {
        but->edit->click = false;
    }
    return 1;
}

int edit_actions(bar_t *nav, sfRenderWindow *win)
{
    draw_but(nav->edit, win);
    if (nav->edit->click == true) {
        draw_but(nav->seal, win);
        nav->seal->clc = true;
        draw_but(nav->brush, win);
        nav->brush->clc = true;
        draw_but(nav->pot, win);
        nav->pot->clc = true;
        draw_but(nav->pen, win);
        nav->pen->clc = true;
        return 0;
    }
    nav->seal->clc = false;
    nav->brush->clc = false;
    nav->seal->clc = false;
    nav->pot->clc = false;
    return 0;
}
