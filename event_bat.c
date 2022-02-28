/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to get bat
*/

#include "includes/my_defender.h"

void get_cannon(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_cannon.x && pos_mouse.x <= \
my_shop->pos_cannon.x + 120 && pos_mouse.y >= my_shop->pos_cannon.y && \
pos_mouse.y <= my_shop->pos_cannon.y + 100 && \
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        rad_pos.x = pos_mouse.x - 90;
        rad_pos.y = pos_mouse.y - 90;
        sfCircleShape_setPosition(game->radius , rad_pos);
        sfCircleShape_setFillColor(game->radius, opacity_down);
        sfCircleShape_setRadius(game->radius , 90);
        game->on_map = 1;
        game->texture = "pictures/defences/cannon/1.png";
        my_shop->cannon = sfTexture_createFromFile(game->texture, sfFalse);
        sfSprite_setTexture(my_shop->s_cannon, my_shop->cannon, sfFalse);
        sfSprite_setColor(my_shop->s_cannon, opacity_down);
        my_shop->pos_cannon.x = pos_mouse.x - 60;
        my_shop->pos_cannon.y = pos_mouse.y - 60;
        sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
        game->take = 0;
    }
}

void get_archer(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_archer.x && pos_mouse.x <= \
my_shop->pos_archer.x + 120 && pos_mouse.y >= my_shop->pos_archer.y && \
pos_mouse.y <= my_shop->pos_archer.y + 100 && \
	sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
	rad_pos.x = pos_mouse.x - 90;
	rad_pos.y = pos_mouse.y - 90;
	sfCircleShape_setPosition(game->radius , rad_pos);
	sfCircleShape_setFillColor(game->radius, opacity_down);
	sfCircleShape_setRadius(game->radius , 90);
	game->on_map = 1;
	game->texture = "pictures/defences/archer_tower/1.png";
	my_shop->archer = sfTexture_createFromFile(game->texture, sfFalse);
	sfSprite_setTexture(my_shop->s_archer, my_shop->archer, sfFalse);
	sfSprite_setColor(my_shop->s_archer, opacity_down);
	my_shop->pos_archer.x = pos_mouse.x - 60;
	my_shop->pos_archer.y = pos_mouse.y - 60;
	sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
	game->take = 2;
    }
}

void get_mortar(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_mortar.x && pos_mouse.x <= \
my_shop->pos_mortar.x + 120 && pos_mouse.y >= my_shop->pos_mortar.y && \
pos_mouse.y <= my_shop->pos_mortar.y + 100 && \
	sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
	rad_pos.x = pos_mouse.x - 90;
	rad_pos.y = pos_mouse.y - 90;
	sfCircleShape_setPosition(game->radius , rad_pos);
	sfCircleShape_setFillColor(game->radius, opacity_down);
	sfCircleShape_setRadius(game->radius , 90);
	game->on_map = 1;
	game->texture = "pictures/defences/mortar/1.png";
	my_shop->mortar = sfTexture_createFromFile(game->texture, sfFalse);
	sfSprite_setTexture(my_shop->s_mortar, my_shop->mortar, sfFalse);
	sfSprite_setColor(my_shop->s_mortar, opacity_down);
	my_shop->pos_mortar.x = pos_mouse.x - 60;
	my_shop->pos_mortar.y = pos_mouse.y - 60;
	sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
	game->take = 3;
    }
}

void get_air_defence(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_air_defence.x && pos_mouse.x <= \
my_shop->pos_air_defence.x + 120 && pos_mouse.y >= my_shop->pos_air_defence.y && \
pos_mouse.y <= my_shop->pos_air_defence.y + 100 && \
	sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
	rad_pos.x = pos_mouse.x - 90;
	rad_pos.y = pos_mouse.y - 90;
	sfCircleShape_setPosition(game->radius , rad_pos);
	sfCircleShape_setFillColor(game->radius, opacity_down);
	sfCircleShape_setRadius(game->radius , 90);
	game->on_map = 1;
	game->texture = "pictures/defences/air_defence/1.png";
	my_shop->air_defence = sfTexture_createFromFile(game->texture, sfFalse);
	sfSprite_setTexture(my_shop->s_air_defence, my_shop->air_defence, sfFalse);
	sfSprite_setColor(my_shop->s_air_defence, opacity_down);
	my_shop->pos_air_defence.x = pos_mouse.x - 60;
	my_shop->pos_air_defence.y = pos_mouse.y - 60;
	sfSprite_setPosition(my_shop->s_air_defence, my_shop->pos_air_defence);
	game->take = 4;
    }
}

void get_xbow(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_xbow.x && pos_mouse.x <= \
my_shop->pos_xbow.x + 120 && pos_mouse.y >= my_shop->pos_xbow.y && \
pos_mouse.y <= my_shop->pos_xbow.y + 100 && \
	sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
	rad_pos.x = pos_mouse.x - 90;
	rad_pos.y = pos_mouse.y - 90;
	sfCircleShape_setPosition(game->radius , rad_pos);
	sfCircleShape_setFillColor(game->radius, opacity_down);
	sfCircleShape_setRadius(game->radius , 90);
	game->on_map = 1;
	game->texture = "pictures/defences/x_bow/1.png";
	my_shop->xbow = sfTexture_createFromFile(game->texture, sfFalse);
	sfSprite_setTexture(my_shop->s_xbow, my_shop->xbow, sfFalse);
	sfSprite_setColor(my_shop->s_xbow, opacity_down);
	my_shop->pos_xbow.x = pos_mouse.x - 60;
	my_shop->pos_xbow.y = pos_mouse.y - 60;
	sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
	game->take = 5;
    }
}

void get_wizard(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfColor opacity_down = {255 ,255, 255, 150};
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_wizard.x && pos_mouse.x <= \
my_shop->pos_wizard.x + 120 && pos_mouse.y >= my_shop->pos_wizard.y && \
pos_mouse.y <= my_shop->pos_wizard.y + 100 && \
	sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
	rad_pos.x = pos_mouse.x - 90;
	rad_pos.y = pos_mouse.y - 90;
	sfCircleShape_setPosition(game->radius , rad_pos);
	sfCircleShape_setFillColor(game->radius, opacity_down);
	sfCircleShape_setRadius(game->radius , 90);
	game->on_map = 1;
	game->texture = "pictures/defences/wizard_tower/1.png";
	my_shop->wizard = sfTexture_createFromFile(game->texture, sfFalse);
	sfSprite_setTexture(my_shop->s_wizard, my_shop->wizard, sfFalse);
	sfSprite_setColor(my_shop->s_wizard, opacity_down);
	my_shop->pos_wizard.x = pos_mouse.x - 60;
	my_shop->pos_wizard.y = pos_mouse.y - 60;
	sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
	game->take = 6;
    }
}
