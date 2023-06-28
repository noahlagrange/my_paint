/*
** EPITECH PROJECT, 2023
** typef
** File description:
** typef
*/

#include "include/struct.h"

typef_t *create_one(void)
{
    typef_t *col = malloc(sizeof(typef_t));
    col->sprite = sfSprite_create();
    col->texture = sfTexture_createFromFile("asset/rond.png", NULL);
    sfSprite_setTexture(col->sprite, col->texture, sfTrue);
    sfSprite_setPosition(col->sprite, (sfVector2f) {10 , 800});
    col->rect = sfRectangleShape_create();
    col->click = 0;
    sfRectangleShape_setFillColor(col->rect, sfTransparent);
    sfRectangleShape_setSize(col->rect, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(col->rect, (sfVector2f) {10, 800});
    sfRectangleShape_setOutlineThickness(col->rect, 2.0);
    sfRectangleShape_setOutlineColor(col->rect, sfBlack);
    col->box = (sfFloatRect) {8, 798, 50, 50};
    return col;
}

typef_t *create_two(void)
{
    typef_t *col = malloc(sizeof(typef_t));
    col->sprite = sfSprite_create();
    col->texture = sfTexture_createFromFile("asset/square.png", NULL);
    sfSprite_setTexture(col->sprite, col->texture, sfTrue);
    sfSprite_setPosition(col->sprite, (sfVector2f) {65 , 800});
    col->rect = sfRectangleShape_create();
    col->click = 0;
    sfRectangleShape_setFillColor(col->rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(col->rect, 2.0);
    sfRectangleShape_setSize(col->rect, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(col->rect, (sfVector2f) {65, 800});
    sfRectangleShape_setOutlineColor(col->rect, sfBlack);
    col->box = (sfFloatRect) {63, 798, 52, 52};
    return col;
}

void typef_draw(typef_t **color, sfRenderWindow *win)
{
    for (int i = 0; color[i] != NULL; i++) {
        sfRenderWindow_drawSprite(win, color[i]->sprite, NULL);
        sfRenderWindow_drawRectangleShape(win, color[i]->rect,NULL);
    }
}

void on_the_type(typef_t **color, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; color[i] != NULL; i++) {
        if (sfFloatRect_contains(&color[i]->box, mouse.x, mouse.y)) {
            sfRectangleShape_setOutlineThickness(color[i]->rect, 2.5);
            sfRectangleShape_setOutlineColor(color[i]->rect, sfRed);
        } else {
            sfRectangleShape_setOutlineThickness(color[i]->rect, 2.0);
            sfRectangleShape_setOutlineColor(color[i]->rect, sfBlack);
        }
    }
}

pix_t *click_type(typef_t **color, sfRenderWindow *win, pix_t *pix)
{
    int rap = -1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; color[i] != NULL; i++) {
        if (sfFloatRect_contains(&color[i]->box, mouse.x, mouse.y)) {
            color[i]->click = 1;
            rap = i;
            pix->form = i;
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
