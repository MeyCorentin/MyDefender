/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create my clock
*/

#include "../../includes/my_defender.h"

void set_music(global *game)
{
    sfSound_setLoop(game->sounds->ambiance, sfTrue);
    sfSound_play(game->sounds->ambiance);
}

void update_game(global *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->secs = game->time.microseconds / 5000.0;
}

void update_enemy(global * game)
{
    if (game->secs > 6) {
        moov_enemy(game, game->enemy);
        sfClock_restart(game->clock);
    }
}