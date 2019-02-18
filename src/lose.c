/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** loose
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

void lose_event(window_t *wind, sfEvent event, options_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(wind->window);
        if (event.key.code == sfKeyM) {
            sfText_setCharacterSize(game->txt_score,
                            (unsigned int){30 * wind->scale.x});
            sfText_setColor(game->txt_score, sfBlack);
            set_menu(wind, game);
        }
    }
}

void lose(window_t *wind, options_t *game)
{
    sfEvent event;

    game->total += game->score;
    if (game->total > game->high_score)
        game->high_score = game->total;
    while (sfRenderWindow_isOpen(wind->window)) {
        sfRenderWindow_clear(wind->window, sfBlack);
        sfRenderWindow_drawSprite(wind->window,
            game->graphics[LOSE]->sprite, NULL);
        print_end(wind->window, game, (sfVector2f){645, 344});
        sfRenderWindow_display(wind->window);
        while (sfRenderWindow_pollEvent(wind->window, &event))
            lose_event(wind, event, game);
    }
}