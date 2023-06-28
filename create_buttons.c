/*
** EPITECH PROJECT, 2023
** buttons
** File description:
** /////////////////////
*/

#include "struct.h"

button_t *create_buttons(char *path)
{
    button_t *buttons = malloc(sizeof(button_t));
    buttons->button = sfSprite_create();
    buttons->texture_b = sfTexture_createFromFile("asset/buttons.png", NULL);
    sfSprite_setTexture(buttons->button, buttons->texture_b, sfTrue);
    buttons->icon = sfSprite_create();
    buttons->texture_i = sfTexture_createFromFile(path, NULL);
    buttons->ho = sfTexture_createFromFile("asset/hoover.png", NULL);
    sfSprite_setTexture(buttons->icon, buttons->texture_i, sfTrue);
    sfSprite_scale(buttons->button, VEC2F(0.09, 0.09));
    sfSprite_scale(buttons->icon, VEC2F(0.1, 0.1));
    return buttons;
}

bar_t *create_buttons_all(bar_t *bar)
{
    bar->edit = create_buttons("asset/edition.png");
    bar->pen = create_buttons("asset/stylo.png");
    bar->brush = create_buttons("asset/pin.png");
    bar->pot = create_buttons("asset/seal.png");
    bar->seal = create_buttons("asset/g.png");
    return bar;
}

bar_t *pos_but(bar_t *bar)
{
    sfSprite_setPosition(bar->edit->button, VEC2F(25, 25));
    sfSprite_setPosition(bar->edit->icon, VEC2F(35, 30));
    sfSprite_setPosition(bar->pen->button, VEC2F(25, 100));
    sfSprite_setPosition(bar->pen->icon, VEC2F(35, 105));
    sfSprite_setPosition(bar->brush->button, VEC2F(25, 200));
    sfSprite_setPosition(bar->brush->icon, VEC2F(35, 205));
    sfSprite_setPosition(bar->seal->button, VEC2F(25, 300));
    sfSprite_setPosition(bar->seal->icon, VEC2F(35, 305));
    sfSprite_setPosition(bar->pot->button, VEC2F(25, 400));
    sfSprite_setPosition(bar->pot->icon, VEC2F(35, 405));
    return bar;
}
