/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain some little functions
*/

#include "includes/my_defender.h"
#include <SFML/Graphics.h>
#include <stdio.h>
#include <math.h>

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

void draw_level(global *game, batiment *temp)
{
    for (int cmpt = 0; temp->temp[cmpt] != '\0'; cmpt += 1)
        temp->temp[cmpt] = '\0';
    temp->pos_level.x = temp->pos.x + 56;
    temp->pos_level.y = temp->pos.y + 90;
    sfText_setPosition(temp->level_str, temp->pos_level);
    sfText_setString(temp->level_str, new_put_nbr_str(temp->level, temp->temp));
    sfRenderWindow_drawText(game->window, temp->level_str, sfFalse);
    for (int cmpt = 0; temp->temp[cmpt] != '\0'; cmpt += 1)
        temp->temp[cmpt] = '\0';
}

void draw_rad(global *game, batiment * bat_)
{
    sfCircleShape *radius = sfCircleShape_create();
    sfVector2f radius_pos;
    sfColor opacity = {255, 255, 255, 100};
    int rad_size;

    radius_pos = bat_->pos;
    if (game->rad_god == 1)
    {
        if (bat_->type == 1)
        {
            sfCircleShape_setRadius(radius, 90);
            radius_pos.x -= 90 / 2 - 60 / 2 + 12;
            radius_pos.y -= 90 / 2 - 60 / 2 + 2;
            rad_size = 90;
        }
        if (bat_->type == 2)
        {
            sfCircleShape_setRadius(radius, 110);
            radius_pos.x -= 110 / 2 - 60 / 2 + 22;
            radius_pos.y -= 110 / 2 - 60 / 2 + 12;
            rad_size = 110;
        }
        if (bat_->type == 3)
        {
            sfCircleShape_setRadius(radius, 140);
            radius_pos.x -= 140 / 2 - 60 / 2 + 45;
            radius_pos.y -= 140 / 2 - 60 / 2 + 25;
            rad_size = 140;
        }
        if (bat_->type == 4)
        {
            sfCircleShape_setRadius(radius, 140);
            radius_pos.x -= 140 / 2 - 60 / 2 + 45;
            radius_pos.y -= 140 / 2 - 60 / 2 + 25;
            rad_size = 140;
        }
        if (bat_->type == 5)
        {
            sfCircleShape_setRadius(radius, 200);
            radius_pos.x -= 200 / 2 - 60 / 2 + 80;
            radius_pos.y -= 200 / 2 - 60 / 2 + 50;
            rad_size = 200;
        }
        if (bat_->type == 6)
        {
            sfCircleShape_setRadius(radius, 90);
            radius_pos.x -= 80 / 2 - 60 / 2 + 12;
            radius_pos.y -= 80 / 2 - 60 / 2 + 2;
            rad_size = 90;
        }
        bat_->rad_pos = radius_pos;
        bat_->rad_size = rad_size;
        bat_->radius = radius;
        sfCircleShape_setFillColor(bat_->radius, opacity);
        sfCircleShape_setPosition(radius, radius_pos);
        sfRenderWindow_drawCircleShape(game->window, bat_->radius, NULL);
    }
    if (bat_->next != NULL)
        draw_rad(game, bat_->next);
}

void check_hit(global *game, batiment * bat_)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (game->rad_god == 1)
    {
        if (pow(abs(pos_mouse.x -(bat_->rad_size / 2) -  bat_->pos.x), 2) + pow(abs(pos_mouse.y - (bat_->rad_size / 2) - bat_->pos.y), 2) < pow(bat_->rad_size, 2))                         // Test si cliqué.
            sfCircleShape_setFillColor(bat_->radius, sfRed);
        sfRenderWindow_drawCircleShape(game->window, bat_->radius, NULL);
    }
    if (bat_->next != NULL)
        check_hit(game, bat_->next);
}

void draw_structs(global *game, batiment *bat_)
{
    if (bat_->on_bat == 0) {
        bat_->level_up->pos_up.x = bat_->pos.x + 15;
        bat_->level_up->pos_up.y = bat_->pos.y + 97;
        sfSprite_setPosition(bat_->level_up->up, bat_->level_up->pos_up);
        sfRenderWindow_drawSprite(game->window, bat_->level_up->up, sfFalse);
        if (bat_->name != -1)
            sfRenderWindow_drawSprite(game->window, bat_->level_up->destroy, sfFalse);
        sfText_setString(bat_->level_up->cost, new_put_nbr_str(bat_->stats->price, bat_->temp));
        bat_->level_up->pos_cost.x = bat_->level_up->pos_up.x - 20;
        bat_->level_up->pos_cost.y = bat_->level_up->pos_up.y + 30;
        sfText_setPosition(bat_->level_up->cost, bat_->level_up->pos_cost);
        sfRenderWindow_drawText(game->window, bat_->level_up->cost, sfFalse);           
    }
    sfRenderWindow_drawSprite(game->window, bat_->bat, sfFalse);
    draw_level(game, bat_);
    if (bat_->next != NULL)
        draw_structs(game, bat_->next);
}

void draw_game(global *game, shop *my_shop, grid_cell grid_cell)
{
    sfRenderWindow_drawSprite(game->window, game->map, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->button, sfFalse);
    draw_ground(game, &grid_cell, my_shop);
    (game->god == 0) ? draw_cell(game, grid_cell.next_cell, my_shop) : 1;
    update_gold(game);
    draw_rad(game, game->first);
    sfRenderWindow_drawCircleShape(game->window , game->radius , sfFalse);
    place_struct(game, &grid_cell, my_shop);
    check_hit(game, game->first);
    draw_structs(game, game->first);
}

void set_game(global *game)
{
    sfTexture *t_map = sfTexture_createFromFile("pictures/maps/backgrounds/4.png", NULL);
    sfCircleShape *radius = sfCircleShape_create();

    game->first = create_hdv(game);
    game->god = 1;
    game->map = sfSprite_create();
    sfSprite_setTexture(game->map, t_map, sfFalse);
    set_music(game);
    create_pause(game);
    game->shop_is_open = 1;
    game->take = 1;
    game->pause_is_open = 1;
    game->on_bat = 1;
    game->radius = radius;
    game->rad_god = 1;
}
