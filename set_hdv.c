/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create hdv
*/

#include "includes/my_defender.h"

batiment *add_bat(global *game, batiment *prev, sfVector2f pos)
{
    batiment *new_bat = malloc(sizeof(batiment));

    new_bat->first = game->first;
    new_bat->prev = prev;
    new_bat->next = NULL;
    new_bat->last = NULL;
    new_bat->level = 1;
    new_bat->type = 1;
    new_bat->bat = sfSprite_create();
    new_bat->t_bat = sfTexture_createFromFile(game->texture, NULL);
    sfSprite_setTexture(new_bat->bat, new_bat->t_bat, sfFalse);
    new_bat->pos.x = pos.x;
    new_bat->pos.y = pos.y;
    sfSprite_setPosition(new_bat->bat, new_bat->pos);
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

    hdv->first = hdv;
    hdv->next = NULL;
    hdv->last = NULL;
    hdv->level = game->level;
    hdv->bat = sfSprite_create();
    set_texture_hdv(game, hdv);
    sfSprite_setTexture(hdv->bat, hdv->t_bat, sfFalse);
    return (hdv);
}
