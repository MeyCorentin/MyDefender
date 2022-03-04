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
        struct_event(game, game->first);
    }
}

void snap_obj(global *game, struct grid_cell *new, shop *my_shop, sfVector2i pos_mouse)
{
    sfVector2f snap_radius;
    if (game->shop_is_open == 0)
    {
        if (pow(abs(pos_mouse.x - 25 - new->p_5.x), 2) + \
            pow(abs(pos_mouse.y - 25 - new->p_5.y), 2) < 1089 \
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && game->take != 1)
        {
            game->on_map = 0;
            if (new->status == 1)
            {
                if (game->take == 0)
                {
                    snap_radius.x = new->p_3.x - 60 - 12;
                    snap_radius.y = new->p_3.y - (abs(new->dy) + abs(new->dy) + abs(new->dy)) - 2;
                    my_shop->pos_cannon.x = new->p_3.x - 60;
                    my_shop->pos_cannon.y = new->p_3.y -
                        (abs(new->dy) + abs(new->dy) + abs(new->dy));
                    game->pos_free.x = my_shop->pos_cannon.x;
                    game->pos_free.y = my_shop->pos_cannon.y;
                }
                if (game->take == 2)
                {
                    snap_radius.x = new->p_3.x - 110;
                    snap_radius.y = new->p_3.y - 140;
                    my_shop->pos_archer.x = new->p_3.x - 60;
                    my_shop->pos_archer.y = new->p_3.y -
                        (abs(new->dy) + abs(new->dy) + abs(new->dy));
                    game->pos_free.x = my_shop->pos_archer.x;
                    game->pos_free.y = my_shop->pos_archer.y;
                }
                if (game->take == 3)
                {
                    snap_radius.x = new->p_3.x - 140;
                    snap_radius.y = new->p_3.y - 175;
                    my_shop->pos_mortar.x = new->p_3.x - 60;
                    my_shop->pos_mortar.y = new->p_3.y -
                        (abs(new->dy) + abs(new->dy) + abs(new->dy));
                    game->pos_free.x = my_shop->pos_mortar.x;
                    game->pos_free.y = my_shop->pos_mortar.y;
                }
                if (game->take == 4)
                {
                    snap_radius.x = new->p_3.x - 140;
                    snap_radius.y = new->p_3.y - 175;
                    my_shop->pos_air_defence.x = new->p_3.x - 60;
                    my_shop->pos_air_defence.y = new->p_3.y -
                        (abs(new->dy) + abs(new->dy) + abs(new->dy));
                    game->pos_free.x = my_shop->pos_air_defence.x;
                    game->pos_free.y = my_shop->pos_air_defence.y;
                }
                if (game->take == 5)
                {
                    snap_radius.x = new->p_3.x - 200;
                    snap_radius.y = new->p_3.y - 250;
                    my_shop->pos_xbow.x = new->p_3.x - 60;
                    my_shop->pos_xbow.y = new->p_3.y -
                        (abs(new->dy) + abs(new->dy) + abs(new->dy));
                    game->pos_free.x = my_shop->pos_xbow.x;
                    game->pos_free.y = my_shop->pos_xbow.y;
                }
                if (game->take == 6)
                {
                    snap_radius.x = new->p_3.x - 90;
                    snap_radius.y = new->p_3.y - 113;
                    my_shop->pos_wizard.x = new->p_3.x - 55;
                    my_shop->pos_wizard.y = new->p_3.y -
                        (abs(new->dy) + abs(new->dy) + abs(new->dy) + 15);
                    game->pos_free.x = my_shop->pos_wizard.x;
                    game->pos_free.y = my_shop->pos_wizard.y;
                }
            }
            sfCircleShape_setPosition(game->radius, snap_radius);
            sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
            sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
            sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
            sfSprite_setPosition(my_shop->s_air_defence, my_shop->pos_air_defence);
            sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
            sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
            game->click = 1;
            game->take_pos = new->g_pos;
        }
    }
}

void place_struct(global *game, struct grid_cell *new, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    sfCircleShape_setFillColor(new->c_5, sfRed);
    if (pow(abs(pos_mouse.x - 25 - new->p_5.x), 2) +
        pow(abs(pos_mouse.y - 25 - new->p_5.y), 2) < 900)                     // Test si cliqué.
        sfCircleShape_setFillColor(new->c_5, sfGreen);
    (new->status == 1) ? sfCircleShape_setFillColor(new->c_5, sfGreen) : 1;   // Met en vert si le status de la cellule est 1.
    snap_obj(game, new, my_shop, pos_mouse);                                  // Colle le bâtiment a la grille sur la quelle il est posé.
    if (new->g_pos == 92)                                                     // Place l'hdv sur l'amplacement choisis.
    {
        game->first->pos.x = new->p_3.x - 55;
        game->first->pos.y = new->p_3.y - (abs(new->dy) + abs(new->dy) + abs(new->dy)) + 10;
        sfSprite_setPosition(game->first->bat, game->first->pos);
    }
    if (new->g_pos != 196)
        place_struct(game, new->next_cell, my_shop);
}

void add_ground(global *game , struct grid_cell *new, shop * my_shop)
{
    if (new->status == 1)
    {
        sfSprite *ground_struct = sfSprite_create();
        sfTexture *ground_struct_text = sfTexture_createFromFile("pictures/maps/ground/struct_ground.png", sfFalse);
        sfVector2f ground_size = {0.8, 0.6};
        sfVector2f ground_pos;

        ground_pos.x = new->p_3.x - 60 + 7;
        ground_pos.y = new->p_3.y - (abs(new->dy) + abs(new->dy) + abs(new->dy)) + 40;
        sfSprite_setScale(ground_struct, ground_size);
        sfSprite_setTexture(ground_struct, ground_struct_text, sfFalse);
        sfSprite_setPosition(ground_struct, ground_pos);
        new->ground = ground_struct;
    }
    if (new->status == 2)
    {
        sfSprite *ground_enemy = sfSprite_create();
        sfTexture *ground_enemy_text = sfTexture_createFromFile("pictures/maps/ground/enemy_ground.png", sfFalse);
        sfVector2f ground_size = {0.8, 0.6};
        sfVector2f ground_pos;

        ground_pos.x = new->p_3.x - 60 + 7;
        ground_pos.y = new->p_3.y - (abs(new->dy) + abs(new->dy) + abs(new->dy)) + 40;
        sfSprite_setScale(ground_enemy, ground_size);
        sfSprite_setTexture(ground_enemy, ground_enemy_text, sfFalse);
        sfSprite_setPosition(ground_enemy, ground_pos);
        new->ground = ground_enemy;
    }
    if (new->g_pos != 196)
        add_ground(game, new->next_cell, my_shop);
}

void draw_ground(global *game, struct grid_cell *new, shop *my_shop)
{
    if (new->status == 1 || new->status == 2)
    {
        sfRenderWindow_drawSprite(game->window, new->ground, sfFalse);
    }
    if (new->g_pos != 196)
        draw_ground(game, new->next_cell, my_shop);
}

void take_cell(global *game, int pos, struct grid_cell *new, shop *my_shop)
{
    if (new->g_pos == pos && new->status == 1)
    {
        new->status = 3; // A MODIIFIER
        add_ground(game, new, my_shop);
    }
    if (new->g_pos != 196)
        take_cell(game, pos, new->next_cell, my_shop);
}

void check_click(global *game, struct grid_cell *grid_cell, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    if ((abs(pos_mouse.x - 25 - grid_cell->p_5.x)) * (abs(pos_mouse.x - 25 - grid_cell->p_5.x)) +
            (abs(pos_mouse.y - 25 - grid_cell->p_5.y)) * (abs(pos_mouse.y - 25 - grid_cell->p_5.y)) <
        900)
    { // Test si cliqué.
        if (game->click == 1 && sfMouse_isButtonPressed(sfMouseLeft) == sfFalse && game->unground == 1)
        {
            take_cell(game, game->take_pos, grid_cell, my_shop);
            game->click = 0;
            game->take_pos = 200;
            game->unground = 0;
        }
    }
    if (grid_cell->g_pos != 196)
        check_click(game, grid_cell->next_cell, my_shop);
}

void create_enemy(global *game, struct enemy_ *enemy)
{
    sfVector2f pos = {269,504};
    sfTexture * e_1 =
    sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
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



void start_game(global *game)
{
    shop *my_shop = create_shop();
    struct grid_cell grid_cell;
    struct enemy_ enemy_f;

    set_game(game); // Init la game.
    create_gold(game);
    grid_cell = init_cell(game, grid_cell, my_shop); // Init la première cellule.
    make_grid(game, &grid_cell, my_shop);
    ////////////////////////////////////////////////////////////////////////////
    sfCircleShape *radius = sfCircleShape_create();
    game->radius = radius;
    game->rad_god = 0;
    game->click = 0;
    game->unground = 0;
    ////////////////////////////////////////////////////////////////////////////
    sfVector2f pos = {269,504};
    sfTexture * e_1 =
    sfTexture_createFromFile("pictures/mob/dragon.png", NULL);
    sfSprite *temp = sfSprite_create();

    enemy_f.enemy_1 = temp;
    enemy_f.pos = pos;
    enemy_f.texture = e_1;
    enemy_f.enemy_first = NULL;
    enemy_f.enemy_next = NULL;
    ////////////////////////////////////////////////////////////////////////////
    read_path(game);
    ////////////////////////////////////////////////////////////////////////////
    const char* filename = "out.txt";
    FILE* output_file = fopen(filename, "w+");
    add_cell_status(game, grid_cell.next_cell, my_shop, output_file); // Modifie le status des cellules.
    fclose(output_file);
    ////////////////////////////////////////////////////////////////////////////
    create_enemy(game, &enemy_f);
    create_enemy(game, &enemy_f);
    create_enemy(game, &enemy_f);
    create_enemy(game, &enemy_f);
    create_enemy(game, &enemy_f);
    create_enemy(game, &enemy_f);
    create_enemy(game, &enemy_f);

    ////////////////////////////////////////////////////////////////////////////
    add_ground(game, grid_cell.next_cell, my_shop);
    while (sfRenderWindow_isOpen(game->window))
    {
        sfRenderWindow_clear(game->window, sfBlack);
        update_game(game);                   // Met a jour les sprites.
        draw_game(game, my_shop, grid_cell); // Draw la map.                                   // Draw les bâtiments.
        (game->shop_is_open == 0) ? open_shop(game, my_shop) : 1;
        draw_enemy(game, &enemy_f);
        // sfRenderWindow_drawSprite(game->window, enemy_f.enemy_1, sfFalse);
        check_game_event(game, my_shop);
        sfRenderWindow_display(game->window);
        check_click(game, &grid_cell, my_shop); // Regarde les inputs.
    }
}
