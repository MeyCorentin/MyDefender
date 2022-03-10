/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/my_defender.h"

void update_htp(global *game)
{
    if (game->how_to_play->page == 1)
        game->how_to_play->t_htp = sfTexture_createFromFile\
        ("pictures/htp/menu_defender.png", NULL);
    if (game->how_to_play->page == 2)
        game->how_to_play->t_htp = sfTexture_createFromFile\
        ("pictures/htp/game_defender.png", NULL);
    if (game->how_to_play->page == 3)
        game->how_to_play->t_htp = sfTexture_createFromFile\
        ("pictures/htp/shop_defender.png", NULL);
    if (game->how_to_play->page == 4)
        game->how_to_play->t_htp = sfTexture_createFromFile\
        ("pictures/htp/reach_defender.png", NULL);
    if (game->how_to_play->page == 5)
        game->how_to_play->t_htp = sfTexture_createFromFile\
        ("pictures/htp/map_defender.png", NULL);
    if (game->how_to_play->page == 6)
        game->how_to_play->t_htp = sfTexture_createFromFile\
        ("pictures/htp/pause_defender.png", NULL);
    sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
    t_htp, sfFalse);
}

void create_htp(global *game)
{
    game->how_to_play = malloc(sizeof(how_to_play_t));
    game->how_to_play->page = 1;
    game->how_to_play->htp = sfSprite_create();
    game->how_to_play->position.x = 300;
    game->how_to_play->position.y = 150;
    game->how_to_play->scale.x = 0.7;
    game->how_to_play->scale.y = 0.7;
    sfSprite_setScale(game->how_to_play->htp, game->how_to_play->scale);
    sfSprite_setPosition(game->how_to_play->htp, game->how_to_play->position);
}

void change_page(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && game->boole->on_htp == 0 && \
    game->secs > 30) {
        if (game->how_to_play->page > 1)
            game->how_to_play->page -= 1;
        else
            game->how_to_play->page = 6;
        game->secs = 0;
        sfClock_restart(game->clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && game->boole->on_htp == 0 && \
    game->secs > 30) {
        if (game->how_to_play->page < 6)
            game->how_to_play->page += 1;
        else
            game->how_to_play->page = 1;
        game->secs = 0;
        sfClock_restart(game->clock);
    }
}

void test_htp(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && game->boole->on_htp == 1) {
        sfSound_play(game->sounds->click);
        game->boole->on_htp = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->boole->on_htp == 0) {
        sfSound_play(game->sounds->click);
        game->boole->on_htp = 1;
        game->how_to_play->page = 1;
    }
    change_page(game);
}
