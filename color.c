/*
** EPITECH PROJECT, 2023
** set button color
** File description:
** /////////////
*/

#include "include/struct.h"

color_t *set_color(sfColor color, int pox, int poy)
{
    color_t *col = malloc(sizeof(color_t));
    col->color = sfRectangleShape_create();
    col->click = 0;
    col->box = (sfFloatRect) {pox, poy, 40, 40};
    sfRectangleShape_setFillColor(col->color, color);
    sfRectangleShape_setOutlineThickness(col->color, 2.0);
    sfRectangleShape_setOutlineColor(col->color, sfBlack);
    sfRectangleShape_setSize(col->color, (sfVector2f) {40, 40});
    sfRectangleShape_setPosition(col->color, (sfVector2f) {pox, poy});
    return col;
}

void color_draw(color_t **color, sfRenderWindow *win)
{
    for (int i = 0; color[i] != NULL; i++)
        sfRenderWindow_drawRectangleShape(win, color[i]->color,NULL);
}

void on_the_block(color_t **color, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; color[i] != NULL; i++) {
        if (sfFloatRect_contains(&color[i]->box, mouse.x, mouse.y)) {
            sfRectangleShape_setOutlineThickness(color[i]->color, 2.5);
            sfRectangleShape_setOutlineColor(color[i]->color, sfWhite);
        } else {
            sfRectangleShape_setOutlineThickness(color[i]->color, 2.0);
            sfRectangleShape_setOutlineColor(color[i]->color, sfBlack);
        }
    }
}

pix_t *click_on(color_t **color, sfRenderWindow *win, pix_t *pix)
{
    int rap = -1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; color[i] != NULL; i++) {
        if (sfFloatRect_contains(&color[i]->box, mouse.x, mouse.y)) {
            color[i]->click = 1;
            rap = i;
            sfColor set = sfRectangleShape_getFillColor(color[i]->color);
            pix->pixel[0] = set.r;
            pix->pixel[1] = set.g;
            pix->pixel[2] = set.b;
            pix->pixel[3] = set.a;
        }
    }
    if (rap == -1)
        return pix;
    for (int i = 0; color[i] != NULL; i++) {
        if (i != rap)
            color[i]->click = 0;
    }
    return pix;
}

color_t **set_the_col(void)
{
    color_t **colors = malloc(sizeof(color_t) * 7);
    colors[0] = set_color(sfBlack, 20, 500);
    colors[1] = set_color(sfMagenta, 20, 550);
    colors[2] = set_color(sfBlue, 20, 600);
    colors[3] = set_color(sfRed, 70, 500);
    colors[4] = set_color(sfGreen, 70, 550);
    colors[5] = set_color(sfYellow, 70, 600);
    colors[6] = NULL;
    return colors;
}
