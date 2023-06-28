/*
** EPITECH PROJECT, 2023
** id click
** File description:
** ///////////////
*/

#include "include/struct.h"

pix_t *is_a_click(init_t *init, pix_t *pix, color_t **col)
{
    pix = click_on(col, init->win->win, pix);
    pix = click_on_size(init->form, init->win->win, pix);
    pix = click_type(init->typef, init->win->win, pix);
    return pix;
}

void set_hover(init_t *init, color_t **col)
{
    color_is_pressed(col);
    event_mouse(init->but, init->win);
    on_the_type(init->typef, init->win->win);
    on_the_size(init->form, init->win->win);
    change_buttons(init->bar, init->nav, init->but->mouse_pos);
}
