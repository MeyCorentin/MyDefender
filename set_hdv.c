/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create hdv
*/

#include "includes/my_defender.h"

batiment *add_bat(global *game, batiment *prev, sfVector2f pos, int name)
{
    batiment *new_bat = malloc(sizeof(batiment));
    sfFont *font = sfFont_createFromFile("pictures/ArialCE.ttf");

    new_bat->first = game->first;
    new_bat->temp = malloc(sizeof(char *));
    new_bat->prev = prev;
    new_bat->next = NULL;
    new_bat->last = NULL;
    new_bat->level = 1;
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

    hdv->first = hdv;
    hdv->next = NULL;
    hdv->last = NULL;
    hdv->level = game->level;
    hdv->gold = 1000;
    hdv->bat = sfSprite_create();
    hdv->temp = malloc(sizeof(char *));
    hdv->level_str = sfText_create();
    sfText_setFont(hdv->level_str, font);
    set_texture_hdv(game, hdv);
    sfSprite_setTexture(hdv->bat, hdv->t_bat, sfFalse);
    sfText_setColor(hdv->level_str, sfBlue);
    return (hdv);
}