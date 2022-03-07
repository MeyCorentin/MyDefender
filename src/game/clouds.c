/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create clouds
*/

#include "../../includes/my_defender.h"

void update_hdv(global *game, batiment *bat)
{
    game->price_hdv = bat->stats->price;
    game->gold = bat->gold;
    game->level += 1;
    //game->menus->level += 1;
    set_texture_hdv(game, bat);
    set_texture_map(game);
}

void create_transition(global *game)
{
    sfColor opacity = {255, 255, 255, 0};

    game->transition = malloc(sizeof(transition_t));
    game->transition->clouds = sfSprite_create();
    game->transition->clouds2 = sfSprite_create();
    game->transition->t_clouds = sfTexture_createFromFile\
    ("pictures/maps/clouds.jpg", NULL);
    sfSprite_setTexture(game->transition->clouds, game->transition->t_clouds, \
    sfFalse);
    sfSprite_setTexture(game->transition->clouds2, \
    game->transition->t_clouds, sfFalse);
    game->transition->opacity = opacity;
    sfSprite_setColor(game->transition->clouds, game->transition->opacity);
    sfSprite_setColor(game->transition->clouds2, game->transition->opacity);
    game->transition->pos_clouds.x = -1920;
    game->transition->pos_clouds.y = 1080;
    game->transition->pos_clouds2.x = 1920;
    game->transition->pos_clouds2.y = -1080;
}

void dissip_clouds(global *game, batiment *bat, grid_cell grid_cell_)
{
    update_hdv(game, bat);
    while (game->secs < 300) {
        draw_game(game, game->shop, grid_cell_);
        sfRenderWindow_drawSprite(game->window, game->transition->clouds, \
        sfFalse);
        sfRenderWindow_drawSprite(game->window, game->transition->clouds2, \
        sfFalse);
        sfRenderWindow_display(game->window);
        update_game(game);
        if (game->transition->opacity.a - 3 >= 0) {
            game->transition->opacity.a -= 3;
            sfSprite_setColor(game->transition->clouds, \
            game->transition->opacity);
            sfSprite_setColor(game->transition->clouds2, game->transition->\
            opacity);
        }
    }
}

void check_time(global *game, batiment *bat, grid_cell grid_cell_)
{
    game->secs = 0;
    sfClock_restart(game->clock);
    while (game->secs < 150) {
        draw_game(game, game->shop, grid_cell_);
        sfRenderWindow_drawSprite(game->window, game->transition->clouds, \
        sfFalse);
        sfRenderWindow_drawSprite(game->window, game->transition->clouds2, \
        sfFalse);
        sfRenderWindow_display(game->window);
        update_game(game);
        if (game->transition->opacity.a + 3 <= 255) {
            game->transition->opacity.a += 3;
            sfSprite_setColor(game->transition->clouds, \
            game->transition->opacity);
            sfSprite_setColor(game->transition->clouds2, game->transition->\
            opacity);
        }
    }
    dissip_clouds(game, bat, grid_cell_);
}