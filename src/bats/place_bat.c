/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to place all bats
*/

#include "../../includes/my_defender.h"

void drop_cannon(global *game, shop *my_shop)
{
    sfColor opacity_up = {255, 255, 255, 255};
    sfColor opacity_none = {255, 255, 255, 0};

    sfSprite_setColor(my_shop->s_cannon, opacity_up);
    sfSprite_setTexture(my_shop->s_cannon, my_shop->t_shop->t_cannon, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->boole->on_map == 0 && game->first->gold >= 75 && my_shop->\
    pos_cannon.x == game->map->pos_free.x && my_shop->pos_cannon.y == \
    game->map->pos_free.y) {
        get_last(game, my_shop->pos_cannon, 1);
        game->first->gold -= 75;
        sfSound_play(game->sounds->anvil);
        game->boole->unground = 1;
    }
    my_shop->pos_cannon.x = 0;
    my_shop->pos_cannon.y = 150;
    sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
    game->boole->take = 1;
}

void drop_archer(global *game, shop *my_shop)
{
    sfColor opacity_up = {255, 255, 255, 255};
    sfColor opacity_none = {255, 255, 255, 0};

    sfSprite_setColor(my_shop->s_archer, opacity_up);
    sfSprite_setTexture(my_shop->s_archer, my_shop->t_shop->t_archer, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->boole->on_map == 0 && game->first->gold >= 150 && my_shop->\
    pos_archer.x == game->map->pos_free.x && my_shop->pos_archer.y == \
    game->map->pos_free.y) {
        get_last(game, my_shop->pos_archer, 2);
        game->first->gold -= 150;
        sfSound_play(game->sounds->anvil);
        game->boole->unground = 1;
    }
    my_shop->pos_archer.x = 0;
    my_shop->pos_archer.y = 270;
    sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
    game->boole->take = 1;
}

void drop_mortar(global *game, shop *my_shop)
{
    sfColor opacity_up = {255, 255, 255, 255};
    sfColor opacity_none = {255, 255, 255, 0};

    sfSprite_setColor(my_shop->s_mortar, opacity_up);
    sfSprite_setTexture(my_shop->s_mortar, my_shop->t_shop->t_mortar, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->boole->on_map == 0 && game->first->gold >= 300 && my_shop->\
    pos_mortar.x == game->map->pos_free.x && my_shop->pos_mortar.y == \
    game->map->pos_free.y) {
        get_last(game, my_shop->pos_mortar, 3);
        game->first->gold -= 300;
        sfSound_play(game->sounds->anvil);
        game->boole->unground = 1;
    }
    my_shop->pos_mortar.x = 0;
    my_shop->pos_mortar.y = 390;
    sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
    game->boole->take = 1;
}
