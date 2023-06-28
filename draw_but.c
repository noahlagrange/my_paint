/*
** EPITECH PROJECT, 2023
** draw_but
** File description:
** //////////////////
*/

#include "struct.h"

void draw_but(button_t *but, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, but->button, NULL);
    sfRenderWindow_drawSprite(win, but->icon, NULL);;
}

void draw_bar(bar_t *bar, sfRenderWindow *window)
{
    draw_but(bar->edit, window);
    draw_but(bar->pen, window);
    draw_but(bar->brush, window);
    draw_but(bar->seal, window);
    draw_but(bar->pot, window);
}

void draw_nav(nav_bar_t *nav, sfRenderWindow *win)
{
    draw_but(nav->file, win);
    draw_but(nav->help, win);
}

void size_is_pressed(form_t **color)
{
    for (int i = 0; color[i] != NULL; i++) {
        if (color[i]->click == 1) {
            sfRectangleShape_setOutlineThickness(color[i]->rect, 2.5);
            sfRectangleShape_setOutlineColor(color[i]->rect, sfRed);
        }
    }
}

void typef_is_pressed(typef_t **color)
{
    for (int i = 0; color[i] != NULL; i++) {
        if (color[i]->click == 1) {
            sfRectangleShape_setOutlineThickness(color[i]->rect, 2.5);
            sfRectangleShape_setOutlineColor(color[i]->rect, sfRed);
        }
    }
}
