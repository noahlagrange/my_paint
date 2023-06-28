/*
** EPITECH PROJECT, 2023
** rond broche
** File description:
** ///////////
*/

#include "include/struct.h"

void rond2_mid(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y - 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y + 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y - 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 2);
}

void rond3_mid(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 3);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 3);
}

void rond2(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    rond2_mid(pix, tex, mou);
    mou.x += 2;
    rond(pix, tex, mou);
    mou.x -= 5;
    rond(pix, tex, mou);
}

void rond3(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    rond3_mid(pix, tex, mou);
    mou.x += 1;
    rond3_mid(pix, tex, mou);
    mou.x -= 2;
    rond2(pix, tex, mou);
    mou.x += 2;
    rond2(pix, tex, mou);
}
