/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set pause menu
*/

#include "includes/my_defender.h"

void set_textures(global *game, menu *menus)
{
    menus->m_on = sfTexture_createFromFile("pictures/buttons/music\
_on.png", NULL);
    menus->m_off = sfTexture_createFromFile("pictures/buttons/music\
_off.png", NULL);
    menus->s_on = sfTexture_createFromFile("pictures/buttons/sounds\
_on.png", NULL);
    menus->s_off = sfTexture_createFromFile("pictures/buttons/sounds\
_off.png", NULL);
}

void set_sounds_buttons(global *game, menu *menus)
{
    sfVector2f size_music = {2, 2};
    sfVector2f size_sounds = {2, 2};

    menus->music = sfSprite_create();
    menus->sounds = sfSprite_create();
    menus->pos_music.x = 20;
    menus->pos_music.y = 10;
    menus->pos_sounds.x = 1800;
    menus->pos_sounds.y = 10;
    set_textures(game, menus);
    sfSprite_setTexture(menus->music, menus->m_on, sfFalse);
    sfSprite_setTexture(menus->sounds, menus->s_on, sfFalse);
    sfSprite_setPosition(menus->music, menus->pos_music);
    sfSprite_setPosition(menus->sounds, menus->pos_sounds);
    sfSprite_setScale(menus->music, size_music);
    sfSprite_setScale(menus->sounds, size_sounds);
}

void set_pos_buttons(global *game)
{
    sfVector2f scale = {0.5, 0.5};

    game->pause->pos_back.x = 480;
    game->pause->pos_back.y = 250;
    game->pause->pos_con.x = game->pause->pos_back.x + 50;
    game->pause->pos_con.y = game->pause->pos_back.y + 300;
    game->pause->pos_res.x = game->pause->pos_back.x + 360;
    game->pause->pos_res.y = game->pause->pos_back.y + 300;
    game->pause->pos_quit.x = game->pause->pos_back.x + 670;
    game->pause->pos_quit.y = game->pause->pos_back.y + 300;
    sfSprite_setPosition(game->pause->continu, game->pause->pos_con);
    sfSprite_setPosition(game->pause->restart, game->pause->pos_res);
    sfSprite_setPosition(game->pause->quit, game->pause->pos_quit);
    sfSprite_setPosition(game->pause->back, game->pause->pos_back);
    sfSprite_setScale(game->pause->continu, scale);
    sfSprite_setScale(game->pause->restart, scale);
    sfSprite_setScale(game->pause->quit, scale);
    sfSprite_setScale(game->pause->back, scale);
}

void set_pos_sounds(global *game)
{
    sfVector2f scale_text = {3, 3};

    game->pause->pos_music.x = game->pause->pos_back.x + 10;
    game->pause->pos_music.y = game->pause->pos_back.y + 10;
    game->pause->pos_sounds.x = game->pause->pos_back.x + 900;
    game->pause->pos_sounds.y = game->pause->pos_back.y + 10;
    sfSprite_setPosition(game->pause->music, game->pause->pos_music);
    sfSprite_setPosition(game->pause->sounds, game->pause->pos_sounds);
    if (game->is_music == 0)
        sfSprite_setTexture(game->pause->music, game->menus->m_on, sfFalse);
    else
        sfSprite_setTexture(game->pause->music, game->menus->m_off, sfFalse);
    if (game->is_sounds == 0)
        sfSprite_setTexture(game->pause->sounds, game->menus->s_on, sfFalse);
    else
        sfSprite_setTexture(game->pause->sounds, game->menus->s_off, sfFalse);
    sfText_setScale(game->pause->text, scale_text);
}

void set_pos_text(global *game)
{
    game->pause->text = sfText_create();
    sfText_setString(game->pause->text, "PAUSE");
    game->pause->pos_text.x = game->pause->pos_back.x + 300;
    game->pause->pos_text.y = game->pause->pos_back.y + 100;
    sfText_setPosition(game->pause->text, game->pause->pos_text);
    sfText_setColor(game->pause->text, sfBlack);
}
