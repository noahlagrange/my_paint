/*
** EPITECH PROJECT, 2023
** bar
** File description:
** ///////////////
*/

#include "struct.h"

button_t *create_buttons_nav(char *path)
{
    button_t *buttons = malloc(sizeof(button_t));
    buttons->clc = false;
    buttons->button = sfSprite_create();
    buttons->texture_b = sfTexture_createFromFile("asset/buttons.png", NULL);
    sfSprite_setTexture(buttons->button, buttons->texture_b, sfTrue);
    buttons->icon = sfSprite_create();
    buttons->texture_i = sfTexture_createFromFile(path, NULL);
    buttons->ho = sfTexture_createFromFile("asset/hoover.png", NULL);
    sfSprite_setTexture(buttons->icon, buttons->texture_i, sfTrue);
    sfSprite_scale(buttons->button, VEC2F(0.07, 0.07));
    sfSprite_scale(buttons->icon, VEC2F(0.05, 0.05));
    return buttons;
}

nav_bar_t *create_nav(nav_bar_t *nav)
{
    nav->file = create_buttons_nav("asset/FILE.png");
    nav->help = create_buttons_nav("asset/HELP.png");
    nav->f_open = create_buttons_nav("asset/open.png");
    nav->f_new = create_buttons_nav("asset/New.png");
    nav->f_save = create_buttons_nav("asset/save.png");
    nav->help_about = create_buttons_nav("asset/about.png");
    nav->help_help = create_buttons_nav("asset/HELP.png");
    return nav;
}

nav_bar_t *pos_nav(nav_bar_t *nav)
{
    sfSprite_setPosition(nav->file->button, VEC2F(1800, 100));
    sfSprite_setPosition(nav->file->icon, VEC2F(1805, 105));
    sfSprite_setPosition(nav->f_open->button, VEC2F(1800, 170));
    sfSprite_setPosition(nav->f_open->icon, VEC2F(1805, 175));
    sfSprite_setPosition(nav->f_new->button, VEC2F(1800, 240));
    sfSprite_setPosition(nav->f_new->icon, VEC2F(1805, 245));
    sfSprite_setPosition(nav->f_save->button, VEC2F(1800, 310));
    sfSprite_setPosition(nav->f_save->icon, VEC2F(1805, 315));
    sfSprite_setPosition(nav->help->button, VEC2F(1800, 500));
    sfSprite_setPosition(nav->help->icon, VEC2F(1805, 505));
    sfSprite_setPosition(nav->help_about->button, VEC2F(1750, 570));
    sfSprite_setPosition(nav->help_about->icon, VEC2F(1760, 578));
    sfSprite_setPosition(nav->help_help->button, VEC2F(1850, 570));
    sfSprite_setPosition(nav->help_help->icon, VEC2F(1860, 580));
    return nav;
}
