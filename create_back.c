/*
** EPITECH PROJECT, 2023
** back
** File description:
** ///////////////////////
*/

#include "struct.h"

back_t *create_background(back_t *back)
{
    back->sprite = sfSprite_create();
    back->texture = sfTexture_createFromFile("asset/back.jpg", NULL);
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    return back;
}

void draw_back(back_t *back, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, back->sprite, NULL);
}
