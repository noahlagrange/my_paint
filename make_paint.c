/*
** EPITECH PROJECT, 2023
** make txture and sprite to peindre
** File description:
** ////////////////
*/

#include "./include/struct.h"

mona_t *make_mona(void)
{
    mona_t *mona = malloc(sizeof(mona_t));
    mona->sprite = sfSprite_create();
    mona->texture = sfTexture_createFromFile("asset/fond.jpg", NULL);
    sfSprite_setTexture(mona->sprite, mona->texture, sfTrue);
    sfSprite_setPosition(mona->sprite, (sfVector2f) {133 , 57});
    return mona;
}
