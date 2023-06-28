/*
** EPITECH PROJECT, 2023
** nav_bar_setting hover
** File description:
** set the hover
*/

#include "include/struct.h"

int changes_click(mona_t *mona)
{
    sfImage *img = sfTexture_copyToImage(mona->texture);
    sfImage_saveToFile(img, "save.jpg");
    return 1;
}

void bar_nav_inter(nav_bar_t *bar, sfRenderWindow *win, mona_t *mona)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    if (sfMouse_isButtonPressed(sfMouseLeft) && bar->f_save->clc == true) {
        if (changes_states_click(bar->f_save, mouse) == 1) {
            changes_click(mona);
            return;
        }
        if (changes_states_click(bar->f_new, mouse) == 1) {
            mona->texture = sfTexture_createFromFile("asset/fond.jpg", NULL);
            sfSprite_setTexture(mona->sprite, mona->texture, sfTrue);
            return;
        }
    }
}

void bar_nav_in(nav_bar_t *bar, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    if (sfMouse_isButtonPressed(sfMouseLeft) && bar->help_about->clc == true) {
        if (changes_states_click(bar->help_about, mouse) == 1) {
            draw_about(bar, win);
            return;
        }
    }
}

void bar_nav_int(nav_bar_t *bar, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    if (sfMouse_isButtonPressed(sfMouseLeft) && bar->help_help->clc == true) {
        if (changes_states_click(bar->help_help, mouse) == 1) {
            draw_help_help(bar, win);
            return;
        }
    }
}
