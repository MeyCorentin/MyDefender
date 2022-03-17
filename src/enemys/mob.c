/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

enemy_ *create_barbar(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/barbarian2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile("pictures/mob/mirror_barbarian2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 100;
    new->pv_base = 45;
    new->damage = 8;
    new->level_hdv = 1;
    sfSprite_setPosition(new->enemy_1, pos);
    new->level = 1;
    new->speed = 16;
    new->type = 1;
    new->offset = 81.5;
    new->max_value = 1050;
    new->x_size = 82;
    new->y_size = 82;
    new->rect = change_rect(new->rect, 81.5, 82);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    return (new);
}

enemy_ *create_archer(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/archer2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile("pictures/mob/mirror_archer2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 20;
    new->pv_base = 20;
    new->damage = 7;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 24;
    new->type = 2;
    new->reward = 15;
    new->offset = 76;
    new->max_value = 1064;
    new->x_size = 76;
    new->y_size = 89;
    new->rect = change_rect(new->rect, 76, 89);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}

enemy_ *create_goblin(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/goblin2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile("pictures/mob/mirror_goblin2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 25;
    new->pv_base = 25;
    new->damage = 11;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 32;
    new->type = 3;
    new->offset = 99.5;
    new->max_value = 690;
    new->x_size = 99;
    new->y_size = 90;
    new->rect = change_rect(new->rect, 99.5, 90);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}

enemy_ *create_giant(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/giant2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile("pictures/mob/mirror_giant2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 300;
    new->pv_base = 300;
    new->damage = 22;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 12;
    new->type = 4;
    new->offset = 109.3;
    new->max_value = 970;
    new->x_size = 109;
    new->y_size = 85;
    new->rect = change_rect(new->rect, 109.3, 85);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}

enemy_ *create_dragon(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/dragon2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile("pictures/mob/mirror_dragon2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    new->pv = 1900;
    new->pv_base = 1900;
    new->damage = 175;
    new->level_hdv = 7;
    new->level = 1;
    new->speed = 16;
    new->type = 5;
    new->offset = 129.6;
    new->max_value = 1030;
    new->x_size = 130;
    new->y_size = 107;
    new->rect = change_rect(new->rect, 129.6, 107);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}
