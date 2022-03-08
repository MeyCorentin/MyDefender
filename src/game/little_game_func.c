/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain some little functions
*/

#include "../../includes/my_defender.h"

batiment *get_last(global *game, sfVector2f pos, int name)
{
    batiment *temp = game->first;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = add_bat(game, temp, pos, name);
    return (temp->next);
}

void check_hit(global *game, batiment *bat_)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfColor color = {0, 255, 0, 150};

    if (game->rad_god == 1) {
        if (sqrt((pos_mouse.x - bat_->pos.x - 70) * (pos_mouse.x - bat_->\
        pos.x - 70) + (pos_mouse.y - bat_->pos.y - 70) * (pos_mouse.y - bat_->\
        pos.y - 70)) < bat_->rad_size)
            sfCircleShape_setFillColor(bat_->radius, color);
        sfRenderWindow_drawCircleShape(game->window, bat_->radius, NULL);
    }
    if (bat_->next != NULL)
        check_hit(game, bat_->next);
}

void set_game(global *game)
{
    sfCircleShape *radius = sfCircleShape_create();

    game->first = create_hdv(game);
    game->boole->god = 1;
    game->map->map = sfSprite_create();
    set_texture_map(game);
    set_music(game);
    create_pause(game);
    game->boole->shop_is_open = 1;
    game->boole->take = 1;
    game->boole->pause_is_open = 1;
    game->boole->on_bat = 1;
    game->radius = radius;
    game->rad_god = 1;
}
