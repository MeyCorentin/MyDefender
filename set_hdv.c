/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create hdv
*/

#include "includes/my_defender.h"

void add_bat_buttons(global *game, batiment *new_bat)
{
    sfVector2f scale_cross = {0.05, 0.05};
    sfVector2f scale_up = {0.06, 0.06};
    sfFont *font = sfFont_createFromFile("pictures/ArialCE.ttf");

    new_bat->level_up = malloc(sizeof(level_up));
    new_bat->level_up->up = sfSprite_create();
    new_bat->level_up->destroy = sfSprite_create();
    new_bat->level_up->cost = sfText_create();
    sfText_setFont(new_bat->level_up->cost, font);
    sfText_setColor(new_bat->level_up->cost, sfGreen);
    new_bat->level_up->t_up = sfTexture_createFromFile("pictures/buttons/arrow.png", NULL);
    new_bat->level_up->t_destroy = sfTexture_createFromFile("pictures/buttons/cross.png", NULL);
    sfSprite_setTexture(new_bat->level_up->up, new_bat->level_up->t_up, sfFalse);
    sfSprite_setTexture(new_bat->level_up->destroy, new_bat->level_up->t_destroy, sfFalse);
    new_bat->level_up->pos_destroy.x = new_bat->pos.x + 90;
    new_bat->level_up->pos_destroy.y = new_bat->pos.y + 100;
    sfSprite_setPosition(new_bat->level_up->up, new_bat->level_up->pos_up);
    sfSprite_setPosition(new_bat->level_up->destroy, new_bat->level_up->pos_destroy);
    sfSprite_setScale(new_bat->level_up->up, scale_up);
    sfSprite_setScale(new_bat->level_up->destroy, scale_cross);
}

batiment *add_bat(global *game, batiment *prev, sfVector2f pos, int name)
{
    batiment *new_bat = malloc(sizeof(batiment));
    sfFont *font = sfFont_createFromFile("pictures/ArialCE.ttf");

    new_bat->first = game->first;
    new_bat->temp = malloc(sizeof(char) * 3);
    new_bat->prev = prev;
    new_bat->next = NULL;
    new_bat->last = NULL;
    new_bat->level = 1;
    new_bat->on_bat = 1;
    new_bat->level_str = sfText_create();
    sfText_setFont(new_bat->level_str, font);
    new_bat->type = name;
    new_bat->bat = sfSprite_create();
    new_bat->t_bat = sfTexture_createFromFile(game->texture, NULL);
    sfSprite_setTexture(new_bat->bat, new_bat->t_bat, sfFalse);
    new_bat->pos.x = pos.x;
    new_bat->pos.y = pos.y;
    sfSprite_setPosition(new_bat->bat, new_bat->pos);
    sfText_setColor(new_bat->level_str, sfBlue);
    add_bat_buttons(game, new_bat);
    check_name(game, name, new_bat);
    return (new_bat);
}

void set_texture_hdv(global *game, batiment *hdv)
{
    if (game->level == 1)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/1.png", NULL);
    if (game->level == 2)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/2.png", NULL);
    if (game->level == 3)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/3.png", NULL);
    if (game->level == 4)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/4.png", NULL);
    if (game->level == 5)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/5.png", NULL);
    if (game->level == 6)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/6.png", NULL);
    if (game->level == 7)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/7.png", NULL);
    if (game->level == 8)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/8.png", NULL);
    if (game->level == 9)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/9.png", NULL);
    if (game->level == 10)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/10.png", NULL);
}

batiment *create_hdv(global *game)
{
    batiment *hdv = malloc(sizeof(batiment));
    sfFont *font = sfFont_createFromFile("pictures/ArialCE.ttf");
    sfVector2f scale = {0.06, 0.06};

    hdv->level_up = malloc(sizeof(level_up));
    hdv->level_up->cost = sfText_create();
    hdv->temp = malloc(sizeof(char *));
    set_stats_hdv(game, hdv);
    sfText_setFont(hdv->level_up->cost, font);
    sfText_setString(hdv->level_up->cost, new_put_nbr_str(hdv->stats->price, hdv->temp));
    sfText_setColor(hdv->level_up->cost, sfGreen);
    hdv->level_up->up = sfSprite_create();
    hdv->level_up->t_up = sfTexture_createFromFile("pictures/buttons/arrow.png", NULL);
    hdv->level_up->pos_destroy.x = 0;
    hdv->level_up->pos_destroy.y = 0;
    sfSprite_setTexture(hdv->level_up->up, hdv->level_up->t_up, sfFalse);
    sfSprite_setScale(hdv->level_up->up, scale);
    hdv->first = hdv;
    hdv->next = NULL;
    hdv->last = NULL;
    hdv->level = game->level;
    hdv->gold = 100000;
    hdv->bat = sfSprite_create();
    hdv->temp = malloc(sizeof(char *));
    hdv->level_str = sfText_create();
    hdv->on_bat = 1;
    hdv->name = -1;
    hdv->rad_size = 0;
    hdv->pos.x = 0;
    hdv->pos.y = 0;
    sfText_setFont(hdv->level_str, font);
    set_texture_hdv(game, hdv);
    sfSprite_setTexture(hdv->bat, hdv->t_bat, sfFalse);
    sfText_setColor(hdv->level_str, sfBlue);
    return (hdv);
}