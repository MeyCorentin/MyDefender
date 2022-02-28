/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the .h of my project "my_defender"
*/

#ifndef MY_DEFENDER_H_
    #define MY_DEFENDER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my.h"
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct sounds {
    sfSoundBuffer *music;
    sfSound *ambiance;
    int is_playing;
    sfSoundBuffer *b_anvil;
    sfSound *anvil;
    sfSoundBuffer *b_click;
    sfSound *click;
} sounds;

typedef struct grid_cell {
    int g_pos;
    int l_pos;
    int status;
    int test;
    sfCircleShape * c_1;
    sfCircleShape * c_2;
    sfCircleShape * c_3;
    sfCircleShape * c_4;
    sfCircleShape * c_5;
    sfVector2f p_3;
    sfVector2f p_5;
    int dx;
    int dy;
    struct grid_cell *first_cell;
    struct grid_cell *prev_cell;
    struct grid_cell *next_cell;
    int count;
}grid_cell;

typedef struct batiment {
    struct batiment *first;
    struct batiment *next;
    struct batiment *prev;
    struct batiment *last;
    int type;
    int status;
    int pv;
    int level;
    float damage;
    int price;
    float range;
    float attack_speed;
    int gold;
    sfSprite *bat;
    sfTexture *t_bat;
    sfVector2f pos;
} batiment;

typedef struct shop {
    sfSprite *button;
    sfTexture *open;
    sfTexture *close;
    sfVector2f pos_button_close;
    sfVector2f pos_button_open;
    sfSprite *s_cannon;
    sfTexture *t_cannon;
    sfSprite *s_archer;
    sfTexture *t_archer;
    sfSprite *s_mortar;
    sfTexture *t_mortar;
    sfSprite *s_air_defence;
    sfTexture *t_air_defence;
    sfSprite *s_xbow;
    sfTexture *t_xbow;
    sfSprite *s_wizard;
    sfTexture *t_wizard;
    sfVector2f pos_cannon;
    sfVector2f pos_archer;
    sfVector2f pos_mortar;
    sfVector2f pos_air_defence;
    sfVector2f pos_xbow;
    sfVector2f pos_wizard;
    int snap;
    sfTexture *cannon;
} shop;

typedef struct menu {
    int level;
    sfSprite *music;
    sfSprite *sounds;
    sfTexture *m_on;
    sfTexture *m_off;
    sfTexture *s_on;
    sfTexture *s_off;
    sfVector2f pos_music;
    sfVector2f pos_sounds;
    sfSprite *restart;
    sfTexture *t_battle;
    sfSprite *quit;
    sfTexture *t_quit;
    sfSprite *map;
    sfTexture *t_map;
    sfSprite *continu;
    sfVector2f pos_continu;
    sfVector2f pos_restart;
    sfVector2f pos_quit;
    sfVector2f pos2_quit;
    sfVector2f pos_map;
    sfText *c_continu;
    sfText *c_restart;
    sfFont *supercell;
    sfVector2f pos_con;
    sfVector2f pos_res;
    sfSprite *background;
    sfTexture *t_background;
} menu;

typedef struct menu_pause {
    sfSprite *music;
    sfSprite *sounds;
    sfSprite *back;
    sfSprite *quit;
    sfSprite *continu;
    sfSprite *restart;
    sfTexture *t_back;
    sfTexture *button;
    sfText *c_quit;
    sfText *c_continu;
    sfText *c_restart;
    sfVector2f pos_c_con;
    sfVector2f pos_c_res;
    sfVector2f pos_c_quit;
    sfVector2f pos_back;
    sfVector2f pos_con;
    sfVector2f pos_res;
    sfVector2f pos_quit;
    sfVector2f pos_music;
    sfVector2f pos_sounds;
    sfText *text;
    sfVector2f pos_text;
} menu_pause;

typedef struct global {
    sfRenderWindow *window;
    sfCircleShape * radius;
    sfEvent event;
    int shop_is_open;
    int pause_is_open;
    int level;
    sfSprite *map;
    sfTexture *t_map;
    batiment *first;
    sounds *sounds;
    menu_pause *pause;
    menu *menus;
    int god;
    int rad_god;
    sfClock *clock;
    sfTime time;
    int secs;
    int take;
    char *texture;
    sfVector2f p_5;
    int is_sounds;
    int is_music;
    int on_map;
} global;

void open_shop(global *game, shop *my_shop);
shop *create_shop(void);
void draw_menu(global *game, menu *menus);
menu *create_menu(int level);
void start_game(global *game);
void check_button_quit(global *game, menu *menus);
void set_minimap(menu *menus);
batiment *create_hdv(global *game);
void update_game(global *game);
void set_texture_map(global *game);
batiment *add_bat(global *game, batiment *prev, sfVector2f pos);
void set_music(global *game);
void set_sounds_buttons(global *game, menu *menus);
void check_sounds(global *game, menu *menus, sfVector2i mouse);
void check_music(global *game, menu *menus, sfVector2i mouse);
void create_pause(global *game);
void draw_pause(global *game);
void in_pause(global *game);
void set_menu(global *game);
void check_sounds_pause(global *game, sfVector2i mouse);
void check_music_pause(global *game, sfVector2i mouse);
void set_pos_buttons(global *game);
void set_pos_sounds(global *game);
void set_pos_text(global *game);
void create_window(int level);
void check_pause_event(global *game);
void set_game(global *game);
void draw_cell(global *game, grid_cell * new, shop * my_shop);
void draw_game(global *game, shop *my_shop);
void draw_structs(global *game);
batiment *get_last(global *game, sfVector2f pos);
void shop_event(global *game, shop *my_shop);
void click_shop(global *game, shop *my_shop);
void check_shop(global *game, shop *my_shop);
grid_cell *make_grid(global *game , grid_cell * grid_cell_ , shop * my_shop);
grid_cell init_cell(global *game , grid_cell grid_cell_ , shop * my_shop);
void add_cell_status(global *game, grid_cell * new, shop * my_shop);

#endif /* MY_DEFENDER_H_ */
