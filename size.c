/*
** EPITECH PROJECT, 2023
** sizeof pen
** File description:
** sie
*/

#include "include/struct.h"

void size_pen2(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    is_pencil(pix, tex, mou);
    mou.x += 2;
    is_pencil(pix, tex, mou);
    mou.y += 2;
    is_pencil(pix, tex, mou);
    mou.x -= 2;
    is_pencil(pix, tex, mou);
}

void size_ofpen(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    if (pix->size == 1)
        is_pencil(pix, tex, mou);
    if (pix->size == 2)
        size_pen2(pix, tex, mou);
    if (pix->size == 3) {
        size_pen2(pix, tex, mou);
        mou.x += 4;
        size_pen2(pix, tex, mou);
        mou.y += 4;
        size_pen2(pix, tex, mou);
        mou.x -= 4;
        size_pen2(pix, tex, mou);
    }
}

void sizeof_rond(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    if (pix->size == 1)
        rond(pix, tex, mou);
    if (pix->size == 2)
        rond2(pix, tex, mou);
    if (pix->size == 3)
        rond3(pix, tex, mou);
}

typef_t **create_type(void)
{
    typef_t **typeform = malloc(sizeof(typef_t *) * 3);
    typeform[0] = create_one();
    typeform[1] = create_two();
    typeform[2] = NULL;
    return typeform;
}
