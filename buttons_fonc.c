/*
** EPITECH PROJECT, 2023
** buttons_fonc
** File description:
** //////////////////////
*/

#include "struct.h"

int changes_states(button_t *but, sfVector2i pos)
{
    sfFloatRect rec = sfSprite_getGlobalBounds(but->button);
    if (sfFloatRect_contains(&rec, pos.x, pos.y)) {
        but->hover = true;
        return 1;
    } else {
        but->hover = false;
    }
    return 0;
}

int change_buttons(bar_t *bar, nav_bar_t *nav, sfVector2i pos)
{
    changes_states(bar->edit, pos);
    if (bar->edit->click == true) {
        changes_states(bar->brush, pos);
        changes_states(bar->pen, pos);
        changes_states(bar->pot, pos);
        changes_states(bar->seal, pos);
    }
    changes_states(nav->file, pos);
    if (nav->file->click == true) {
        changes_states(nav->f_open, pos);
        changes_states(nav->f_new, pos);
        changes_states(nav->f_save, pos);
    }
    changes_states(nav->help, pos);
    if (nav->help->click == true) {
        changes_states(nav->help_about, pos);
        changes_states(nav->help_help, pos);
    }
    return 0;
}

int uptate(button_t *but)
{
    if (but->hover == true || but->click == true)
        sfSprite_setTexture(but->button, but->ho, sfTrue);
    else
        sfSprite_setTexture(but->button, but->texture_b, sfTrue);
    return 0;
}

int buttons_actions(bar_t *bar, nav_bar_t *nav)
{
    uptate(bar->edit);
    uptate(bar->brush);
    uptate(bar->pen);
    uptate(bar->pot);
    uptate(bar->seal);
    uptate(nav->file);
    uptate(nav->f_open);
    uptate(nav->f_new);
    uptate(nav->f_save);
    uptate(nav->help);
    uptate(nav->help_about);
    uptate(nav->help_help);
    return 0;
}
