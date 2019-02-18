/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** score
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "malloc.h"
#include "runner.h"

char const BASES_DECIMAL[11] = "0123456789";

int count_char(int nb)
{
    int i = 1;
    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return (i);
}

static char *end_of_string(char *str, int count, int pos)
{
    str[count] = BASES_DECIMAL[pos];
    count++;
    str[count] = '\0';
    return (str);
}

char *my_itoa(int nb, char *str)
{
    char *score;
    char *text;
    int count = 0;
    int pos;

    score = malloc(sizeof(char) * (count_char(nb) + 2));
    for (; nb > 9; count++) {
        pos = nb % 10;
        score[count] = BASES_DECIMAL[pos];
        nb = nb / 10;
    }
    pos = nb % 10;
    score = end_of_string(score, count, pos);
    score = my_revstr(score);
    text = my_strncat(str, score, -1);
    return (text);
}

void update_score(options_t *game)
{
    get_stime(game);
    if (game->s_sec > 0.2) {
        game->score++;
        sfClock_restart(game->s_clock);
    }
}