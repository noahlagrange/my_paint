/*
** EPITECH PROJECT, 2023
** struct
** File description:
** //////////////////////
*/

#include <SFML/Window.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#pragma once

#define VEC2F(x , y) (sfVector2f){\
x, y \
}

#define VEC2I(x , y) (sfVector2i){\
x, y \
}

typedef struct typef_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect box;
    int click;
    sfRectangleShape *rect;
} typef_t;

typedef struct form_s {
    sfFloatRect box;
    int click;
    sfRectangleShape *rect;
    sfCircleShape *form;
} form_t;

typedef struct window_s {
    sfRenderWindow *win;
    sfVideoMode mode;
} window_t;

typedef struct button_s {
    sfFloatRect *rec;
    sfSprite *button;
    sfTexture *texture_b;
    sfSprite *icon;
    sfTexture *texture_i;
    sfTexture *ho;
    bool hover;
    bool click;
    bool clc;
    sfVector2i mouse_pos;
} button_t;

typedef struct bar_s {
    button_t *edit;
    button_t *brush;
    button_t *seal;
    button_t *pot;
    button_t *pen;
} bar_t;

typedef struct nav_bar_s {
    button_t *file;
    button_t *edition;
    button_t *help;
    button_t *help_about;
    button_t *help_help;
    button_t *f_save;
    button_t *f_open;
    button_t *f_new;
    button_t *h_des;
    button_t *e_pen;
    button_t *e_eraser;
    sfSprite *sprite_help;
    sfSprite *sprite_about;
    sfTexture *tex_help;
    sfTexture *tex_about;
} nav_bar_t;

typedef struct back_s {
    sfSprite *sprite;
    sfTexture *texture;
} back_t;

typedef struct init_s {
    window_t *win;
    button_t *but;
    sfEvent ev;
    back_t *back;
    button_t *buttons;
    bar_t *bar;
    nav_bar_t *nav;
    form_t **form;
    typef_t **typef;
} init_t;

typedef struct pix_s {
    int width;
    int height;
    sfUint8 *pixel;
    int lastposx;
    int lastposy;
    int borche;
    int size;
    int form;
} pix_t;

typedef struct mona_s {
    sfSprite *sprite;
    sfTexture *texture;
} mona_t;

typedef struct color_s {
    sfFloatRect box;
    int click;
    sfRectangleShape *color;
} color_t;

void create_win(window_t *win);
void win_loop(init_t *init, pix_t *pix, mona_t *mona, color_t **col);
void game_loop(init_t *init, pix_t *pix, mona_t *mona, color_t **col);
back_t *create_background(back_t *back);
void draw_back(back_t *back, sfRenderWindow *window);
button_t *create_buttons(char *path);
void draw_pen(bar_t *buttons, sfRenderWindow *window);
void draw_brush(bar_t *buttons, sfRenderWindow *window);
bar_t *create_buttons_all(bar_t *bar);
bar_t *pos_but(bar_t *bar);
void draw_seal(bar_t *buttons, sfRenderWindow *window);
void draw_pot(bar_t *buttons, sfRenderWindow *window);
nav_bar_t *pos_nav(nav_bar_t *nav);
nav_bar_t *create_nav(nav_bar_t *nav);
void draw_help(nav_bar_t *nav, sfRenderWindow *window);
pix_t *make_framebuff(void);
void draw_thing(pix_t *pix, sfTexture *tex, sfRenderWindow *win, sfSprite *spr);
void thickness(pix_t *pix, sfTexture *texture,sfVector2i mouse);
void plotline(sfVector2i mouse, sfVector2i mouse2, pix_t *pix, sfTexture *text);
mona_t *make_mona(void);
color_t **set_the_col(void);
void color_draw(color_t **color, sfRenderWindow *win);
void on_the_block(color_t **color, sfRenderWindow *win);
pix_t *click_on(color_t **color, sfRenderWindow *win, pix_t *pix);
void draw_bar(bar_t *bar, sfRenderWindow *window);
int buttons_actions(bar_t *bar, nav_bar_t *nav);
void init_all(init_t *init);
void event(init_t *init, mona_t *mona, color_t **col);
void draw_nav(nav_bar_t *nav, sfRenderWindow *win);
int change_buttons(bar_t *bar, nav_bar_t *nav, sfVector2i pos);
void color_is_pressed(color_t **color);
void is_pencil(pix_t *pix, sfTexture *tex, sfVector2i mou);
void is_pen(pix_t *pix, sfTexture *tex, sfVector2i mou);
pix_t *change_broche(pix_t *pix, bar_t *bar, sfRenderWindow *win);
void draw_but(button_t *but, sfRenderWindow *win);
int nav_actions(nav_bar_t *nav, sfRenderWindow *win);
int changes_states_click_nav_file(nav_bar_t *but, sfVector2i pos);
int edit_actions(bar_t *nav, sfRenderWindow *win);
int changes_states_click_edit_file(bar_t *but, sfVector2i pos);
void is_eraser(pix_t *pix, sfTexture *tex, sfVector2i mou);
void size_ofpen(pix_t *pix, sfTexture *tex, sfVector2i mou);
void size_draw(form_t**form, sfRenderWindow *win);
form_t **create_form(void);
void on_the_size(form_t **color, sfRenderWindow *win);
pix_t *click_on_size(form_t **color, sfRenderWindow *win, pix_t *pix);
void size_is_pressed(form_t **color);
void bar_nav_inter(nav_bar_t *bar, sfRenderWindow *win, mona_t *mona);
int changes_states_click(button_t *but, sfVector2i pos);
int file_actions1(nav_bar_t *nav, sfRenderWindow *win);
void rond(pix_t *pix, sfTexture *tex, sfVector2i mou);
void rond2(pix_t *pix, sfTexture *tex, sfVector2i mou);
void rond3(pix_t *pix, sfTexture *tex, sfVector2i mou);
typef_t **create_type(void);
void typef_draw(typef_t **color, sfRenderWindow *win);
void on_the_type(typef_t **color, sfRenderWindow *win);
pix_t *click_type(typef_t **color, sfRenderWindow *win, pix_t *pix);
void typef_is_pressed(typef_t **color);
void sizeof_rond(pix_t *pix, sfTexture *tex, sfVector2i mou);
pix_t *is_a_click(init_t *init, pix_t *pix, color_t **col);
void set_hover(init_t *init, color_t **col);
void event_mouse(button_t *but, window_t *win);
typef_t *create_one(void);
typef_t *create_two(void);
void draw_about(nav_bar_t *nav, sfRenderWindow *win);
void create_about(nav_bar_t *nav);
void bar_nav_in(nav_bar_t *bar, sfRenderWindow *win);
void create_help_help(nav_bar_t *nav);
void draw_help_help(nav_bar_t *nav, sfRenderWindow *win);
int file_actions2(nav_bar_t *nav, sfRenderWindow *win);
int changes_states_click_nav_help(nav_bar_t *but, sfVector2i pos);
void bar_nav_int(nav_bar_t *bar, sfRenderWindow *win);
