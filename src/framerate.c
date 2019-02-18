/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** framerate
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "runner.h"

char const BASE_DECIMAL[11] = "0123456789";

void text_init(window_t *window)
{
    window->font = sfFont_createFromFile("files/arial.ttf");
    window->FPS = sfText_create();
    sfText_setFont(window->FPS, window->font);
    sfText_setCharacterSize(window->FPS, (unsigned int){20 * window->scale.x});
    sfText_setColor(window->FPS, sfRed);
}

int count_char_f(int nb)
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
    str[count] = BASE_DECIMAL[pos];
    count++;
    str[count] = '\0';
    return (str);
}

char *my_itoa_f(int nb)
{
    char *text;
    int count = 0;
    int pos;

    text = malloc(sizeof(char) * (count_char_f(nb) + 2));
    for (; nb > 9; count++) {
        pos = nb % 10;
        text[count] = BASE_DECIMAL[pos];
        nb = nb / 10;
    }
    pos = nb % 10;
    text = end_of_string(text, count, pos);
    text = my_revstr(text);
    return (text);
}

void get_framerate(window_t *wind)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;
    char *fps_num;

    sfRenderWindow_clear(wind->window, sfBlack);
    if (first == 1) {
        clock = sfClock_create ();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        fps_num = my_itoa_f(fps);
        sfText_setString(wind->FPS, fps_num);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}