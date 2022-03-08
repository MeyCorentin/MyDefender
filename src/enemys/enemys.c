/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

int get_path_pos_x(int i) {
    char *buffer = malloc(sizeof(char) * 2173000);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_x = malloc(sizeof(char) * 2173000);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, 2173000);
    for (; k != i; k++)
        for (; buffer[cmpt++] != '\n';);
    for (; buffer[cmpt] != ','; cmpt++ , j++)
        path_x[j] = buffer[cmpt];
    path_x[j] = '\0';
    // printf("%s\n", path_x);
    close(fd);
    return (my_getnbr(path_x));
}

int get_path_pos_y(int i) {
    char *buffer = malloc(sizeof(char) * 2173000);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_y = malloc(sizeof(char) * 2173000);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, 2173000);
    for (; k != i; k++)
        for (; buffer[cmpt++] != '\n';);
    for (; buffer[cmpt] != ','; cmpt++);
    for (; buffer[cmpt] != '\n'; cmpt++ , j++)
        path_y[j] = buffer[cmpt];
    path_y[j] = '\0';
    // printf("%s\n", path_y);
    close(fd);
    return (my_getnbr(path_y));
}

void create_enemy(global *game, struct enemy_ *enemy)
{
    sfTexture *e_1 = sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
    enemy_ *new = malloc(sizeof(enemy_));
    sfSprite *temp = sfSprite_create();

    new->enemy_prev = enemy;
    new->loc = -30;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    sfSprite_setTexture(new->enemy_1 , new->texture , sfFalse);
    (enemy->enemy_next == NULL) ? enemy->enemy_next = new : \
    create_enemy(game, enemy->enemy_next);
}

void set_enemy_pos(global * game, struct enemy_ *enemy) {
    sfVector2f pos;

    if(enemy->loc > 0) {
    pos.x = get_path_pos_x(enemy->loc);
    pos.y = get_path_pos_y(enemy->loc);
    pos.x -= 25;
    pos.y -= 20;
    sfSprite_setPosition(enemy->enemy_1, pos);
    if (enemy->enemy_next != NULL)
        set_enemy_pos(game, enemy->enemy_next);
    }
}

void draw_enemy(global *game, struct enemy_ *enemy)
{
    sfRenderWindow_drawSprite(game->window, enemy->enemy_1, sfFalse);
    if (enemy->enemy_next!= NULL)
        draw_enemy(game, enemy->enemy_next);
}

void moov_enemy(global *game, struct enemy_ *enemy)
{
    enemy->loc++;
    if(enemy->loc > 0) {
    if( enemy->loc >= 38 * 30)
        enemy->loc = 0;
    set_enemy_pos(game, enemy);
    if (enemy->enemy_next!= NULL)
        moov_enemy(game, enemy->enemy_next);
    }
}

void set_enemy(global *game, struct enemy_ *enemy_f)
{
    sfCircleShape *radius = sfCircleShape_create();
    sfTexture * e_1 =
    sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
    sfSprite *temp = sfSprite_create();

    game->radius = radius;
    game->rad_god = 0;
    game->boole->click = 0;
    game->boole->unground = 0;
    enemy_f->enemy_1 = temp;
    enemy_f->texture = e_1;
    enemy_f->enemy_first = NULL;
    enemy_f->enemy_next = NULL;
    enemy_f->loc = 0;
    game->enemy = enemy_f;
    for (int cmpt = 0; cmpt < 7; cmpt += 1)
        create_enemy(game, enemy_f);
    set_enemy_pos(game, enemy_f);
}


