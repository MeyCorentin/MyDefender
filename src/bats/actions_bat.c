/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to check action of bats
*/

#include "../../includes/my_defender.h"

int is_only(global *game, int num)
{
    char *number = "023456";

    for (int cmpt = 0; number[cmpt] != '\0'; cmpt += 1) {
        if (game->boole->take == number[cmpt] - 48 && game->boole->take \
		!= num)
            return (1);
    }
    return (0);
}

void destroy_struct(global *game, batiment *bat)
{
    batiment *temp = malloc(sizeof(batiment));
    batiment *prev = malloc(sizeof(batiment));

    temp = bat;
    prev = bat->prev;
    prev->next = temp->next;
    game->first->gold += bat->stats->price / 3;
    free(temp);
}

void up_struct(global *game, batiment *bat)
{
    if (bat->on_bat == 0) {
        sfSound_play(game->sounds->anvil);
        bat->stats->level += 1;
        game->first->gold -= bat->stats->price;
        bat->stats->damage *= 1.5;
        bat->stats->price *= 1.5;
        bat->stats->pv *= 1.5;
        if (bat->stats->bat_name == -1) {
            game->price_hdv = bat->stats->price;
            game->gold = bat->gold;
            game->level += 1;
            //game->menus->level += 1;
            set_texture_hdv(game, bat);
            set_texture_map(game);
        }
    }
}

void button_struct(global *game, batiment *bat_, sfVector2i pos_mouse)
{
    if (bat_->stats->level < 10 && game->first->gold >= bat_->stats->price && \
    pos_mouse.x > bat_->level_up->pos_up.x && pos_mouse.x < bat_->level_up->\
    pos_up.x + 30 && pos_mouse.y > bat_->level_up->pos_up.y && pos_mouse.y < \
    bat_->level_up->pos_up.y + 30 && game->event.type == \
    sfEvtMouseButtonReleased)
        up_struct(game, bat_);
    /* if (pos_mouse.x > bat_->level_up->pos_destroy.x && pos_mouse.x < bat_->\
    level_up->pos_destroy.x + 30 && pos_mouse.y > bat_->level_up->\
    pos_destroy.y && pos_mouse.y < bat_->level_up->pos_destroy.y + 30 && \
    game->event.type == sfEvtMouseButtonReleased)
        destroy_struct(game, bat_); */
}

void struct_event(global *game, batiment *bat_)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (game->event.type == sfEvtMouseButtonReleased && !(pos_mouse.x > bat_->\
    level_up->pos_up.x && pos_mouse.x < bat_->level_up->pos_up.x + 30 && \
    pos_mouse.y > bat_->level_up->pos_up.y && pos_mouse.y < bat_->level_up->\
    pos_up.y + 30))
        bat_->on_bat = 1;
    if (pos_mouse.x > bat_->pos.x + 30 && pos_mouse.x < bat_->pos.x + 90 && \
    pos_mouse.y > bat_->pos.y + 30 && pos_mouse.y < bat_->pos.y + 90 && game->\
    event.type == sfEvtMouseButtonReleased) {
        if (bat_->on_bat == 1 && game->secs != 5)
            bat_->on_bat = 0;
        else if (bat_->on_bat == 0)
            bat_->on_bat = 1;
    }
    button_struct(game, bat_, pos_mouse);
    if (bat_->next != NULL)
        struct_event(game, bat_->next);
}
