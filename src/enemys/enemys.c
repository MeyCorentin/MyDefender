/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

void create_enemy(global *game, struct enemy_ *enemy)
{
    sfVector2f pos = {269,504};
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
    enemy_ *new = malloc(sizeof(enemy_));
    sfSprite *temp = sfSprite_create();

    new->enemy_1 = temp;
    new->pos = pos;
    new->texture = e_1;
    new->enemy_next = NULL;
    sfSprite_setPosition(new->enemy_1, new->pos);
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    if (enemy->enemy_first == NULL)
        enemy->enemy_first = new;
    if (enemy->enemy_next == NULL)
        enemy->enemy_next = new;
    else {
        create_enemy(game, enemy->enemy_next);
    }
}

void draw_enemy(global *game, struct enemy_ *enemy)
{
    sfRenderWindow_drawSprite(game->window, enemy->enemy_1, sfFalse);
    if (enemy->enemy_next!= NULL)
        draw_enemy(game, enemy->enemy_next);
}

void set_enemy(global *game, struct enemy_ *enemy_f)
{
    sfCircleShape *radius = sfCircleShape_create();
    sfVector2f pos = {269,504};
    sfTexture * e_1 =
    sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
    sfSprite *temp = sfSprite_create();

    game->radius = radius;
    game->rad_god = 0;
    game->boole->click = 0;
    game->boole->unground = 0;
    enemy_f->enemy_1 = temp;
    enemy_f->pos = pos;
    enemy_f->texture = e_1;
    enemy_f->enemy_first = NULL;
    enemy_f->enemy_next = NULL;
    for (int cmpt = 0; cmpt < 7; cmpt += 1)
        create_enemy(game, enemy_f);
}
