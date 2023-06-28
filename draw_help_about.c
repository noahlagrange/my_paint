/*
** EPITECH PROJECT, 2023
** help_about
** File description:
** /////////////////
*/

#include "struct.h"

void create_about(nav_bar_t *nav)
{
    nav->sprite_about = sfSprite_create();
    nav->tex_about = sfTexture_createFromFile("asset/help1.png", NULL);
    sfSprite_setTexture(nav->sprite_about, nav->tex_about, sfTrue);
    sfSprite_setPosition(nav->sprite_about, VEC2F(1700, 600));
    sfSprite_scale(nav->sprite_about, VEC2F(0.17, 0.17));
}

void draw_about(nav_bar_t *nav, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, nav->sprite_about, NULL);
}

void create_help_help(nav_bar_t *nav)
{
    nav->sprite_help = sfSprite_create();
    nav->tex_help = sfTexture_createFromFile("asset/help2.png", NULL);
    sfSprite_setTexture(nav->sprite_help, nav->tex_help, sfTrue);
    sfSprite_setPosition(nav->sprite_help, VEC2F(1700, 600));
    sfSprite_scale(nav->sprite_help, VEC2F(0.17, 0.17));
}

void draw_help_help(nav_bar_t *nav, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, nav->sprite_help, NULL);
}
