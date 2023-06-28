/*
** EPITECH PROJECT, 2023
** ////////
** File description:
** ////////////
*/

#include "include/struct.h"

pix_t *make_framebuff(void)
{
    pix_t *pixel = malloc(sizeof(pix_t));
    pixel->pixel = malloc(1000 * 1000 * 4);
    pixel->borche = 0;
    pixel->size = 1;
    pixel->pixel[0] = 0;
    pixel->pixel[1] = 0;
    pixel->pixel[2] = 0;
    pixel->pixel[3] = 255;
    pixel->width = 1000;
    pixel->height = 1000;
    pixel->lastposx = 0;
    pixel->lastposy = 0;
    pixel->form = 1;
    return pixel;
}

void thickness(pix_t *pix, sfTexture *tex, sfVector2i mou)
{
    if (pix->borche == 0) {
        if (pix->form == 1)
            size_ofpen(pix, tex, mou);
        else
            sizeof_rond(pix, tex, mou);
    }
    if (pix->borche == 1)
        is_pen(pix, tex, mou);
    if (pix->borche == 2) {
        pix->pixel[0] = sfWhite.r;
        pix->pixel[1] = sfWhite.g;
        pix->pixel[2] = sfWhite.b;
        pix->pixel[3] = sfWhite.a;
        if (pix->form == 1)
            size_ofpen(pix, tex, mou);
        else
            sizeof_rond(pix, tex, mou);
    }
}

void draw_thing(pix_t *pix, sfTexture *tex, sfRenderWindow *win, sfSprite *spr)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
        mouse.x -= 133;
        mouse.y -= 57;
        thickness(pix, tex, mouse);
        plotline(mouse,(sfVector2i) {pix->lastposx, pix->lastposy}, pix, tex);
        pix->lastposx = mouse.x;
        pix->lastposy = mouse.y;
        sfRenderWindow_drawSprite(win, spr, NULL);
        sfRenderWindow_display(win);
    } else {
        pix->lastposx = 0;
        pix->lastposy = 0;
    }
}
