/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

enemy_ * create_barbar(global *game, struct enemy_ *enemy, int i, enemy_ * new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/barbarian.png", NULL);
    sfSprite *temp = sfSprite_create();

    new->enemy_prev = enemy;
    new->loc = -30;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 45;
    new->damage = 8;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 16;
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    return (new);
}
enemy_ * create_archer(global *game, struct enemy_ *enemy, int i, enemy_ * new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/archer.png", NULL);
    sfSprite *temp = sfSprite_create();

    new->enemy_prev = enemy;
    new->loc = -30;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 20;
    new->damage = 7;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 24;
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    return (new);
}

enemy_ * create_goblin(global *game, struct enemy_ *enemy, int i, enemy_ * new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/goblin.png", NULL);
    sfSprite *temp = sfSprite_create();

    new->enemy_prev = enemy;
    new->loc = -30;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 25;
    new->damage = 11;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 32;
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    return (new);
}
enemy_ * create_giant(global *game, struct enemy_ *enemy, int i, enemy_ * new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/giant.png", NULL);
    sfSprite *temp = sfSprite_create();

    new->enemy_prev = enemy;
    new->loc = -30;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 300;
    new->damage = 22;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 12;
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    return (new);
}

enemy_ * create_dragon(global *game, struct enemy_ *enemy, int i, enemy_ * new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
    sfSprite *temp = sfSprite_create();

    new->enemy_prev = enemy;
    new->loc = -30;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 1900;
    new->damage = 175;
    new->level_hdv = 7;
    new->level = 1;
    new->speed = 16;
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    return (new);
}