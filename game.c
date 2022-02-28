/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "includes/my_defender.h"
#include <SFML/Graphics.h>
#include <stdio.h>
#include <math.h>

void check_game_event(global *game, shop *my_shop)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
    {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->shop_is_open == 1 && sfKeyboard_isKeyPressed(sfKeyS) &&
            game->secs != 1)
        {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(my_shop->button, my_shop->open, sfFalse);
            game->shop_is_open = 0;
            sfSprite_setPosition(my_shop->button, my_shop->pos_button_open);
            game->secs = 1;
        }
        if (game->shop_is_open == 0 && sfKeyboard_isKeyPressed(sfKeyS) &&
            game->secs != 1)
        {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(my_shop->button, my_shop->close, sfFalse);
            game->shop_is_open = 1;
            sfSprite_setPosition(my_shop->button, my_shop->pos_button_close);
            game->secs = 1;
        }
        check_shop(game, my_shop);
    }
}

void snap_obj(global *game, struct grid_cell *new, shop *my_shop, sfVector2i pos_mouse)
{
    if (game->shop_is_open == 0)
    {
        if (pow(abs(pos_mouse.x - 25 - new->p_5.x), 2) + \
        pow(abs(pos_mouse.y - 25 - new->p_5.y), 2) < 1089 \
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        {
            my_shop->pos_cannon.x = new->p_3.x - 60;
            my_shop->pos_cannon.y = new->p_3.y - \
            (abs(new->dy) + abs(new->dy) + abs(new->dy));
            sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
        }
    }
}

void place_struct(global *game, struct grid_cell *new, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    sfCircleShape_setFillColor(new->c_5, sfRed);
    if (pow(abs(pos_mouse.x - 25 - new->p_5.x), 2) + \
    pow(abs(pos_mouse.y - 25 - new->p_5.y), 2) < 900)                         // Test si cliqué.
    {
        (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) ? new->test = 1 : 1;
        sfCircleShape_setFillColor(new->c_5, sfGreen);
    }
    (new->test == 1) ? sfCircleShape_setFillColor(new->c_5, sfBlue) : 1;      // Test si cliqué.
    (new->status == 1) ? sfCircleShape_setFillColor(new->c_5, sfGreen) : 1;   // Met en vert si le status de la cellule est 1.
    snap_obj(game, new, my_shop, pos_mouse);                                  // Colle le bâtiment a la grille sur la quelle il est posé.
    if (new->g_pos == 92)                                                     // Place l'hdv sur l'amplacement choisis.
    {
        game->first->pos.x = new->p_3.x - 55;
        game->first->pos.y = new->p_3.y - (abs(new->dy) + \
        abs(new->dy) + abs(new->dy)) + 10;
        sfSprite_setPosition(game->first->bat, game->first->pos);
    }
    if (new->g_pos != 196)
        place_struct(game, new->next_cell, my_shop);
}

void start_game(global *game)
{
    shop *my_shop = create_shop();
    struct grid_cell grid_cell;

    set_game(game);                                                           // Init la game.
    grid_cell = init_cell(game, grid_cell, my_shop);                          // Init la première cellule.
    make_grid(game, &grid_cell, my_shop);                                     // Init la grill de cellules.
    while (sfRenderWindow_isOpen(game->window))
    {
        sfRenderWindow_clear(game->window, sfBlack);
        update_game(game);                                                    // Met a jour les sprites.
        draw_game(game, my_shop);                                             // Draw la map.
        add_cell_status(game, grid_cell.next_cell, my_shop);                  // Modifie le status des cellules.
        (game->god == 0) ? draw_cell(game, grid_cell.next_cell, my_shop) : 1; // Affiche les cellules.
        place_struct(game, &grid_cell, my_shop);                              // Place tous les bâtiments.
        draw_structs(game);                                                   // Draw les bâtiments.
        (game->shop_is_open == 0) ? open_shop(game, my_shop) : 1;             // Draw les shops;
        sfRenderWindow_display(game->window);
        check_game_event(game, my_shop);                                      // Regarde les inputs.
    }
}
