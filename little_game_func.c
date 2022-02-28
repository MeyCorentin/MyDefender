/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain some little functions
*/

#include "includes/my_defender.h"

batiment *get_last(global *game, sfVector2f pos, int name)
{
    batiment *temp = game->first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = add_bat(game, temp, pos, name);
    return (temp->next);
}

void draw_structs(global *game)
{
    batiment *temp = game->first;
    sfCircleShape *radius = sfCircleShape_create();
    sfVector2f radius_pos;
    sfColor opacity = {255, 255, 255, 150};

    while (temp != NULL)
    {
        radius_pos = temp->pos;
        sfCircleShape_setFillColor(radius, opacity);
        if (game->rad_god == 1)
        {
            if (temp->type == 1)
            {
                sfCircleShape_setRadius(radius, 90);
                radius_pos.x -= 90 / 2 - 60 / 2 + 12;
                radius_pos.y -= 90 / 2 - 60 / 2 + 2;
            }
            if (temp->type == 2)
            {
                sfCircleShape_setRadius(radius, 110);
                radius_pos.x -= 110 / 2 - 60 / 2 + 22;
                radius_pos.y -= 110 / 2 - 60 / 2 + 12;
            }
            if (temp->type == 3)
            {
                sfCircleShape_setRadius(radius, 140);
                radius_pos.x -= 140 / 2 - 60 / 2 + 45;
                radius_pos.y -= 140 / 2 - 60 / 2 + 25;
            }
            if (temp->type == 4)
            {
                sfCircleShape_setRadius(radius, 140);
                radius_pos.x -= 140 / 2 - 60 / 2 + 45;
                radius_pos.y -= 140 / 2 - 60 / 2 + 25;
            }
            if (temp->type == 5)
            {
                sfCircleShape_setRadius(radius, 200);
                radius_pos.x -= 200 / 2 - 60 / 2 + 80;
                radius_pos.y -= 200 / 2 - 60 / 2 + 50;
            }
            if (temp->type == 6)
            {
                sfCircleShape_setRadius(radius, 90);
                radius_pos.x -= 80 / 2 - 60 / 2 + 12;
                radius_pos.y -= 80 / 2 - 60 / 2 + 2;
            }
            sfCircleShape_setPosition(radius, radius_pos);
            sfRenderWindow_drawCircleShape(game->window, radius, NULL);
        }
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
