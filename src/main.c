/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int setup_new_highscore(int score, char *path)
{
    int fp;
    char *highscore = my_itoa_f(score);
    int nb_char = count_char(score);
    int ret_val;

    fp = open(path, O_WRONLY);
    if (fp == -1)
        return (-1);
    ret_val = write(fp, highscore, nb_char);
    if (ret_val == -1)
        return (-1);
    close(fp);
    return (0);
}

void out_conditions(window_t *wind, options_t *game)
{
    if (game->win == 1)
        win(wind, game);
    if (game->lose == 1) {
        sfSound_play(game->sound);
        lose(wind, game);
    }
}

int my_runner(window_t *wind, options_t *game)
{
    game_obj_t **objects;

    game = initialize_options(game);
    if (game->error == 84) {
        sfRenderWindow_close(wind->window);
        return (84);
    }
    objects = init_struct(wind, game);
    while (sfRenderWindow_isOpen(wind->window)) {
        choose_move(game, objects, wind);
        print_all(wind, objects, game);
        print_score(wind->window, game);
        sfRenderWindow_display(wind->window);
        move_all(wind, objects, game);
        while (sfRenderWindow_pollEvent(wind->window, &wind->event))
            analyze_events(wind, wind->event, game);
        check_hitbox(objects, game->jump, game);
        out_conditions(wind, game);
    }
    return (destroy_objects(objects, game));
}

int main(int ac, char **av)
{
    window_t *wind;
    options_t *game;
    int ret_val;

    if (ac != 2)
        return (84);
    ret_val = check_flag(av);
    if (ret_val != 1)
        return (ret_val);
    wind = init_wind();
    game = start_options(av[1], wind);
    if (game->error == 84)
        return (84);
    while (sfRenderWindow_isOpen(wind->window))
        set_menu(wind, game);
    sfRenderWindow_destroy(wind->window);
    sfText_destroy(wind->FPS);
    destroy_game(game);
    return (0);
}