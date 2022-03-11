/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that draw all in game
*/

#include "../../includes/my_defender.h"

void detect_enemy(global *game, struct enemy_ *enemy, batiment *bat_)
{   
    if(enemy->type == 2) {
        if (((sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->pos.x- 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - bat_->pos.y - 70)) <= bat_->rad_size) ||
            (sqrt((enemy->pos.x + 47 - bat_->pos.x - 70) * (enemy->pos.x + 47 - bat_->pos.x- 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - bat_->pos.y - 70)) <= bat_->rad_size) ||
            (sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->pos.x- 70) + (enemy->pos.y + 63 - bat_->pos.y - 70) * (enemy->pos.y + 63 - bat_->pos.y - 70)) <= bat_->rad_size) ||
            (sqrt((enemy->pos.x + 47 - bat_->pos.x - 70) * (enemy->pos.x + 47 - bat_->pos.x- 70) + (enemy->pos.y + 63- bat_->pos.y - 70) * (enemy->pos.y  + 63- bat_->pos.y - 70)) <= bat_->rad_size))
            && bat_->target == NULL)
            bat_->target = enemy;
        if (((sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->pos.x- 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - bat_->pos.y - 70)) <= bat_->rad_size) ||
            (sqrt((enemy->pos.x + 47 - bat_->pos.x - 70) * (enemy->pos.x + 47 - bat_->pos.x- 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - bat_->pos.y - 70)) <= bat_->rad_size) ||
            (sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->pos.x- 70) + (enemy->pos.y + 63 - bat_->pos.y - 70) * (enemy->pos.y + 63 - bat_->pos.y - 70)) <= bat_->rad_size) ||
            (sqrt((enemy->pos.x + 47 - bat_->pos.x - 70) * (enemy->pos.x + 47 - bat_->pos.x- 70) + (enemy->pos.y + 63- bat_->pos.y - 70) * (enemy->pos.y  + 63- bat_->pos.y - 70)) <= bat_->rad_size)) &&
            ((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x- 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) > bat_->rad_size) &&
            (sqrt((bat_->target->pos.x + 47 - bat_->pos.x - 70) * (bat_->target->pos.x + 47 - bat_->pos.x- 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) > bat_->rad_size) &&
            (sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x- 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y + 63 - bat_->pos.y - 70)) > bat_->rad_size) &&
            (sqrt((bat_->target->pos.x + 47 - bat_->pos.x - 70) * (bat_->target->pos.x + 47 - bat_->pos.x- 70) + (bat_->target->pos.y + 63- bat_->pos.y - 70) * (bat_->target->pos.y  + 63- bat_->pos.y - 70)) > bat_->rad_size)))
            bat_->target = enemy;
    }
    if (enemy->enemy_next!= NULL)
        detect_enemy(game, enemy->enemy_next, bat_);
}

void check_hit(global *game, batiment *bat_)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfColor color = {0, 255, 0, 150};
    sfColor color2 = {0, 0, 255, 150};

    if (bat_->type != 9 && game->rad_god == 1) {
        if (sqrt((pos_mouse.x - bat_->pos.x - 70) * (pos_mouse.x - bat_->\
        pos.x - 70) + (pos_mouse.y - bat_->pos.y - 70) * (pos_mouse.y - bat_->\
        pos.y - 70)) < bat_->rad_size)
            sfCircleShape_setFillColor(bat_->radius, color);
        detect_enemy(game, game->enemy, bat_);
        if (bat_->target != NULL) {
            if(bat_->target->type == 2) {
                if((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size)
                || (sqrt((bat_->target->pos.x + 47- bat_->pos.x - 70) * (bat_->target->pos.x + 47 - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size)
                || (sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y  + 63- bat_->pos.y - 70)) < bat_->rad_size)
                || (sqrt((bat_->target->pos.x + 47 - bat_->pos.x - 70) * (bat_->target->pos.x + 47- bat_->pos.x - 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y +63 - bat_->pos.y - 70)) < bat_->rad_size))
                sfCircleShape_setFillColor(bat_->radius, color2);
            }
        }
        sfRenderWindow_drawCircleShape(game->window, bat_->radius, NULL);
    }
    if (bat_->next != NULL)
        check_hit(game, bat_->next);
}