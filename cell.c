/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "includes/my_defender.h"
#include "includes/my.h"
#include <SFML/Graphics.h>
#include <stdio.h>
#include <math.h>

grid_cell *make_grid(global *game, grid_cell *grid_cell_, shop *my_shop)
{
    struct grid_cell *new = (grid_cell *)malloc(sizeof(grid_cell));
    int i = grid_cell_->l_pos;
    int r = (grid_cell_->g_pos) / 14;
    int dx = 51;
    int dy = -33;
    int original_x = 260 - 17 + (dx * r);
    int original_y = 540 - 11 + (abs(dy) * r);
    sfCircleShape *c_1 = sfCircleShape_create();
    sfVector2f p_1 = {original_x + (dx * (0 + i)), original_y + (dy * (0 + i))};
    sfCircleShape *c_2 = sfCircleShape_create();
    sfVector2f p_2 = {original_x + (dx * (1 + i)), original_y + (dy * (1 + i))};
    sfCircleShape *c_3 = sfCircleShape_create();
    sfVector2f p_3 = {original_x + (dx * (1 + i)), original_y - dy + (dy * (0 + i))};
    sfCircleShape *c_4 = sfCircleShape_create();
    sfVector2f p_4 = {original_x + (dx * (2 + i)), original_y + (dy * (0 + i))};
    sfCircleShape *c_5 = sfCircleShape_create();
    sfVector2f p_5 = {original_x + (dx * (0 + i)) + dx - 25, original_y + (dy * (0 + i) - 25)};

    sfCircleShape_setFillColor(c_1, sfBlue);
    sfCircleShape_setRadius(c_1, 5.0);
    sfCircleShape_setPosition(c_1, p_1);
    sfCircleShape_setFillColor(c_2, sfBlue);
    sfCircleShape_setRadius(c_2, 5.0);
    sfCircleShape_setPosition(c_2, p_2);
    sfCircleShape_setFillColor(c_3, sfBlue);
    sfCircleShape_setRadius(c_3, 5.0);
    sfCircleShape_setPosition(c_3, p_3);
    sfCircleShape_setFillColor(c_4, sfBlue);
    sfCircleShape_setRadius(c_4, 5.0);
    sfCircleShape_setPosition(c_4, p_4);
    sfCircleShape_setRadius(c_5, 33.0);
    sfCircleShape_setPosition(c_5, p_5);
    new->c_1 = c_1;
    new->c_2 = c_2;
    new->c_3 = c_3;
    new->c_4 = c_4;
    new->c_5 = c_5;
    new->p_3 = p_3;
    new->p_5 = p_5;
    new->dx = dx;
    new->dy = dy;
    new->status = 0;
    new->prev_cell = grid_cell_;
    new->first_cell = grid_cell_->first_cell;
    new->next_cell = NULL;
    new->g_pos = grid_cell_->g_pos + 1;
    new->l_pos = grid_cell_->l_pos + 1;
    grid_cell_->next_cell = new;
    (new->l_pos == 14) ? new->l_pos = 0 : 1;
    if (new->g_pos != 196)
        make_grid(game, new, my_shop);
    return (grid_cell_);
}

grid_cell init_cell(global *game, grid_cell grid_cell_, shop *my_shop)
{
    int i = 0;
    int r = 0;
    int dx = 51;
    int dy = -33;
    int original_x = 260 - 17 + (dx * r);
    int original_y = 540 - 11 + (abs(dy) * r);
    sfCircleShape *c_1 = sfCircleShape_create();
    sfVector2f p_1 = {original_x + (dx * (0 + i)), original_y + (dy * (0 + i))};
    sfCircleShape *c_2 = sfCircleShape_create();
    sfVector2f p_2 = {original_x + (dx * (1 + i)), original_y + (dy * (1 + i))};
    sfCircleShape *c_3 = sfCircleShape_create();
    sfVector2f p_3 = {original_x + (dx * (1 + i)), original_y - dy + (dy * (0 + i))};
    sfCircleShape *c_4 = sfCircleShape_create();
    sfVector2f p_4 = {original_x + (dx * (2 + i)), original_y + (dy * (0 + i))};
    sfCircleShape *c_5 = sfCircleShape_create();
    sfVector2f p_5 = {original_x + (dx * (0 + i)) + dx - 25, original_y + (dy * (0 + i) - 25)};

    sfCircleShape_setFillColor(c_1, sfBlue);
    sfCircleShape_setRadius(c_1, 5.0);
    sfCircleShape_setPosition(c_1, p_1);
    sfCircleShape_setFillColor(c_2, sfBlue);
    sfCircleShape_setRadius(c_2, 5.0);
    sfCircleShape_setPosition(c_2, p_2);
    sfCircleShape_setFillColor(c_3, sfBlue);
    sfCircleShape_setRadius(c_3, 5.0);
    sfCircleShape_setPosition(c_3, p_3);
    sfCircleShape_setFillColor(c_4, sfBlue);
    sfCircleShape_setRadius(c_4, 5.0);
    sfCircleShape_setPosition(c_4, p_4);
    sfCircleShape_setRadius(c_5, 33.0);
    sfCircleShape_setPosition(c_5, p_5);
    grid_cell_.c_1 = c_1;
    grid_cell_.c_2 = c_2;
    grid_cell_.c_3 = c_3;
    grid_cell_.c_4 = c_4;
    grid_cell_.c_5 = c_5;
    grid_cell_.p_3 = p_3;
    grid_cell_.p_5 = p_5;
    grid_cell_.dx = dx;
    grid_cell_.dy = dy;
    grid_cell_.status = 0;
    grid_cell_.prev_cell = NULL;
    grid_cell_.next_cell = NULL;
    grid_cell_.first_cell = &grid_cell_;
    grid_cell_.g_pos = 0;
    grid_cell_.l_pos = 0;
    grid_cell_.first_cell = &grid_cell_;
    return (grid_cell_);
}

void draw_cell(global *game, grid_cell *new, shop *my_shop)
{
    sfRenderWindow_drawCircleShape(game->window, new->c_1, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_2, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_3, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_4, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_5, NULL);
    if (new->g_pos != 196)
        draw_cell(game, new->next_cell, my_shop);
}

void read_path(global *game)
{
    int level = game->menus->level;
    char *buffer = malloc(sizeof(char) * 136);
    int fd = open("path", O_RDONLY);

    int test = read(fd, buffer, 136);
    buffer[test] = '\0';
    close(fd);
    char **temp_split = my_split_tab(buffer, '\n');
    char **split_path = my_split_tab(temp_split[level - 1], '/');
    game->path_nbr = my_count_split(temp_split[level - 1], '/');
    game->path_way = split_path;
}

void add_cell_status(global *game, grid_cell *new, shop *my_shop)
{
    int i = 0;

    new->status = 1;
    for (; game->path_way[i]; i++)
    {
        if (my_getnbr(game->path_way[i]) == new->g_pos)
            new->status = 2;
    }
    if (new->g_pos != 196)
        add_cell_status(game, new->next_cell, my_shop);
}