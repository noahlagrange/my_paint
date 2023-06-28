/*
** EPITECH PROJECT, 2023
** is clicked
** File description:
** set a pressed button
*/

#include "include/struct.h"

void color_is_pressed(color_t **color)
{
    for (int i = 0; color[i] != NULL; i++) {
        if (color[i]->click == 1) {
            sfRectangleShape_setOutlineThickness(color[i]->color, 2.5);
            sfRectangleShape_setOutlineColor(color[i]->color, sfWhite);
        }
    }
}

int changes_states_click(button_t *but, sfVector2i pos)
{
    sfFloatRect rec = sfSprite_getGlobalBounds(but->button);
    if (sfFloatRect_contains(&rec, pos.x, pos.y)) {
        but->click = true;
        return 1;
    } else {
        but->click = false;
    }
    return 0;
}

pix_t *set_true(pix_t *pix, bar_t *bar)
{
    if (pix->borche == 0)
        bar->brush->click = true;
    if (pix->borche == 1)
        bar->pen->click = true;
    if (pix->borche == 2)
        bar->seal->click = true;
    return pix;
}

pix_t *set_to_black(pix_t *pix)
{
    pix->pixel[0] = 0;
    pix->pixel[1] = 0;
    pix->pixel[2] = 0;
    pix->pixel[3] = 255;
    return pix;
}

pix_t *change_broche(pix_t *pix, bar_t *bar, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    if (sfMouse_isButtonPressed(sfMouseLeft) && bar->seal->clc == true) {
        if (changes_states_click(bar->brush, mouse) == 1) {
            pix = set_to_black(pix);
            pix->borche = 0;
            return pix;
        }
        if (changes_states_click(bar->pen, mouse) == 1) {
            pix = set_to_black(pix);
            pix->borche = 1;
            return pix;
        }
        if (changes_states_click(bar->seal, mouse) == 1) {
            pix->borche = 2;
            return pix;
        }
    }
    pix = set_true(pix, bar);
    return pix;
}
