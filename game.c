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
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->shop_is_open == 1 && sfKeyboard_isKeyPressed(sfKeyS) && \
            game->secs != 1) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(my_shop->button, my_shop->open, sfFalse);
            game->shop_is_open = 0;
            sfSprite_setPosition(my_shop->button, my_shop->pos_button_open);
            game->secs = 1;
        } if (game->shop_is_open == 0 && sfKeyboard_isKeyPressed(sfKeyS) && \
            game->secs != 1) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(my_shop->button, my_shop->close, sfFalse);
            game->shop_is_open = 1;
            sfSprite_setPosition(my_shop->button, my_shop->pos_button_close);
            game->secs = 1;
        }
        check_shop(game, my_shop);
    }
}

void snap_obj(global *game, grid_cell new, shop *my_shop, sfVector2i pos_mouse)
{
    if (game->shop_is_open == 0) {
        if (pow(abs(pos_mouse.x - 25- new.p_5.x), 2) + pow(abs(pos_mouse.y - \
25 - new.p_5.y) , 2) < 1089 && sfMouse_isButtonPressed(sfMouseLeft) == \
            sfTrue)  {
            my_shop->pos_cannon.x = new.p_3.x - 60;
            my_shop->pos_cannon.y = new.p_3.y - (abs(new.dy) + abs(new.dy) + \
                                                 abs(new.dy));
            sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
            my_shop->snap = 1;
        }
    }
    if (new.g_pos == 92) {
        game->first->pos.x = new.p_3.x - 55;
        game->first->pos.y = new.p_3.y - (abs(new.dy) + abs(new.dy) + \
                                          abs(new.dy)) + 10;
        sfSprite_setPosition(game->first->bat, game->first->pos);
    }
}

void place_obj(global *game, grid_cell new, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);

    if (pow(abs(pos_mouse.x - 25- new.p_5.x), 2) + pow(abs(pos_mouse.y - 25 - \
new.p_5.y), 2) < 900)
        sfCircleShape_setFillColor(new.c_5, sfGreen);
    else
        sfCircleShape_setFillColor(new.c_5, sfRed);
    snap_obj(game, new, my_shop, pos_mouse);
}

void make_grid(global *game , grid_cell * grid_cell , shop * my_shop)
{
    struct grid_cell new;
    int i = grid_cell->l_pos;
    int r = (grid_cell->g_pos ) /14;
    int dx = 51;
    int dy = -33;
    int original_x = 260 - 17 + (dx * r);
    int original_y = 540  - 11 + (abs(dy) * r);
    sfCircleShape * c_1 = sfCircleShape_create();
    sfVector2f p_1 = {original_x + (dx * (0 + i)), original_y + (dy * (0 + i))};
    sfCircleShape * c_2 = sfCircleShape_create();
    sfVector2f p_2 = {original_x + (dx * (1 + i)) , original_y + (dy * (1 + i))};
    sfCircleShape * c_3 = sfCircleShape_create();
    sfVector2f p_3 = {original_x + (dx * (1 + i)), original_y - dy  + (dy * (0 + i))};
    sfCircleShape * c_4 = sfCircleShape_create();
    sfVector2f p_4 = {original_x + (dx * (2 + i)) , original_y +(dy * (0 + i))};
    sfCircleShape * c_5 = sfCircleShape_create();
    sfVector2f p_5 = {original_x + (dx * (0 + i)) + dx - 25 , original_y + (dy * (0 + i) - 25)};
    
    sfCircleShape_setFillColor(c_1 , sfBlue);
    sfCircleShape_setRadius(c_1 , 5.0);
    sfCircleShape_setPosition(c_1 , p_1);
    sfCircleShape_setFillColor(c_2 , sfBlue);
    sfCircleShape_setRadius(c_2 , 5.0);
    sfCircleShape_setPosition(c_2 , p_2);
    sfCircleShape_setFillColor(c_3 , sfBlue);
    sfCircleShape_setRadius(c_3 , 5.0);
    sfCircleShape_setPosition(c_3 , p_3);
    sfCircleShape_setFillColor(c_4 , sfBlue);
    sfCircleShape_setRadius(c_4 , 5.0);
    sfCircleShape_setPosition(c_4 , p_4);
    sfCircleShape_setRadius(c_5 , 33.0);
    sfCircleShape_setPosition(c_5 , p_5);
    new.c_1 = c_1;
    new.c_2 = c_2;
    new.c_3 = c_3;
    new.c_4 = c_4;
    new.c_5 = c_5;
    new.p_3 = p_3;
    new.p_5 = p_5;
    new.dx = dx;
    new.dy = dy;
    new.first_cell = grid_cell->first_cell;
    new.prev_cell = grid_cell;
    new.first_cell = grid_cell->first_cell;
    new.g_pos = grid_cell->g_pos + 1;
    new.next_cell = NULL;
    new.l_pos = grid_cell->l_pos + 1;
    grid_cell->next_cell = &new;
    place_obj(game , new, my_shop);
    (game->god == 0) ? draw_point(game , new , my_shop) : 1;
    sfRenderWindow_drawSprite(game->window, game->first->bat, sfFalse);
    (new.l_pos == 14) ? new.l_pos = 0 : 1;
    (new.g_pos != 196) ? make_grid(game, &new, my_shop) : 1;
}

void start_game(global *game)
{
    shop *my_shop = create_shop();
    struct grid_cell grid_cell;

    set_game(game);
    grid_cell.g_pos = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        update_game(game);
        draw_game(game, my_shop);
        make_grid(game , &grid_cell , my_shop);
        draw_structs(game);
        if (game->shop_is_open == 0)
            open_shop(game, my_shop);
        sfRenderWindow_display(game->window);
        check_game_event(game, my_shop);
    }
}
