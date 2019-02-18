/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** hitbox
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int test_normal(int type, sfVector2f pers, sfVector2f obs_pos,
                                                    options_t *game)
{
    if (type == 2 && (pers.x + (46 * game->scale) > obs_pos.x &&
                                pers.x < obs_pos.x + (88 * game->scale)))
        return (1);
    if (type == 3 && (pers.x + (46 * game->scale) > obs_pos.x &&
                                pers.x < obs_pos.x + (124 * game->scale)))
        return (1);
    if (type == 4 && (pers.x + (46 * game->scale) > obs_pos.x &&
                                pers.x < obs_pos.x + (128 * game->scale)))
        game->win = 1;
    return (0);
}

int test_jump(int type, sfVector2f pers, sfVector2f obs_pos,
                                                    options_t *game)
{
    if (type == 2 && (pers.x + (40 * game->scale) > obs_pos.x && pers.x <
    obs_pos.x + (88 * game->scale)) && ((pers.y + (60 * game->scale) <
    obs_pos.y + (90 * game->scale) && pers.y + (60 * game->scale) > obs_pos.y)
    || (pers.y < obs_pos.y + (90 * game->scale) && pers.y > obs_pos.y)))
        return (1);
    if (type == 3 && (pers.x + (40 * game->scale) > obs_pos.x && pers.x <
    obs_pos.x + (124 * game->scale)) && ((pers.y + (60 * game->scale) <
    obs_pos.y + (56 * game->scale) && pers.y + (60 * game->scale) > obs_pos.y)
    || (pers.y < obs_pos.y + (56 * game->scale) && pers.y > obs_pos.y)))
        return (1);
    if (type == 4 && (pers.x + (40 * game->scale) > obs_pos.x &&
    pers.x < obs_pos.x + (128 * game->scale)))
        game->win = 1;
    return (0);
}

void check_hitbox(game_obj_t **objects, int jump, options_t *game)
{
    int charac = (jump >= 1) ? 12 : 11;
    sfVector2f pers = sfSprite_getPosition(objects[charac]->sprite);
    sfVector2f obs_pos;
    int hit = 0;

    if (game->pause == 1)
        return;
    for (int i = 13; i < (13 + game->map->enemies); i++) {
        obs_pos = sfSprite_getPosition(objects[i]->sprite);
        if (charac == 11)
            hit = test_normal(objects[i]->type, pers, obs_pos, game);
        if (charac == 12)
            hit = test_jump(objects[i]->type, pers, obs_pos, game);
        if (hit == 1 && game->lose != 2)
            game->lose = 1;
    }
}