/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to check event in game
*/

#include "includes/my_defender.h"

void drop_cannon(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_cannon, opacity_up);
    sfSprite_setTexture(my_shop->s_cannon,my_shop->t_cannon, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->on_map == 0)
        get_last(game, my_shop->pos_cannon);
    my_shop->pos_cannon.x = 0;
    my_shop->pos_cannon.y = 150;
    sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
    game->take = 1;
    sfSound_play(game->sounds->anvil);
}

void shop_event(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_cannon.x && pos_mouse.x <= \
my_shop->pos_cannon.x + 120 && pos_mouse.y >= my_shop->pos_cannon.y && \
pos_mouse.y <= my_shop->pos_cannon.y + 100 && \
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        ////////////////////////////////////////////////////////////////////////
        rad_pos.x = pos_mouse.x - 90;
        rad_pos.y = pos_mouse.y - 90;
        sfCircleShape_setPosition(game->radius , rad_pos);
        sfCircleShape_setFillColor(game->radius, opacity_down);
        sfCircleShape_setRadius(game->radius , 90);
        ////////////////////////////////////////////////////////////////////////
        game->on_map = 1;
        game->texture = "pictures/defences/cannon/1.png";
        my_shop->cannon = sfTexture_createFromFile(game->texture, sfFalse);
        sfSprite_setTexture(my_shop->s_cannon, my_shop->cannon, sfFalse);
        sfSprite_setColor(my_shop->s_cannon, opacity_down);
        my_shop->pos_cannon.x = pos_mouse.x - 60;
        my_shop->pos_cannon.y = pos_mouse.y - 60;
        sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
        game->take = 0;
    }
    if (game->event.type == sfEvtMouseButtonReleased && game->take == 0)
        drop_cannon(game, my_shop);
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
