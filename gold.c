/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create gold
*/

#include "includes/my_defender.h"

void create_gold(global *game)
{
    sfFont *font = sfFont_createFromFile("pictures/supercell.x-font-ttf");

    game->gold_gestion = malloc(sizeof(gold));
    game->gold_gestion->money = sfText_create();
    game->gold_gestion->number = sfText_create();
    game->gold_gestion->pos_money.x = 1600;
    game->gold_gestion->pos_money.y = 0;
    game->gold_gestion->pos_number.x = 1710;
    game->gold_gestion->pos_number.y = 0;
    sfText_setPosition(game->gold_gestion->money, game->gold_gestion->pos_money);
    sfText_setFont(game->gold_gestion->money, font);
    sfText_setPosition(game->gold_gestion->number, game->gold_gestion->pos_number);
    sfText_setFont(game->gold_gestion->number, font);
    game->gold_gestion->temp = malloc(sizeof(char *));
}

void update_gold(global *game)
{
    int cmpt = 0;

    for (; game->gold_gestion->temp[cmpt] != '\0'; cmpt += 1)
        game->gold_gestion->temp[cmpt] = '\0';
    sfText_setString(game->gold_gestion->money,	"Gold : ");
    sfText_setString(game->gold_gestion->number, new_put_nbr_str(game->first->gold, game->gold_gestion->temp));
    sfRenderWindow_drawText(game->window, game->gold_gestion->money, sfFalse);
    sfRenderWindow_drawText(game->window, game->gold_gestion->number, sfFalse);
}
