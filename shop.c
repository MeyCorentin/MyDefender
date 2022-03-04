/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions for my shop
*/

#include "includes/my_defender.h"

void open_shop(global *game, shop *my_shop)
{
    sfRenderWindow_drawSprite(game->window, my_shop->s_cannon, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->s_archer, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->s_mortar, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->s_air_defence, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->s_xbow, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->s_wizard, sfFalse);
}

void create_defences(shop *my_shop)
{
    my_shop->s_cannon =	sfSprite_create();
    my_shop->t_cannon =	sfTexture_createFromFile("pictures/defences/cannon/\
cannon_lvl1.png", NULL);
    my_shop->s_archer =	sfSprite_create();
    my_shop->t_archer =	sfTexture_createFromFile("pictures/defences/\
archer_tower/archer_tower_lvl1.png", NULL);
    my_shop->s_mortar =	sfSprite_create();
    my_shop->t_mortar =	sfTexture_createFromFile("pictures/defences/mortar/\
mortar_lvl1.png", NULL);
    my_shop->s_air_defence = sfSprite_create();
    my_shop->t_air_defence = sfTexture_createFromFile("pictures/defences/\
air_defence/air_defence_lvl1.png", NULL);
    my_shop->s_xbow = sfSprite_create();
    my_shop->t_xbow = sfTexture_createFromFile("pictures/defences/x_bow/\
x_bow_lvl1.png", NULL);
    my_shop->s_wizard =	sfSprite_create();
    my_shop->t_wizard =	sfTexture_createFromFile("pictures/defences/\
wizard_tower/wizard_tower_lvl1.png", NULL);
}

void set_positions(shop *my_shop)
{
    my_shop->pos_cannon.x = 0;
    my_shop->pos_cannon.y = 150;
    my_shop->pos_archer.x = 0;
    my_shop->pos_archer.y = 270;
    my_shop->pos_mortar.x = 0;
    my_shop->pos_mortar.y = 390;
    my_shop->pos_air_defence.x = 0;
    my_shop->pos_air_defence.y = 510;
    my_shop->pos_xbow.x = 0;
    my_shop->pos_xbow.y = 630;
    my_shop->pos_wizard.x = 0;
    my_shop->pos_wizard.y = 750;
    my_shop->snap = 0;
    sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
    sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
    sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
    sfSprite_setPosition(my_shop->s_air_defence, my_shop->pos_air_defence);
    sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
    sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
}

void set_pos_stat_shop(shop *my_shop)
{
    my_shop->stats->pos_cannon.x = my_shop->pos_cannon.x + 120;
    my_shop->stats->pos_cannon.y = my_shop->pos_cannon.y;
    my_shop->stats->pos_archer.x = my_shop->pos_archer.x + 120;
    my_shop->stats->pos_archer.y = my_shop->pos_archer.y;
    my_shop->stats->pos_mortar.x = my_shop->pos_mortar.x + 120;
    my_shop->stats->pos_mortar.y = my_shop->pos_mortar.y;
    my_shop->stats->pos_air.x = my_shop->pos_air_defence.x + 120;
    my_shop->stats->pos_air.y = my_shop->pos_air_defence.y;
    my_shop->stats->pos_xbow.x = my_shop->pos_xbow.x + 120;
    my_shop->stats->pos_xbow.y = my_shop->pos_xbow.y;
    my_shop->stats->pos_wizard.x = my_shop->pos_wizard.x + 120;
    my_shop->stats->pos_wizard.y = my_shop->pos_wizard.y;
    sfSprite_setPosition(my_shop->stats->cannon, my_shop->stats->pos_cannon);
    sfSprite_setPosition(my_shop->stats->archer, my_shop->stats->pos_archer);
    sfSprite_setPosition(my_shop->stats->mortar, my_shop->stats->pos_mortar);
    sfSprite_setPosition(my_shop->stats->air, my_shop->stats->pos_air);
    sfSprite_setPosition(my_shop->stats->xbow, my_shop->stats->pos_xbow);
    sfSprite_setPosition(my_shop->stats->wizard, my_shop->stats->pos_wizard);
}

void set_is_stats(shop *my_shop)
{
    my_shop->stats->mouse->is_cannon = 1;
    my_shop->stats->mouse->is_archer = 1;
    my_shop->stats->mouse->is_mortar = 1;
    my_shop->stats->mouse->is_air = 1;
    my_shop->stats->mouse->is_xbow = 1;
    my_shop->stats->mouse->is_wizard = 1;
}

void create_stat_shop(shop *my_shop)
{
    my_shop->stats = malloc(sizeof(stat_shop));
    my_shop->stats->mouse = malloc(sizeof(mouse_t));
    my_shop->stats->cannon = sfSprite_create();
    my_shop->stats->archer = sfSprite_create();
    my_shop->stats->mortar = sfSprite_create();
    my_shop->stats->air = sfSprite_create();
    my_shop->stats->xbow = sfSprite_create();
    my_shop->stats->wizard = sfSprite_create();
    my_shop->stats->t_cannon = sfTexture_createFromFile("pictures/shop/stats/cannon.png", NULL);
    my_shop->stats->t_archer = sfTexture_createFromFile("pictures/shop/stats/archer.png", NULL);
    my_shop->stats->t_mortar = sfTexture_createFromFile("pictures/shop/stats/mortar.png", NULL);
    my_shop->stats->t_air = sfTexture_createFromFile("pictures/shop/stats/air.png", NULL);
    my_shop->stats->t_xbow = sfTexture_createFromFile("pictures/shop/stats/xbow.png", NULL);
    my_shop->stats->t_wizard = sfTexture_createFromFile("pictures/shop/stats/wizard.png", NULL);
    sfSprite_setTexture(my_shop->stats->cannon, my_shop->stats->t_cannon, sfFalse);
    sfSprite_setTexture(my_shop->stats->archer, my_shop->stats->t_archer, sfFalse);
    sfSprite_setTexture(my_shop->stats->mortar, my_shop->stats->t_mortar, sfFalse);
    sfSprite_setTexture(my_shop->stats->air, my_shop->stats->t_air, sfFalse);
    sfSprite_setTexture(my_shop->stats->xbow, my_shop->stats->t_xbow, sfFalse);
    sfSprite_setTexture(my_shop->stats->wizard, my_shop->stats->t_wizard, sfFalse);
    set_pos_stat_shop(my_shop);
    set_is_stats(my_shop);
}

shop *create_shop(void)
{
    shop *my_shop = malloc(sizeof(shop) * 10);

    my_shop->pos_button_close.x = 0;
    my_shop->pos_button_close.y = 430;
    my_shop->pos_button_open.x = 120;
    my_shop->pos_button_open.y = 430;
    my_shop->button = sfSprite_create();
    create_defences(my_shop);
    my_shop->open = sfTexture_createFromFile("pictures/buttons/shop_open.png", NULL);
    my_shop->close = sfTexture_createFromFile("pictures/buttons/shop_close.png", NULL);
    sfSprite_setTexture(my_shop->button, my_shop->close, sfFalse);
    sfSprite_setTexture(my_shop->s_cannon, my_shop->t_cannon, sfFalse);
    sfSprite_setTexture(my_shop->s_archer, my_shop->t_archer, sfFalse);
    sfSprite_setTexture(my_shop->s_mortar, my_shop->t_mortar, sfFalse);
    sfSprite_setTexture(my_shop->s_air_defence, my_shop->t_air_defence, sfFalse);
    sfSprite_setTexture(my_shop->s_xbow, my_shop->t_xbow, sfFalse);
    sfSprite_setTexture(my_shop->s_wizard, my_shop->t_wizard, sfFalse);
    sfSprite_setPosition(my_shop->button, my_shop->pos_button_close);
    set_positions(my_shop);
    create_stat_shop(my_shop);
    return (my_shop);
}
