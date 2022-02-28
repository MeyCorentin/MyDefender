/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain some little functions
*/

#include "includes/my_defender.h"

batiment *get_last(global *game, sfVector2f pos)
{
    batiment *temp = game->first;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = add_bat(game, temp, pos);
    return (temp->next);
}

void draw_structs(global *game)
{
    batiment *temp = game->first;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(game->window, temp->bat, sfFalse);
        temp = temp->next;
    }
}

void draw_game(global *game, shop *my_shop)
{
    sfRenderWindow_drawSprite(game->window, game->map, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->button, sfFalse);
}

void set_game(global *game)
{
    sfTexture *t_map = sfTexture_createFromFile("pictures/maps/backgrounds/4.png", NULL);

    game->first = create_hdv(game);
    game->god = 1;
    game->map = sfSprite_create();
    sfSprite_setTexture(game->map, t_map, sfFalse);
    set_music(game);
    create_pause(game);
    game->shop_is_open = 1;
    game->take = 1;
    game->pause_is_open = 1;
}
