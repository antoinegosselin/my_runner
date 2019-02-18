/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** runner
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>

#ifndef RUNNER_H
#define RUNNER_H

#define EXIT_MALLOC NULL
#define EXIT_OPEN NULL

enum {I, MOVES, X, OBJ};
enum {MENU, MENUM, PAUSE, LEVEL, LOSE, WIN};
typedef struct game_object_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    float speed;
    void *ptr_move;
    int size_x;
    int size_y;
    int type;
} game_obj_t;
typedef struct window_s
{
    sfRenderWindow *window;
    sfVector2f scale;
    sfEvent event;
    sfFont *font;
    sfText *FPS;
} window_t;
typedef struct map_s
{
    int lines;
    int enemies;
    char **map;
} map_t;
typedef struct hud_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} hud_t;
typedef struct settings
{
    int music;
    int level;
    int score;
    int high_score;
    int total;
    int jump;
    int error;
    sfMusic *song;
    sfSound *sound;
    sfSoundBuffer *sound_buff;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    sfText *txt_score;
    sfText *txt_hscore;
    sfText *txt_total;
    sfClock *s_clock;
    sfTime s_time;
    float s_sec;
    float seconds;
    int win;
    int lose;
    int pause;
    int scale;
    char *filepath;
    map_t *map;
    hud_t **graphics;
} options_t;

//flags gestion
void print_usage(void);
void print_credits(void);
int check_flag(char **av);

//init
int count_char(int nb);
window_t *init_wind(void);
int get_nb_obj(map_t *map);
int get_nb_lines(FILE *fp);
int set_music(options_t *game);
void text_init(window_t *window);
int get_highscore(char *path);
hud_t **init_graphics(window_t *wind);
options_t *start_options(char *filepath, window_t *wind);
int setup_new_highscore(int score, char *path);
map_t *read_map(char *filepath, options_t *game);
game_obj_t **init_struct(window_t *wind, options_t *game);
game_obj_t **init_struct_two(window_t *wind, game_obj_t **objects,
                                                    options_t *game);
game_obj_t **fill_objects(window_t *wind, game_obj_t **objects, map_t *map);
options_t *initialize_options(options_t *game);
char **fill_map(FILE *fp, int lines, char **map);
sfIntRect initialize_rect_char(int width, int height);
sfIntRect initialize_rect(int width, int height);
game_obj_t *create_object(const char *path, sfVector2f pos, float speed,
                                                        sfVector2f scale);
sfRenderWindow *create_my_window(sfRenderWindow *window, sfVector2f scale,
                                                                char *title);

//display
void my_put_map(map_t *map);
void print_pause(window_t *wind, options_t *game);
void print_object(window_t *wind, game_obj_t *object);
void print_char(window_t *wind, game_obj_t *object, float scale);
void print_all(window_t *wind, game_obj_t **objects, options_t *game);

//move
void move_duck(void);
void choose_move(options_t *game, game_obj_t **objects, window_t *wind);
void move_char(sfIntRect *rect, int offset, int max_value);
void move_all(window_t *wind, game_obj_t **objects, options_t *game);

int set_pause(options_t *game);
void get_time(options_t *game);
void get_framerate (window_t *window);
int my_runner(window_t *wind, options_t *game);
void check_hitbox(game_obj_t **objects, int jump, options_t *game);
int destroy_objects(game_obj_t **obj, options_t *game);
void analyze_events(window_t *wind, sfEvent event, options_t *game);
int destroy_game(options_t *game);
char *my_itoa_f(int nb);
options_t *select_level(window_t *wind, options_t *game);
void print_level(window_t *wind, options_t *game);
options_t *analyze_level_event(window_t *wind, sfEvent event,
                                                options_t *game);
int level_event(options_t *game, sfEvent click);
void set_menu(window_t *wind, options_t *game);
void print_menu(sfRenderWindow *window, options_t *game);
options_t *analyze_menu_event(window_t *wind, sfEvent event, options_t *game);
options_t *click_event(window_t *wind, sfEvent click, options_t *game);
void lose_event(window_t *wind, sfEvent event, options_t *game);
void lose(window_t *wind, options_t *game);
void win_event(window_t *wind, sfEvent event, options_t *game);
void win(window_t *wind, options_t *game);
char *my_itoa(int nb, char *str);
void print_score(sfRenderWindow *window, options_t *game);
void print_score_m(sfRenderWindow *window, options_t *game);
void print_end(sfRenderWindow *window, options_t *game, sfVector2f pos);
void get_stime(options_t *game);
void update_score(options_t *game);

typedef struct move_s {
    float time;
    int offset;
    int move_y;
    int move_x;
} move_t;

extern const move_t MOVE_VAL[31];

#endif //RUNNER_H
