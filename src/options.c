/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** options
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

void txt_init(options_t *game, window_t *wind)
{
    game->txt_score = sfText_create();
    sfText_setFont(game->txt_score, wind->font);
    sfText_setCharacterSize(game->txt_score,
                        (unsigned int){30 * wind->scale.x});
    sfText_setColor(game->txt_score, sfBlack);
    game->txt_hscore = sfText_create();
    sfText_setFont(game->txt_hscore, wind->font);
    sfText_setCharacterSize(game->txt_hscore,
                        (unsigned int){30 * wind->scale.x});
    sfText_setColor(game->txt_hscore, sfRed);
    game->txt_total = sfText_create();
    sfText_setFont(game->txt_total, wind->font);
    sfText_setCharacterSize(game->txt_total,
                        (unsigned int){30 * wind->scale.x});
    sfText_setColor(game->txt_total, sfRed);
}

int get_highscore(char *path)
{
    FILE *fp;
    int highscore;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL)
        return (-1);
    read = getline(&line, &len, fp);
    if (read == -1)
        return (-1);
    highscore = my_getnbr(line);
    fclose(fp);
    return (highscore);
}

options_t *start_options(char *filepath, window_t *wind)
{
    options_t *game = malloc(sizeof(options_t));

    game->music = 0;
    game->level = 1;
    game->score = 0;
    game->total = 0;
    game->song = sfMusic_createFromFile("files/run.ogg");
    game->sound_buff = sfSoundBuffer_createFromFile("files/death.ogg");
    game->sound = sfSound_create();
    sfSound_setBuffer(game->sound, game->sound_buff);
    game->scale = 1;
    game->filepath = my_strndup(filepath, -1);
    game->high_score = get_highscore("highscore.txt");
    game->graphics = init_graphics(wind);
    if (game->high_score == -1)
        game->error = 84;
    game->music = set_music(game);
    txt_init(game, wind);
    return (game);
}

options_t *initialize_options(options_t *game)
{
    game->win = 0;
    game->lose = 0;
    game->jump = 0;
    game->error = 0;
    game->score = 0;
    game->pause = 0;
    game->map = read_map(game->filepath, game);
    if (game->map == NULL)
        game->error = 84;
    game->clock = sfClock_create();
    game->s_clock = sfClock_create();
    return (game);
}