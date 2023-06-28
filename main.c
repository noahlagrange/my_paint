/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** ////////////////////////////
*/

#include "include/struct.h"

void event(init_t *init, mona_t *mona, color_t **col)
{
    sfRenderWindow_clear(init->win->win, sfBlack);
    draw_back(init->back, init->win->win);
    pos_but(init->bar);
    pos_nav(init->nav);
    typef_is_pressed(init->typef);
    draw_nav(init->nav, init->win->win);
    buttons_actions(init->bar, init->nav);
    file_actions1(init->nav, init->win->win);
    file_actions2(init->nav, init->win->win);
    edit_actions(init->bar, init->win->win);
    sfRenderWindow_drawSprite(init->win->win, mona->sprite, NULL);
    color_draw(col, init->win->win);
    size_draw(init->form, init->win->win);
    typef_draw(init->typef, init->win->win);
    sfRenderWindow_display(init->win->win);
    sfRenderWindow_setFramerateLimit(init->win->win, 60);
}

void close_evt(window_t *win, sfEvent event, button_t *but, nav_bar_t *nav)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(win->win);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (but->clc == sfTrue) {
            nav->file->click = !nav->file->click;
        }
    }
}

void event_mouse(button_t *but, window_t *win)
{
    but->mouse_pos = sfMouse_getPositionRenderWindow(win->win);
}

void game_loop(init_t *init, pix_t *pix, mona_t *mona, color_t **col)
{
    while (sfRenderWindow_pollEvent(init->win->win, &init->ev))
        close_evt(init->win, init->ev, init->but, init->nav);
    draw_thing(pix, mona->texture, init->win->win, mona->sprite);
    event(init, mona, col);
    on_the_block(col, init->win->win);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pix = is_a_click(init, pix, col);
        changes_states_click_nav_file(init->nav, init->but->mouse_pos);
        changes_states_click_nav_help(init->nav, init->but->mouse_pos);
        changes_states_click_edit_file(init->bar, init->but->mouse_pos);
    }
    set_hover(init, col);
    bar_nav_inter(init->nav, init->win->win, mona);
    bar_nav_in(init->nav, init->win->win);
    bar_nav_int(init->nav, init->win->win);
    pix = change_broche(pix, init->bar, init->win->win);
    buttons_actions(init->bar, init->nav);
}

int main(int ac, char **av)
{
    (void)av;
    init_t *init = malloc(sizeof(init_t));
    init_all(init);
    if (ac > 1)
        return 84;
    create_win(init->win);
    create_background(init->back);
    create_buttons_all(init->bar);
    create_nav(init->nav);
    create_about(init->nav);
    create_help_help(init->nav);
    init->form = create_form();
    init->typef = create_type();
    pix_t * pix = make_framebuff();
    mona_t *mona = make_mona();
    color_t **color = set_the_col();
    win_loop(init, pix, mona, color);
    sfRenderWindow_destroy(init->win->win);
    return 0;
}
