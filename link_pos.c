/*
** EPITECH PROJECT, 2023
** link 2 position
** File description:
** link pos
*/

#include "include/struct.h"

void line_low(sfVector2i mouse, sfVector2i mouse2, pix_t *pix, sfTexture *text)
{
    float dx = mouse2.x - mouse.x;
    float dy = mouse2.y - mouse.y;
    float yi = 1;
    if (dy < 0) {
        yi = -1;
        dy *= -1;
    }
    float D = (2 * dy) - dx;
    float y = mouse.y;
    for (int x = mouse.x; x <= mouse2.x; x++) {
        thickness(pix, text, (sfVector2i) {x, y});
        if (D > 0) {
            thickness(pix, text, (sfVector2i) {x, y});
            y = y + yi;
            D = D + (2 * (dy - dx));
        } else {
            thickness(pix, text, (sfVector2i) {x, y});
            D = D + 2 * dy;
        }
    }
}

void line_high(sfVector2i mouse, sfVector2i mouse2, pix_t *pix, sfTexture *text)
{
    float dx = mouse2.x - mouse.x;
    float dy = mouse2.y - mouse.y;
    float xi = 1;
    if (dx < 0) {
        xi = -1;
        dx *= -1;
    }
    float D = (2 * dx) - dy;
    float x = mouse.x;
    for (int y = mouse.y; y <= mouse2.y; y++) {
        if (D > 0) {
            thickness(pix, text, (sfVector2i) {x, y});
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else {
            thickness(pix, text, (sfVector2i) {x, y});
            D = D + 2 * dx;
        }
    }
}

void plotline(sfVector2i mouse, sfVector2i mouse2, pix_t *pix, sfTexture *text)
{
    if (mouse2.x == 0 && mouse2.y == 0)
        return;
    if (abs(mouse2.y - mouse.y) < abs(mouse2.x - mouse.x)) {
        if (mouse.x > mouse2.x)
            line_low(mouse2, mouse, pix, text);
        else
            line_low(mouse, mouse2, pix, text);
    } else {
        if (mouse.y > mouse2.y)
            line_high(mouse2, mouse, pix, text);
        else
            line_high(mouse, mouse2, pix, text);
    }
}
