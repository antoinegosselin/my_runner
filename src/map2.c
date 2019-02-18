/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** map2
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

game_obj_t **fill_objects2(window_t *wind, game_obj_t **objects, map_t *map,
                                                                int **params)
{
    if (map->map[map->lines - 2][((*params)[I])] == '3') {
        objects[((*params)[OBJ])] = create_object("files/spikes.png",
            (sfVector2f){((*params)[X]), 524 * wind->scale.y}, 4, wind->scale);
        objects[((*params)[OBJ])]->type = 3;
        ((*params)[OBJ])++;
        ((*params)[X]) += (126 * wind->scale.x);
        ((*params)[MOVES])++;
    }
    if (map->map[map->lines - 2][((*params)[I])] == 'W') {
        objects[((*params)[OBJ])] = create_object("files/chest.png",
            (sfVector2f){((*params)[X]), 452 * wind->scale.y}, 4, wind->scale);
        objects[((*params)[OBJ])]->type = 4;
        ((*params)[OBJ])++;
        ((*params)[X]) += (130 * wind->scale.x);
        ((*params)[MOVES])++;
    }
    return (objects);
}

int *init_params(void)
{
    int *params = malloc(sizeof(int) * 4);

    params[I] = 0;
    params[MOVES] = 0;
    params[X] = 500;
    params[OBJ] = 13;
    return (params);
}

game_obj_t **fill_objects(window_t *wind, game_obj_t **objects, map_t *map)
{
    int *params = init_params();

    for (; map->map[map->lines - 1][params[I]] != '\0'; params[I]++) {
        params[MOVES] = 0;
        if (map->map[map->lines - 2][params[I]] == '2') {
            objects[params[OBJ]] = create_object("files/stone.png",
                (sfVector2f){params[X], 490 * wind->scale.y}, 4, wind->scale);
            objects[params[OBJ]]->type = 2;
            params[OBJ]++;
            params[X] += (90 * wind->scale.x);
            params[MOVES]++;
        }
        objects = fill_objects2(wind, objects, map, &params);
        if (params[MOVES] == 0)
            params[X] += (100 * wind->scale.x);
    }
    free(params);
    return (objects);
}

int get_nb_obj(map_t *map)
{
    int nb_obj = 0;

    for (int i = 0; i < map->lines; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            nb_obj = (map->map[i][j] == '2') ? nb_obj + 1 : nb_obj;
            nb_obj = (map->map[i][j] == '3') ? nb_obj + 1 : nb_obj;
            nb_obj = (map->map[i][j] == 'W') ? nb_obj + 1 : nb_obj;
        }
    }
    return (nb_obj);
}