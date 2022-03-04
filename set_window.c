/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set a basic window
*/

#include "includes/my_defender.h"

void create_sounds(global *game)
{
    game->sounds = malloc(sizeof(sounds));
    game->sounds->music = sfSoundBuffer_createFromFile("Sounds/ambiance.ogg");
    game->sounds->b_anvil = sfSoundBuffer_createFromFile("Sounds/anvil.ogg");
    game->sounds->b_click = sfSoundBuffer_createFromFile("Sounds/click.ogg");
    game->sounds->ambiance = sfSound_create();
    game->sounds->anvil = sfSound_create();
    game->sounds->click = sfSound_create();
    sfSound_setBuffer(game->sounds->ambiance, game->sounds->music);
    sfSound_setBuffer(game->sounds->anvil, game->sounds->b_anvil);
    sfSound_setBuffer(game->sounds->click, game->sounds->b_click);
    game->sounds->is_playing = 1;
}

void check_event(global *game, menu *menus)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *) game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if ((game->event.type == sfEvtClosed || \
sfKeyboard_isKeyPressed(sfKeyQ)) && game->secs != 4) {
            sfSound_play(game->sounds->click);
            sfRenderWindow_close(game->window);
        } if (sfKeyboard_isKeyPressed(sfKeyC)) {
            sfSound_play(game->sounds->click);
            start_game(game);
        } if (sfKeyboard_isKeyPressed(sfKeyR)) {
            sfSound_play(game->sounds->click);
            game->gold = 100000;
            game->price_hdv = 1000;
            game->level = 1;
            start_game(game);
        }
        check_button_quit(game, menus);
        check_sounds(game, menus, mouse);
        check_music(game, menus, mouse);
    }
}

void set_menu(global *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_menu(game, game->menus);
        check_event(game, game->menus);
        update_game(game);
        sfRenderWindow_display(game->window);
    }
}

void create_window(int level)
{
    sfVideoMode mode = {1920, 1080, 64};
    global *game = malloc(sizeof(global));
    menu *menus = create_menu(level);

    game->window = sfRenderWindow_create(mode, "My Defender",           \
                                                   sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    game->level = level;
    game->clock = sfClock_create();
    game->is_sounds = 0;
    game->is_music = 0;
    game->gold = 100000;
    game->price_hdv = 1000;
    create_sounds(game);
    set_sounds_buttons(game, menus);
    game->menus = menus;
    set_menu(game);
}
