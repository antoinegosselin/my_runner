/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** text
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "malloc.h"
#include "runner.h"

void print_end(sfRenderWindow *window, options_t *game, sfVector2f pos)
{
    char *score = my_itoa_f(game->score);

    sfText_setString(game->txt_score, score);
    sfText_setColor(game->txt_score, sfRed);
    sfText_setCharacterSize(game->txt_score, (unsigned int){50});
    sfText_setPosition(game->txt_score, pos);
    sfRenderWindow_drawText(window, game->txt_score, NULL);
}

void print_score(sfRenderWindow *window, options_t *game)
{
    char *score;

    update_score(game);
    score = my_itoa(game->score, "Score: ");
    sfText_setString(game->txt_score, score);
    sfText_setPosition(game->txt_score, (sfVector2f){20, 670});
    sfRenderWindow_drawText(window, game->txt_score, NULL);
}

void print_score_m(sfRenderWindow *window, options_t *game)
{
    char *total = my_itoa(game->total, "Total: ");
    char *hscore = my_itoa(game->high_score, "High score: ");

    sfText_setString(game->txt_hscore, hscore);
    sfText_setPosition(game->txt_hscore, (sfVector2f){20, 670});
    sfRenderWindow_drawText(window, game->txt_hscore, NULL);
    sfText_setString(game->txt_total, total);
    sfText_setPosition(game->txt_total, (sfVector2f){20, 620});
    sfRenderWindow_drawText(window, game->txt_total, NULL);
}