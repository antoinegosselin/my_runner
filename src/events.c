/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** events
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int set_pause(options_t *game)
{
    if (game->pause == 0)
        game->pause = 1;
    else
        game->pause = 0;
    return (game->pause);
}

void analyze_events(window_t *wind, sfEvent event, options_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyF5)
            game->music = set_music(game);
        if (event.key.code == sfKeyM)
            set_menu(wind, game);
        if (event.key.code == sfKeyP)
            game->pause = set_pause(game);
        if (event.key.code == sfKeySpace && game->jump == 0) {
            game->jump = 1;
            sfClock_restart(game->clock);
        }
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(wind->window);
    }
}