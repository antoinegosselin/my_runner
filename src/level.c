/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** level
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int level_pos(int m_x, int m_y, options_t *game)
{
    if ((m_x >= 562) && (m_x < 800) && (m_y >= 80) && (m_y < 133)) {
        game->level = 1;
        return (1);
    }
    if ((m_x >= 930) && (m_x <= 1187) && (m_y >= 80) && (m_y < 133)) {
        game->level = 2;
        return (1);
    }
    if ((m_x >= 562) && (m_x < 840) && (m_y >= 127) && (m_y <= 270)) {
        game->level = 3;
        return (1);
    }
    if ((m_x >= 930) && (m_x <= 1222) && (m_y >= 127) && (m_y <= 270)) {
        game->level = 4;
        return (1);
    }
    return (0);
}

int level_event(options_t *game, sfEvent click)
{
    int m_x = click.mouseButton.x;
    int m_y = click.mouseButton.y;

    if (click.mouseButton.button == sfMouseLeft) {
        return (level_pos(m_x, m_y, game));
    }
    return (0);
}

options_t *analyze_level_event(window_t *wind, sfEvent event, options_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyF5)
            game->music = set_music(game);
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(wind->window);
    }
    if (event.type == sfEvtMouseButtonPressed)
        if (event.mouseButton.button == sfMouseLeft)
            game->error = level_event(game, event);
    return (game);
}

void print_level(window_t *wind, options_t *game)
{
    sfRenderWindow_clear(wind->window, sfBlack);
    sfRenderWindow_drawSprite(wind->window,
        game->graphics[LEVEL]->sprite, NULL);
    sfRenderWindow_display(wind->window);
}

options_t *select_level(window_t *wind, options_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wind->window)) {
        print_level(wind, game);
        while (sfRenderWindow_pollEvent(wind->window, &event))
            analyze_level_event(wind, event, game);
        if (game->error == 1) {
            game->error = 0;
            break;
        }
    }
    return (game);
}