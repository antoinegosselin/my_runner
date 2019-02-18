/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** time
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

void get_stime(options_t *game)
{
    game->s_time = sfClock_getElapsedTime(game->s_clock);
    game->s_sec = game->s_time.microseconds / 1000000.0;
}

void get_time(options_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
}