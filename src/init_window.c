/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** init_window
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

sfRenderWindow *create_my_window(sfRenderWindow *window, sfVector2f scale,
                                                                char *title)
{
    sfVideoMode video_mode = {(1280 * scale.x), (720 * scale.y), 32};

    window = sfRenderWindow_create(video_mode, title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    return (window);
}

window_t *init_wind(void)
{
    window_t *wind = malloc(sizeof(window_t));

    wind->scale.x = 1;
    wind->scale.y = 1;
    wind->window = create_my_window(wind->window, wind->scale, "My Runner");
    text_init(wind);
    return (wind);
}