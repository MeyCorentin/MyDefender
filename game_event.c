/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to check event in game
*/

#include "includes/my_defender.h"

void shop_event(global *game, shop *my_shop)
{
    get_cannon(game, my_shop);
    get_archer(game, my_shop);
    get_mortar(game, my_shop);
    get_air_defence(game, my_shop);
    get_xbow(game, my_shop);
    get_wizard(game, my_shop);
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 0)
        drop_cannon(game, my_shop);
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 2)
        drop_archer(game, my_shop);
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 3)
        drop_mortar(game, my_shop);
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 4)
        drop_air_defence(game, my_shop);
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 5)
        drop_xbow(game, my_shop);
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 6)
        drop_wizard(game, my_shop);
}

void click_shop(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfVector2f pos_button = sfSprite_getPosition(my_shop->button);

    if (pos_mouse.x > pos_button.x && pos_mouse.x < pos_button.x + 50 && \
pos_mouse.y > pos_button.y && pos_mouse.y < pos_button.y + 150 && \
        game->event.type == sfEvtMouseButtonReleased) {
        if (game->shop_is_open == 1 && game->secs != 1) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(my_shop->button, my_shop->open, sfFalse);
            game->shop_is_open = 0;
            sfSprite_setPosition(my_shop->button, my_shop->pos_button_open);
            game->secs = 1;
        } else if (game->shop_is_open == 0 && game->secs != 1) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(my_shop->button, my_shop->close, sfFalse);
            game->shop_is_open = 1;
            sfSprite_setPosition(my_shop->button, my_shop->pos_button_close);
            game->secs = 1;
        }
    }
}

void check_shop(global *game, shop *my_shop)
{
    if (game->shop_is_open == 0)
        shop_event(game, my_shop);
    if (game->god == 1 && sfKeyboard_isKeyPressed(sfKeyO) && game->secs != 0) {
        game->god = 0;
        game->secs = 0;
    }
    if (game->god == 0 && sfKeyboard_isKeyPressed(sfKeyO) && game->secs != 0) {
        game->god = 1;
        game->secs = 0;
    }
    if (game->rad_god == 1 && sfKeyboard_isKeyPressed(sfKeyP) && game->secs != 0) {
        game->rad_god  = 0;
        game->secs = 0;
    }
    if (game->rad_god  == 0 && sfKeyboard_isKeyPressed(sfKeyP) && game->secs != 0) {
        game->rad_god  = 1;
        game->secs = 0;
    }
    click_shop(game, my_shop);
    if (game->pause_is_open == 1 && sfKeyboard_isKeyPressed(sfKeyEscape) && \
        game->secs != 3) {
        sfSound_play(game->sounds->click);
        sfSound_pause(game->sounds->ambiance);
        game->pause_is_open = 0;
        game->secs = 3;
        in_pause(game);
    }
}
