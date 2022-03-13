/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-nathan.donat-filliod
** File description:
** make_dmg
*/

#include "../../includes/my_defender.h"

void create_shot(global *game, batiment *bat)
{
    bat->bullet->fireball = sfTexture_createFromFile\
    ("pictures/fireball.png", NULL);
    bat->bullet->t_bullet = sfTexture_createFromFile\
    ("pictures/bullet.png", NULL);
    bat->bullet->right_arrow = sfTexture_createFromFile\
    ("pictures/arrow_right.png", NULL);
    bat->bullet->left_arrow = sfTexture_createFromFile\
    ("pictures/arrow_left.png", NULL);
}

void create_bullet(global *game, batiment *bat)
{
    bat->bullet = malloc(sizeof(bullet_t));
    bat->bullet->bullet = sfSprite_create();
    create_shot(game, bat);
    if (bat->stats->bat_name == 1 || bat->stats->bat_name == 3)
        sfSprite_setTexture(bat->bullet->bullet, bat->bullet->t_bullet, sfFalse);
    else if (bat->stats->bat_name == 6)
        sfSprite_setTexture(bat->bullet->bullet, bat->bullet->fireball, sfFalse);
    else
        sfSprite_setTexture(bat->bullet->bullet, bat->bullet->right_arrow, sfFalse);
    bat->bullet->pos_bullet.x = bat->pos.x + 50;
    bat->bullet->pos_bullet.y = bat->pos.y + 50;
    sfSprite_setPosition(bat->bullet->bullet, bat->bullet->pos_bullet);
    bat->bullet->shot = 1;
}

void set_texture_in(global *game, batiment *bat)
{
    if (bat->stats->bat_name == 2 || bat->stats->bat_name == 3 || bat->stats->bat_name == 4 || bat->stats->bat_name == 5) {
        if (bat->bullet->pos_bullet.x < bat->target->pos.x)
            sfSprite_setTexture(bat->bullet->bullet, bat->bullet->right_arrow, sfFalse);
        if (bat->bullet->pos_bullet.x > bat->target->pos.x)
            sfSprite_setTexture(bat->bullet->bullet, bat->bullet->left_arrow, sfFalse);
    }
}

void update_bullet(global *game, batiment *bat)
{
    if (bat->bullet->shot == 0) {
        set_texture_in(game, bat);
        if ((bat->bullet->pos_bullet.x + 24 > bat->target->pos.x && bat->bullet->pos_bullet.x < bat->target->pos.x + 47 && \
        bat->bullet->pos_bullet.y + 23 > bat->target->pos.y && bat->bullet->pos_bullet.y < bat->target->pos.y + 70) || (bat->target->pv <= 0 && game->secs < 150)) {
            bat->bullet->pos_bullet.x = bat->pos.x + 50;
            bat->bullet->pos_bullet.y = bat->pos.y + 50;
            sfSprite_setPosition(bat->bullet->bullet, bat->bullet->pos_bullet);
            bat->bullet->shot = 1;
        }
        if (bat->bullet->shot == 0) {
            if (bat->bullet->pos_bullet.x < bat->target->pos.x + 20)
                bat->bullet->pos_bullet.x += 3;
            else
                bat->bullet->pos_bullet.x -= 3;
            if (bat->bullet->pos_bullet.y < bat->target->pos.y + 20)
                bat->bullet->pos_bullet.y += 3;
            else
                bat->bullet->pos_bullet.y -= 3;
            sfSprite_setPosition(bat->bullet->bullet, bat->bullet->pos_bullet);
            sfRenderWindow_drawSprite(game->window, bat->bullet->bullet, sfFalse);
        }
    }
    if (bat->next != NULL)
        update_bullet(game, bat->next);
}

void make_dmg_archer(global *game, batiment *bat_)
{
    if (bat_->type != 9 && bat_->target != NULL) {
        if (bat_->target->type == 2) {
            if ((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size)
            || (sqrt((bat_->target->pos.x + 47 - bat_->pos.x - 70) * (bat_->target->pos.x + 47 - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size)
            || (sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y + 63 - bat_->pos.y - 70)) < bat_->rad_size)
            || (sqrt((bat_->target->pos.x + 47 - bat_->pos.x - 70) * (bat_->target->pos.x + 47 - bat_->pos.x - 70) + (bat_->target->pos.y + 63 - bat_->pos.y - 70) * (bat_->target->pos.y + 63 - bat_->pos.y - 70)) < bat_->rad_size)) {
                bat_->target->pv -= bat_->stats->damage;
                sfClock_restart(game->clock);
                bat_->bullet->shot = 0;
            }
        }
    }
    if (bat_->next != NULL)
        make_dmg_archer(game, bat_->next);
}
