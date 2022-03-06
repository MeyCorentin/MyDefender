/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/my_defender.h"

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
    char *buffer = malloc(sizeof(char) * 139);
    int fd = open("src/txt/path", O_RDONLY);

    int test = read(fd, buffer, 139);
    buffer[test] = '\0';
    close(fd);
    char **temp_split = my_split_tab(buffer, '\n');
    char **split_path = my_split_tab(temp_split[level - 1], '/');
    game->boole->path_nbr = my_count_split(temp_split[level - 1], '/');
    game->map->path_way = split_path;
}

void add_cell_status(global *game, grid_cell *new, shop *my_shop, FILE* \
output_file)
{
    int i = 0;
    int fd = open("src/txt/path", O_RDONLY);

    new->status = 1;
    for (; game->map->path_way[i]; i++) {
        if (my_getnbr(game->map->path_way[i]) == new->g_pos) {
            fwrite(new_put_nbr_str((int) new->p_5.x), 1, 3, output_file);
            fwrite(",", 1, 1, output_file);
            fwrite(new_put_nbr_str((int) new->p_5.y), 1, 3, output_file);
            fwrite("\n", 1, 1, output_file);
            new->status = 2;
        }
    }
    close(fd);
    if (new->g_pos != 196)
        add_cell_status(game, new->next_cell, my_shop, output_file);
}
