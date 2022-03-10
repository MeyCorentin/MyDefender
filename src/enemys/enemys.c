/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

int get_path_pos_x(int i) {
    char *buffer = malloc(sizeof(char) * 100000);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_x = malloc(sizeof(char) * 100000);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, 100000);
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
    char *buffer = malloc(sizeof(char) * 100000);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_y = malloc(sizeof(char) * 100000);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, 100000);
    for (; k != i; k++)
        for (; buffer[cmpt++] != '\n';);
    for (; buffer[cmpt] != ','; cmpt++);
    for (; buffer[cmpt] != '\n'; cmpt++ , j++)
        path_y[j] = buffer[cmpt];
    path_y[j] = '\0';
    close(fd);
    return (my_getnbr(path_y));
}

void create_enemy(global *game, struct enemy_ *enemy, int i)
{
    enemy_ *new = malloc(sizeof(enemy_));

    if (i == 1)
        new = create_barbar(game, enemy, i, new);
    if (i == 2)
        new = create_archer(game, enemy, i, new);
    if (i == 3)
        new = create_goblin(game, enemy, i, new);
    if (i == 4)
        new = create_giant(game, enemy, i, new);
    if (i == 5)
        new = create_dragon(game, enemy, i, new);
    (enemy->enemy_next == NULL) ? enemy->enemy_next = new : \
    create_enemy(game, enemy->enemy_next, i);
}

void set_enemy_pos(global * game, struct enemy_ *enemy) {
    if(enemy->loc > 0) {
    enemy->e_pos.x = get_path_pos_x(enemy->loc);
    enemy->e_pos.y = get_path_pos_y(enemy->loc);
    enemy->e_pos.x -= 25;
    enemy->e_pos.y -= 20;
    enemy->pos = enemy->e_pos;
    sfSprite_setPosition(enemy->enemy_1, enemy->e_pos);
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
    if (enemy->loc >= 0) {
        if (enemy->pv <= 0) {
            enemy->loc = 0;
            enemy->pv = enemy->pv_base;
            game->first->gold  += enemy->reward;
            update_gold(game);
        }
        if (enemy->loc >= 38 * 30)
            enemy->loc = 0;
        set_enemy_pos(game, enemy);
    }
    if (enemy->enemy_next!= NULL)
        moov_enemy(game, enemy->enemy_next);
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
    for(int i = 0 ; i != 5; i ++)
        create_enemy(game, enemy_f, rand() % 2 + 1);

    set_enemy_pos(game, enemy_f);
}


