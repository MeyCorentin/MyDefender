/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/my_defender.h"

void take_cell(global *game, int pos, struct grid_cell *new, shop *my_shop)
{
    if (new->g_pos == pos && new->status == 1) {
        new->status = 3; //À MODIFIER
        add_ground(game, new, my_shop);
    }
    if (new->g_pos != 196)
        take_cell(game, pos, new->next_cell, my_shop);
}

void check_click(global *game, struct grid_cell *grid_cell, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    if ((abs(pos_mouse.x - 25 - grid_cell->p_5.x)) * (abs(pos_mouse.x - 25 - \
    grid_cell->p_5.x)) + (abs(pos_mouse.y - 25 - grid_cell->p_5.y)) * \
    (abs(pos_mouse.y - 25 - grid_cell->p_5.y)) < 900) {
        if (game->boole->click == 1 && sfMouse_isButtonPressed(sfMouseLeft) == \
        sfFalse && game->boole->unground == 1) {
            take_cell(game, game->boole->take_pos, grid_cell, my_shop);
            game->boole->click = 0;
            game->boole->take_pos = 200;
            game->boole->unground = 0;
        }
    }
    if (grid_cell->g_pos != 196)
        check_click(game, grid_cell->next_cell, my_shop);
}

void read_something(global *game, struct grid_cell grid_cell, shop *my_shop)
{
    read_path(game);
    const char* filename = "src/txt/out.txt";
    FILE* output_file = fopen(filename, "w+");
    add_cell_status(game, grid_cell.next_cell, my_shop, output_file);
    fclose(output_file);
}

struct grid_cell set_all(global *game, shop *my_shop, struct grid_cell \
grid_cell, struct enemy_ *enemy_f)
{
    set_enemy(game, enemy_f);
    set_game(game);
    create_gold(game);
    grid_cell = init_cell(game, grid_cell, my_shop);
    make_grid(game, &grid_cell, my_shop);
    read_something(game, grid_cell, my_shop);
    add_ground(game, grid_cell.next_cell, my_shop);
    return (grid_cell);
}
