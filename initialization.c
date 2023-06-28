/*
** EPITECH PROJECT, 2023
** init
** File description:
** /////////////////
*/

#include "struct.h"

void init_all(init_t *init)
{
    init->win = malloc(sizeof(window_t));
    init->but = malloc(sizeof(button_t));
    init->back = malloc(sizeof(back_t));
    init->buttons = malloc(sizeof(button_t));
    init->bar = malloc(sizeof(bar_t));
    init->nav = malloc(sizeof(nav_bar_t));
    init->but->hover = false;
    init->but->click = false;
    init->but->clc = false;
}
