/*
** EPITECH PROJECT, 2023
** make size button
** File description:
** an form
*/


#include "include/struct.h"

form_t *creat_form(int pox, int poy, int rad)
{
    form_t *form = malloc(sizeof(form_t));
    form->rect = sfRectangleShape_create();
    form->click = 0;
    sfRectangleShape_setFillColor(form->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(form->rect, 2.0);
    sfRectangleShape_setOutlineColor(form->rect, sfBlack);
    sfRectangleShape_setSize(form->rect, (sfVector2f) {30, 30});
    form->form = sfCircleShape_create();
    sfRectangleShape_setPosition(form->rect, (sfVector2f) {pox, poy});
    sfCircleShape_setOrigin(form->form, (sfVector2f) {rad, rad});
    sfCircleShape_setRadius(form->form, rad);
    sfCircleShape_setPosition(form->form, (sfVector2f) {pox + 15, poy + 15});
    form->box = (sfFloatRect) {pox, poy, 30, 30};
    return form;
}

void size_draw(form_t **form, sfRenderWindow *win)
{
    size_is_pressed(form);
    for (int i = 0; form[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(win, form[i]->rect,NULL);
        sfRenderWindow_drawCircleShape(win, form[i]->form, NULL);
    }
}

void on_the_size(form_t **color, sfRenderWindow *win)
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

pix_t *click_on_size(form_t **color, sfRenderWindow *win, pix_t *pix)
{
    int rap = -1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    for (int i = 0; color[i] != NULL; i++) {
        if (sfFloatRect_contains(&color[i]->box, mouse.x, mouse.y)) {
            sfRectangleShape_setOutlineThickness(color[i]->rect, 2.5);
            sfRectangleShape_setOutlineColor(color[i]->rect, sfRed);
            color[i]->click = 1;
            rap = i;
            pix->size = i + 1;
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

form_t **create_form(void)
{
    form_t **form = malloc(sizeof(form_t) * 4);
    form[0] = creat_form(10, 720, 5);
    form[1] = creat_form(45, 720, 10);
    form[2] = creat_form(80, 720, 15);
    form[3] = NULL;
    return form;
}
