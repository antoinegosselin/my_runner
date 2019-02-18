/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** init_graphics
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

hud_t *init_graph(char *filepath, sfVector2f pos, sfVector2f scale)
{
    hud_t *graph = malloc(sizeof(hud_t));

    graph->texture = sfTexture_createFromFile(filepath, NULL);
    graph->sprite = sfSprite_create();
    graph->pos = pos;
    sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
    sfSprite_setScale(graph->sprite, scale);
    return (graph);
}

hud_t **init_graphics(window_t *wind)
{
    hud_t **graphics = malloc(sizeof(hud_t *) * 6);

    graphics[0] = init_graph("files/menu.png",
                        (sfVector2f){0, 0}, wind->scale);
    graphics[1] = init_graph("files/menum.png",
                        (sfVector2f){0, 0}, wind->scale);
    graphics[2] = init_graph("files/pause.png",
                        (sfVector2f){0, 0}, wind->scale);
    graphics[3] = init_graph("files/level.png",
                        (sfVector2f){0, 0}, wind->scale);
    graphics[4] = init_graph("files/lose.png",
                        (sfVector2f){0, 0}, wind->scale);
    graphics[5] = init_graph("files/win.png",
                        (sfVector2f){0, 0}, wind->scale);
    return (graphics);
}