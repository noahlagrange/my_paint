/*
** EPITECH PROJECT, 2023
** is_broche
** File description:
** select brache
*/

#include "include/struct.h"

void is_pencil(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 1);
}

void is_pen(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 2, mou.y - 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 2, mou.y + 2);
    mou.x += 1;
    mou.y += 1;
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 2, mou.y - 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 2, mou.y + 2);
}

void is_eraser(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y + 2);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y - 2);
}

void rond(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y - 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 1, mou.y + 1);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x + 2, mou.y);
    sfTexture_updateFromPixels(tex, pix->pixel, 1, 1, mou.x - 1, mou.y);
}
