/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** map
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "runner.h"

int get_nb_lines(FILE *fp)
{
    int lines = 0;
    char buf[1];

    fread(buf, sizeof(char), 1, fp);
    while (buf[0] != '\n' && buf[0] != '\0') {
        lines = (lines * 10) + (buf[0] - 48);
        fread(buf, sizeof(char), 1, fp);
    }
    printf("lines: %d\n", lines);
    return (lines);
}

char **fill_map(FILE *fp, int lines, char **map)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    for (int i = 0; i < lines; i++) {
        read = getline(&line, &len, fp);
        map[i] = malloc(sizeof(char) * read);
        if (map[i] == NULL)
            return (EXIT_MALLOC);
        map[i] = my_strndup(line, -1);
    }
    free(line);
    return (map);
}

char *get_map(char *filepath, int level)
{
    char *map;

    if (level == 1)
        map = my_strncat(filepath, "level1", -1);
    if (level == 2)
        map = my_strncat(filepath, "level2", -1);
    if (level == 3)
        map = my_strncat(filepath, "level3", -1);
    if (level == 4)
        map = my_strncat(filepath, "level4", -1);
    return (map);
}

map_t *read_map(char *filepath, options_t *game)
{
    FILE *fp;
    map_t *map = malloc(sizeof(map_t));
    char *my_map = get_map(filepath, game->level);

    fp = fopen(my_map, "r");
    if (fp == NULL) {
        my_putstr_error("Error: Can't open the map\n");
        return (EXIT_OPEN);
    }
    map->lines = get_nb_lines(fp);
    map->map = malloc(sizeof(char *) * map->lines);
    if (map->map == NULL) {
        fclose(fp);
        return (EXIT_MALLOC);
    }
    map->map = fill_map(fp, map->lines, map->map);
    fclose(fp);
    map->enemies = get_nb_obj(map);
    return (map);
}

void my_put_map(map_t *map)
{
    for (int i = 0; i < map->lines; i++)
        my_putstr(map->map[i]);
}