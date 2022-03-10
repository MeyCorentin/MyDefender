/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** It's the file that contain functions to set a basic window
*/

#include "../../includes/my_defender.h"

void draw_skill_tree(global *game, chained_skill_t *skill)
{
    sfRenderWindow_drawSprite(game->window, skill->skill, sfFalse);
    if (skill->next != NULL) {
        draw_skill_tree(game, skill->next);
    }
}

void set_stats_skill(global *game, int cmpt, int level, \
chained_skill_t *new_skill)
{
    if (cmpt == 0) {
        new_skill->value = 10 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->hearth, sfFalse);
    } if (cmpt == 1) {
        new_skill->value = 2 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->sword, sfFalse);
    } if (cmpt == 2) {
        new_skill->value = 1 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->speed, sfFalse);
    } if (cmpt == 3) {
        new_skill->value = 1 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->gold, sfFalse);
    } if (cmpt == -1) {
        new_skill->value = 100;
        sfSprite_setTexture(new_skill->skill, game->tree->tree, sfFalse);
    }
}

chained_skill_t *check_prev(global *game, int cmpt)
{
    chained_skill_t *temp = game->tree->first_skill;
    chained_skill_t *last_type = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
        if (temp->type == cmpt)
            last_type = temp;
    }
    if (last_type == NULL)
        return (game->tree->first_skill);
    else
        return (last_type);
}

chained_skill_t *create_skill(global *game, int cmpt, int level)
{
    chained_skill_t *new_skill = malloc(sizeof(chained_skill_t));
    chained_skill_t *first = malloc(sizeof(chained_skill_t));
    sfColor unactive = {255, 255, 255, 150};

    if (cmpt == -1) {
        new_skill->prev = first;
        new_skill->prev->active = 0;
    } else
        new_skill->prev = check_prev(game, cmpt);
    new_skill->first = game->tree->first_skill;
    new_skill->skill = sfSprite_create();
    new_skill->next = NULL;
    new_skill->pos_skill.x = game->tree->x;
    new_skill->pos_skill.y = game->tree->y;
    new_skill->pos_skill2.x = new_skill->pos_skill.x - 14;
    new_skill->pos_skill2.y = new_skill->pos_skill.y - 14;
    new_skill->active = 1;
    if (level == -1)
        new_skill->price = 1000;
    else
        new_skill->price = 100 * (level + 1);
    set_stats_skill(game, cmpt, level, new_skill);
    sfSprite_setPosition(new_skill->skill, new_skill->pos_skill);
    new_skill->type = cmpt;
    sfSprite_setColor(new_skill->skill, unactive);
    return (new_skill);
}

chained_skill_t *get_last_skill(global *game, int cmpt, int level)
{
    chained_skill_t *temp = game->tree->first_skill;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = create_skill(game, cmpt, level);
    return (temp->next);
}

void set_texture_tree(global *game)
{
    game->tree->hearth = sfTexture_createFromFile\
    ("pictures/buttons/hearth.png", NULL);
    game->tree->tree = sfTexture_createFromFile\
    ("pictures/buttons/tree.png", NULL);
    game->tree->sword = sfTexture_createFromFile\
    ("pictures/buttons/sword.png", NULL);
    game->tree->speed = sfTexture_createFromFile\
    ("pictures/buttons/speed.png", NULL);
    game->tree->gold = sfTexture_createFromFile\
    ("pictures/buttons/gold.png", NULL);
}

void create_bonus(global *game)
{
    game->bonus = malloc(sizeof(bonus_t));
    game->bonus->all = 0;
    game->bonus->gold = 0;
    game->bonus->life = 0;
    game->bonus->speed = 0;
    game->bonus->strenght = 0;
}

void create_tree(global *game)
{
    game->tree = malloc(sizeof(skill_tree_t));
    game->tree->back = sfSprite_create();
    game->tree->t_back = sfTexture_createFromFile\
    ("pictures/buttons/leandre.png", NULL);
    set_texture_tree(game);
    sfSprite_setTexture(game->tree->back, game->tree->t_back, sfFalse);
    game->tree->x = 900;
    game->tree->y = 200;
    game->tree->first_skill = create_skill(game, -1, -1);
    game->tree->y = 300;
    game->tree->x = 150;
    for (int level = 0; level < 7; level += 1) {
        for (int cmpt = 0; cmpt < 4; cmpt += 1) {
            game->tree->x += 300;
            get_last_skill(game, cmpt, level);
        }
        game->tree->y += 100;
        game->tree->x = 150;
    }
}

void active_bonus(global *game, chained_skill_t *skill)
{
    sfColor active = {255, 255, 255, 255};

    skill->active = 0;
    sfSprite_setColor(skill->skill, active);
    game->first->gold -= skill->price;
    if (skill->type == 0)
        game->bonus->life += skill->value;
    if (skill->type == 1)
        game->bonus->strenght += skill->value;
    if (skill->type == 2)
        game->bonus->speed += skill->value;
    if (skill->type == 3)
        game->bonus->gold += skill->value;
    if (skill->type == -1)
        game->bonus->all += skill->value;
}

void check_mouse_tree(global *game, chained_skill_t *skill)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *) game->window);
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_basic = {1, 1};

    if (mouse.x > skill->pos_skill.x && mouse.x < skill->pos_skill.x + 100 \
    && mouse.y > skill->pos_skill.y && mouse.y < skill->pos_skill.y + 100 && \
    skill->active == 1) {
        sfSprite_setPosition(skill->skill, skill->pos_skill2);
        sfSprite_setScale(skill->skill, scale);
        if (game->event.type == sfEvtMouseButtonReleased && game->first->gold \
        >= skill->price && skill->prev->active == 0)
            active_bonus(game, skill);
    } else {
        sfSprite_setPosition(skill->skill, skill->pos_skill);
        sfSprite_setScale(skill->skill, scale_basic);
    }
    if (skill->next != NULL)
        check_mouse_tree(game, skill->next);
}

void event_tree(global *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if ((sfKeyboard_isKeyPressed(sfKeyT) && game->other_secs != 0) || \
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->boole->in_tree = 1;
            game->other_secs = 0;
        }
        check_mouse_tree(game, game->tree->first_skill);
    }
}

void loop_tree(global *game)
{
    game->boole->in_tree = 0;
    game->other_secs = 0;
    while (sfRenderWindow_isOpen(game->window) && game->boole->in_tree == 0) {
        sfRenderWindow_drawSprite(game->window, game->tree->back, sfFalse);
        draw_skill_tree(game, game->tree->first_skill);
        event_tree(game);
        sfRenderWindow_display(game->window);
        update_game(game);
    }
}
