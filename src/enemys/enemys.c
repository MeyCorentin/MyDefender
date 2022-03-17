/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

int get_path_pos_x(int i)
{
    char *buffer = malloc(sizeof(char) * 100000);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_x = malloc(sizeof(char) * 100000);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, 100000);
    for (; k != i; k++)
        for (; buffer[cmpt++] != '\n';);
    for (; buffer[cmpt] != ','; cmpt++, j++)
        path_x[j] = buffer[cmpt];
    path_x[j] = '\0';
    close(fd);
    return (my_getnbr(path_x));
}

int get_path_pos_y(int i)
{
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
    for (; buffer[cmpt] != '\n'; cmpt++, j++)
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
    new->pv_max = new->pv;
    new->clock = sfClock_create();
    new->seconds = 0;
    create_lifebar(game, new);
    (enemy->enemy_next == NULL) ? enemy->enemy_next = new : \
    create_enemy(game, enemy->enemy_next, i);
}

void set_enemy_pos(global *game, struct enemy_ *enemy)
{
    enemy->old_x = enemy->pos.x;
    if (enemy->loc > 0) {
    enemy->pos.x = get_path_pos_x(enemy->loc);
    enemy->pos.y = get_path_pos_y(enemy->loc);
    enemy->pos.x -= 25;
    enemy->pos.y -= 20;
    if(enemy->old_x > enemy->pos.x)
        sfSprite_setTexture(enemy->enemy_1, enemy->mirror, sfFalse);
    else
        sfSprite_setTexture(enemy->enemy_1, enemy->texture, sfFalse);
    sfSprite_setPosition(enemy->enemy_1, enemy->pos);
    if (enemy->enemy_next != NULL)
        set_enemy_pos(game, enemy->enemy_next);
    }
}

void draw_enemy(global *game, struct enemy_ *enemy)
{
    do_rect_enemy(game, enemy);
    sfRenderWindow_drawSprite(game->window, enemy->enemy_1, sfFalse);
    update_lifebar(game, enemy);
    sfSprite_setTextureRect(enemy->lifebar->life, enemy->lifebar->rect);
    enemy->lifebar->pos_life.x = enemy->pos.x;
    enemy->lifebar->pos_life.y = enemy->pos.y + 70;
    sfSprite_setPosition(enemy->lifebar->life, enemy->lifebar->pos_life);
    if (enemy->pv_max != -1)
        sfRenderWindow_drawSprite(game->window, enemy->lifebar->life, sfFalse);
    if (enemy->enemy_next != NULL)
        draw_enemy(game, enemy->enemy_next);
}

void moov_enemy(global *game, struct enemy_ *enemy)
{
    enemy->loc++;
    if (enemy->loc >= 0) {
        if (enemy->pv <= 0) {
            enemy->loc = 0;
            enemy->pv = enemy->pv_base;
            game->first->gold += enemy->reward;
            update_gold(game);
        }
        if (enemy->loc >= 38 * 30)
            enemy->loc = 0;
        set_enemy_pos(game, enemy);
    }
    if (enemy->enemy_next != NULL)
        moov_enemy(game, enemy->enemy_next);
}

sfIntRect move_rect(sfIntRect rect, float offset, int max_value)
{
    rect.left += offset;
    if (rect.left >= max_value)
        rect.left = 0;
    return (rect);
}

void do_rect_enemy(global *game, struct enemy_ *enemy)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = enemy->time.microseconds / 5000;
    if (enemy->seconds >= 20) {
        enemy->rect = move_rect(enemy->rect, enemy->offset, enemy->max_value);
        sfClock_restart(enemy->clock);
    }
    sfSprite_setTextureRect(enemy->enemy_1, enemy->rect);
}

void set_enemy(global *game, struct enemy_ *enemy_f)
{
    sfCircleShape *radius = sfCircleShape_create();
    sfTexture *e_1 =
    sfTexture_createFromFile("pictures/mob/dragon2.png", NULL);
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
    enemy_f->lifebar = malloc(sizeof(lifebar_t));
    enemy_f->pv_max = -1;
    enemy_f->clock = sfClock_create();
    enemy_f->offset = 0;
    enemy_f->max_value = 0;
    create_lifebar(game, enemy_f);
    game->enemy = enemy_f;
    for (int i = 0; i != 15; i++)
        create_enemy(game, enemy_f, rand() % 5 + 1);
    set_enemy_pos(game, enemy_f);
}