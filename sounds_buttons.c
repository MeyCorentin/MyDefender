/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to turn on/off sounds
*/

#include "includes/my_defender.h"

void check_music(global *game, menu *menus, sfVector2i mouse)
{
    if (mouse.x >= menus->pos_music.x && mouse.x <= menus->pos_music.x + 100 \
        && mouse.y >= menus->pos_music.y && mouse.y <= menus->pos_music.y + \
        100 && game->event.type == sfEvtMouseButtonReleased) {
        if (game->is_music == 1 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(menus->music, menus->m_on, sfFalse);
            game->is_music = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->ambiance, 100);
        } else if (game->is_music == 0 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(menus->music, menus->m_off, sfFalse);
            game->is_music = 1;
            game->secs = 2;
            sfSound_setVolume(game->sounds->ambiance, 0);
        }
    }
}

void check_music_pause(global *game, sfVector2i mouse)
{
    if (mouse.x >= game->pause->pos_music.x && mouse.x <= game->pause->pos_music.x + 100 && mouse.y >= game->pause->pos_music.y && mouse.y <= game->pause->pos_music.y + 100 && game->event.type == sfEvtMouseButtonReleased) {
	if (game->is_music == 1 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(game->menus->music, game->menus->m_on, sfFalse);
            sfSprite_setTexture(game->pause->music, game->menus->m_on, sfFalse);
            game->is_music = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->ambiance, 100);
	} else if (game->is_music == 0 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(game->menus->music, game->menus->m_off, sfFalse);
            sfSprite_setTexture(game->pause->music, game->menus->m_off, sfFalse);
            game->is_music = 1;
            game->secs = 2;
            sfSound_setVolume(game->sounds->ambiance, 0);
	}
    }
}

void check_sounds(global *game, menu *menus, sfVector2i mouse)
{
    if (mouse.x >= menus->pos_sounds.x && mouse.x <= menus->pos_sounds.x + 100 \
	&& mouse.y >= menus->pos_sounds.y && mouse.y <= menus->pos_sounds.y + \
	100 && game->event.type == sfEvtMouseButtonReleased) {
	if (game->is_sounds == 1 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(menus->sounds, menus->s_on, sfFalse);
            game->is_sounds = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->click, 100);
            sfSound_setVolume(game->sounds->anvil, 100);
	} else if (game->is_sounds == 0 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(menus->sounds, menus->s_off, sfFalse);
            game->is_sounds = 1;
            game->secs = 2;
            sfSound_setVolume(game->sounds->click, 0);
            sfSound_setVolume(game->sounds->anvil, 0);
	}
    }
}

void check_sounds_pause(global *game, sfVector2i mouse)
{
    if (mouse.x >= game->pause->pos_sounds.x && mouse.x <= game->pause->pos_sounds.x + 50 && mouse.y >= game->pause->pos_sounds.y && mouse.y <= game->pause->pos_sounds.y + 50 && game->event.type == sfEvtMouseButtonReleased) {
	if (game->is_sounds == 1 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(game->menus->sounds, game->menus->s_on, sfFalse);
            sfSprite_setTexture(game->pause->sounds, game->menus->s_on, sfFalse);
            game->is_sounds = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->click, 100);
            sfSound_setVolume(game->sounds->anvil, 100);
	} else if (game->is_sounds == 0 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(game->menus->sounds, game->menus->s_off, sfFalse);
            sfSprite_setTexture(game->pause->sounds, game->menus->s_off, sfFalse);
            game->is_sounds = 1;
            game->secs = 2;
            sfSound_setVolume(game->sounds->click, 0);
            sfSound_setVolume(game->sounds->anvil, 0);
	}
    }
}
