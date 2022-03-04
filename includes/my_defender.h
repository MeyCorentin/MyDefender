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
    #include <stdio.h>

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
    sfSprite* ground;
    int g_pos;
    int l_pos;
    int status;
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
}grid_cell;

typedef struct level_up {
    sfSprite *up;
    sfSprite *destroy;
    sfTexture *t_up;
    sfTexture *t_destroy;
    sfVector2f pos_up;
    sfVector2f pos_destroy;
    sfText *cost;
    sfVector2f pos_cost;
} level_up;

typedef struct stats_bat {
    int pv;
    float damage;
    int price;
    float attack_speed;
    char *name;
} stats_bat;

typedef struct batiment {
    struct batiment *first;
    struct batiment *next;
    struct batiment *prev;
    struct batiment *last;
    stats_bat *stats;
    level_up *level_up;
    sfCircleShape *radius;
    sfVector2f rad_pos;
    int rad_size;
    int type;
    int status;
    int level;
    float range;
    int gold;
    sfSprite *bat;
    sfTexture *t_bat;
    sfVector2f pos;
    char *temp;
    sfText * level_str;
    sfVector2f pos_level;
    int on_bat;
    int name;
} batiment;

typedef struct mouse {
    int is_cannon;
    int is_archer;
    int is_mortar;
    int is_air;
    int is_xbow;
    int is_wizard;
} mouse_t;

typedef struct stat_shop {
    sfSprite *cannon;
    sfSprite *archer;
    sfSprite *mortar;
    sfSprite *air;
    sfSprite *xbow;
    sfSprite *wizard;
    sfTexture *t_cannon;
    sfTexture *t_archer;
    sfTexture *t_mortar;
    sfTexture *t_air;
    sfTexture *t_xbow;
    sfTexture *t_wizard;
    sfVector2f pos_cannon;
    sfVector2f pos_archer;
    sfVector2f pos_mortar;
    sfVector2f pos_air;
    sfVector2f pos_xbow;
    sfVector2f pos_wizard;
    mouse_t *mouse;
} stat_shop;

typedef struct shop {
    stat_shop *stats;
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
    sfTexture *archer;
    sfTexture *mortar;
    sfTexture *air_defence;
    sfTexture *xbow;
    sfTexture *wizard;
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

typedef struct gold {
    sfText *money;
    sfText *number;
    sfVector2f pos_money;
    sfVector2f pos_number;
    char *temp;
} gold;

typedef struct enemy_ {
    struct enemy_ *enemy_first;
    sfSprite *enemy_1;
    sfVector2f pos;
    sfTexture *texture;
    struct enemy_ *enemy_next;
    int number;
    sfVector2f direct;
}enemy_;

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
    gold *gold_gestion;
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
    sfVector2f pos_free;
    char **path_way;
    char *total_path;
    int path_nbr;
    int click;
    int take_pos;
    int on_bat;
    int unground;
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
batiment *add_bat(global *game, batiment *prev, sfVector2f pos, int name);
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
void draw_game(global *game, shop *my_shop, grid_cell grid_cell);
void draw_structs(global *game, batiment *bat);
batiment *get_last(global *game, sfVector2f pos, int name);
void shop_event(global *game, shop *my_shop);
void click_shop(global *game, shop *my_shop);
void check_shop(global *game, shop *my_shop);
grid_cell *make_grid(global *game , grid_cell * grid_cell_ , shop * my_shop);
grid_cell init_cell(global *game , grid_cell grid_cell_ , shop * my_shop);
void add_cell_status(global *game, grid_cell * new, shop * my_shop, FILE* output_file);
void drop_cannon(global *game, shop *my_shop);
void drop_archer(global *game, shop *my_shop);
void drop_mortar(global *game, shop *my_shop);
void drop_air_defence(global *game, shop *my_shop);
void drop_xbow(global *game, shop *my_shop);
void drop_wizard(global *game, shop *my_shop);
void get_cannon(global *game, shop *my_shop);
void get_archer(global *game, shop *my_shop);
void get_mortar(global *game, shop *my_shop);
void get_air_defence(global *game, shop *my_shop);
void get_xbow(global *game, shop *my_shop);
void get_wizard(global *game, shop *my_shop);
void draw_rad(global *game, batiment * bat_);
void check_hit(global *game, batiment * bat_);
void read_path(global *game);
void update_gold(global *game);
void create_gold(global *game);
int is_only(global *game, int num);
void struct_event(global *game, batiment *bat_);
void check_name(global *game, int name, batiment *bat);
void set_stats_hdv(global *game, batiment *bat);
void draw_ground(global *game , struct grid_cell *new, shop * my_shop);
void place_struct(global *game, struct grid_cell *new, shop *my_shop);
void up_struct(global *game, batiment *bat);
void destroy_struct(global *game, batiment *bat);
void set_texture_hdv(global *game, batiment *hdv);
void create_path(global *game, grid_cell *new, shop *my_shop);

#endif /* MY_DEFENDER_H_ */
