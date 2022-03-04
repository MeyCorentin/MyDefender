/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to place all bats
*/

#include "includes/my_defender.h"

void drop_cannon(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_cannon, opacity_up);
    sfSprite_setTexture(my_shop->s_cannon,my_shop->t_cannon, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->on_map == 0 && game->first->gold >= 75 && my_shop->pos_cannon.x == game->pos_free.x && my_shop->pos_cannon.y == game->pos_free.y) {
        get_last(game, my_shop->pos_cannon, 1);
        game->first->gold -= 75;
        sfSound_play(game->sounds->anvil);
    }
    my_shop->pos_cannon.x = 0;
    my_shop->pos_cannon.y = 150;
    sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
    game->take = 1;
}

void drop_archer(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_archer, opacity_up);
    sfSprite_setTexture(my_shop->s_archer,my_shop->t_archer, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->on_map == 0 && game->first->gold >= 150 && my_shop->pos_archer.x == game->pos_free.x && my_shop->pos_archer.y == game->pos_free.y) {
	get_last(game, my_shop->pos_archer, 2);
	game->first->gold -= 150;
	sfSound_play(game->sounds->anvil);
    }
    my_shop->pos_archer.x = 0;
    my_shop->pos_archer.y = 270;
    sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
    game->take = 1;
}

void drop_mortar(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_mortar, opacity_up);
    sfSprite_setTexture(my_shop->s_mortar,my_shop->t_mortar, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->on_map == 0 && game->first->gold >= 300 && my_shop->pos_mortar.x == game->pos_free.x && my_shop->pos_mortar.y == game->pos_free.y) {
	get_last(game, my_shop->pos_mortar, 3);
	game->first->gold -= 300;
	sfSound_play(game->sounds->anvil);
    }
    my_shop->pos_mortar.x = 0;
    my_shop->pos_mortar.y = 390;
    sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
    game->take = 1;
}

void drop_air_defence(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_air_defence, opacity_up);
    sfSprite_setTexture(my_shop->s_air_defence,my_shop->t_air_defence, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->on_map == 0 && game->first->gold >= 1300 && my_shop->pos_air_defence.x == game->pos_f\
ree.x && my_shop->pos_air_defence.y == game->pos_free.y) {
	get_last(game, my_shop->pos_air_defence, 4);
	game->first->gold -= 1300;
	sfSound_play(game->sounds->anvil);
    }
    my_shop->pos_air_defence.x = 0;
    my_shop->pos_air_defence.y = 510;
    sfSprite_setPosition(my_shop->s_air_defence, my_shop->pos_air_defence);
    game->take = 1;
}

void drop_xbow(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_xbow, opacity_up);
    sfSprite_setTexture(my_shop->s_xbow,my_shop->t_xbow, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    sfCircleShape_setRadius(game->radius , 200);
    if (game->on_map == 0 && game->first->gold >= 7000 && my_shop->pos_xbow.x == game->pos_f\
ree.x && my_shop->pos_xbow.y == game->pos_free.y) {
	get_last(game, my_shop->pos_xbow, 5);
	game->first->gold -= 7000;
	sfSound_play(game->sounds->anvil);
    }
    my_shop->pos_xbow.x = 0;
    my_shop->pos_xbow.y = 630;
    sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
    game->take = 1;
}

void drop_wizard(global *game, shop *my_shop)
{
    sfColor opacity_up = {255 ,255, 255, 255};
    sfColor opacity_none = {255 ,255, 255, 0};

    sfSprite_setColor(my_shop->s_wizard, opacity_up);
    sfSprite_setTexture(my_shop->s_wizard,my_shop->t_wizard, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    sfCircleShape_setRadius(game->radius , 90);
    if (game->on_map == 0 && game->first->gold >= 3000 && my_shop->pos_wizard.x == game->pos_f\
ree.x && my_shop->pos_wizard.y == game->pos_free.y) {
	get_last(game, my_shop->pos_wizard, 6);
	game->first->gold -= 3000;
	sfSound_play(game->sounds->anvil);
    }
    my_shop->pos_wizard.x = 0;
    my_shop->pos_wizard.y = 750;
    sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
    game->take = 1;
}
