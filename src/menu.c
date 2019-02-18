/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** menu
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

options_t *click_event(window_t *wind, sfEvent click, options_t *game)
{
    int m_x = click.mouseButton.x;
    int m_y = click.mouseButton.y;

    if ((m_x >= 935) && (m_x <= 1135) && (m_y >= 205) && (m_y <= 273)) {
        sfRenderWindow_setMouseCursorVisible(wind->window, sfFalse);
        my_runner(wind, game);
    }
    if ((m_x >= 925) && (m_x <= 1120) && (m_y >= 433) && (m_y <= 503))
        sfRenderWindow_close(wind->window);
    if ((m_x >= 935) && (m_x <= 1170) && (m_y >= 320) && (m_y <= 387))
        game = select_level(wind, game);
    if ((m_x >= 1220) && (m_x <= 1280) && (m_y >= 665) && (m_y <= 720))
        game->music = set_music(game);
    return (game);
}

options_t *analyze_menu_event(window_t *wind, sfEvent event, options_t *game)
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
            game = click_event(wind, event, game);
    return (game);
}

void print_menu(sfRenderWindow *window, options_t *game)
{
    if (game->music == 1)
        sfRenderWindow_drawSprite(window, game->graphics[MENU]->sprite, NULL);
    if (game->music == 0)
        sfRenderWindow_drawSprite(window,
        game->graphics[MENUM]->sprite, NULL);
}

void set_menu(window_t *wind, options_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wind->window)) {
        sfRenderWindow_setMouseCursorVisible(wind->window, sfTrue);
        sfRenderWindow_clear(wind->window, sfBlack);
        print_menu(wind->window, game);
        print_score_m(wind->window, game);
        sfRenderWindow_display(wind->window);
        while (sfRenderWindow_pollEvent(wind->window, &event))
            game = analyze_menu_event(wind, event, game);
    }
}