/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-nathan.donat-filliod
** File description:
** make_dmg
*/

#include "../../includes/my_defender.h"

void make_dmg_archer(global *game, batiment * bat_) {
    if (bat_->target != NULL) {
        if(bat_->target->type == 2) {
            if((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size)
            || (sqrt((bat_->target->pos.x + 47- bat_->pos.x - 70) * (bat_->target->pos.x + 47 - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size)
            || (sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y  + 63- bat_->pos.y - 70)) < bat_->rad_size)
            || (sqrt((bat_->target->pos.x + 47 - bat_->pos.x - 70) * (bat_->target->pos.x + 47- bat_->pos.x - 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y +63 - bat_->pos.y - 70)) < bat_->rad_size)) {
                bat_->target->pv -= bat_->stats->damage;
            }
        }
    }
    if (bat_->next != NULL)
        make_dmg_archer(game, bat_->next);
}