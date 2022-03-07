/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain event pause functions
*/

#include "../../includes/my_defender.h"

void event_res(global *game, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= game->pause->p_pause->pos_res.x && pos_mouse.x <= game->\
    pause->p_pause->pos_res.x + 240 && pos_mouse.y >= game->pause->p_pause->\
    pos_res.y && pos_mouse.y <= game->pause->p_pause->pos_res.y + 120) {
        sfText_setColor(game->pause->c_restart, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->sounds->click);
            start_game(game);
        }
    } else
        sfText_setColor(game->pause->c_restart, sfBlack);
}

void event_quit(global *game, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= game->pause->p_pause->pos_quit.x && pos_mouse.x <= \
    game->pause->p_pause->pos_quit.x + 240 && pos_mouse.y >= game->pause->\
    p_pause->pos_quit.y && pos_mouse.y <= game->pause->p_pause->pos_quit.y + \
    120) {
        sfText_setColor(game->pause->c_quit, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->sounds->click);
            game->secs = 4;
            set_menu(game);
        }
    } else
        sfText_setColor(game->pause->c_quit, sfBlack);
}

void event_con(global *game, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= game->pause->p_pause->pos_con.x && pos_mouse.x <= game->\
    pause->p_pause->pos_con.x + 240 && pos_mouse.y >= game->pause->p_pause->\
    pos_con.y && pos_mouse.y <= game->pause->p_pause->pos_con.y + 120) {
        sfText_setColor(game->pause->c_continu, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->sounds->click);
            game->boole->pause_is_open = 1;
        }
    } else
        sfText_setColor(game->pause->c_continu, sfBlack);
}

void check_button_event(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyC)) {
        game->boole->pause_is_open = 1;
        sfSound_play(game->sounds->click);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR)) {
        sfSound_play(game->sounds->click);
        start_game(game);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        game->secs = 4;
        sfSound_play(game->sounds->click);
        set_menu(game);
    }
}

void check_pause_event(global *game)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *) game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->boole->pause_is_open == 0 && sfKeyboard_isKeyPressed\
        (sfKeyEscape) && game->secs != 3) {
            sfSound_play(game->sounds->click);
            sfSound_play(game->sounds->ambiance);
            game->boole->pause_is_open = 1;
            game->secs = 3;
        }
        check_button_event(game);
        check_sounds_pause(game, mouse);
        check_music_pause(game, mouse);
        event_con(game, mouse);
        event_res(game, mouse);
        event_quit(game, mouse);
    }
}