/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to check action of bats
*/

#include "includes/my_defender.h"

void destroy_struct(global *game, batiment *bat)
{
    batiment *temp = malloc(sizeof(batiment));
    batiment *prev = malloc(sizeof(batiment));

    temp = bat;
    prev = bat->prev;
    prev->next = temp->next;
    game->first->gold += bat->stats->price / 2;
    free(temp);
}

void up_struct(global *game, batiment *bat)
{
    sfSound_play(game->sounds->anvil);
    bat->level += 1;
    game->first->gold -= bat->stats->price;
    bat->stats->damage *= 1.5;
    bat->stats->price *= 1.5;
    bat->stats->pv *= 1.5;
}