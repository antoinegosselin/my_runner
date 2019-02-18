/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** move
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

void move_char(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= (max_value - offset))
        rect->left = 0;
    else
        rect->left = rect->left + offset;
}

void move_all(window_t *wind, game_obj_t **objects, options_t *game)
{
    if (game->pause == 1)
        return;
    for (int i = 0; i < 11; i++) {
        objects[i]->pos.x -= objects[i]->speed;
        if (objects[i]->pos.x <= (-1908 * wind->scale.x) && i < 11)
            objects[i]->pos.x += (1908 * wind->scale.x);
        sfSprite_setPosition(objects[i]->sprite, objects[i]->pos);
    }
    for (int j = 13; j < (13 + game->map->enemies); j++) {
        objects[j]->pos.x -= objects[j]->speed;
        sfSprite_setPosition(objects[j]->sprite, objects[j]->pos);
    }
}

void move_jump(options_t *game, game_obj_t **objects, window_t *wind)
{
    move_char(&objects[12]->rect, (MOVE_VAL[game->jump]).offset, 520);
    objects[12]->pos.x += (MOVE_VAL[game->jump].move_x *
                                                wind->scale.x);
    objects[12]->pos.y += (MOVE_VAL[game->jump].move_y *
                                                wind->scale.x);
}

void choose_move(options_t *game, game_obj_t **objects, window_t *wind)
{
    if (game->pause == 1)
        return;
    get_time(game);
    if (game->jump == 0) {
        if (game->seconds > 0.1) {
            move_char(&objects[11]->rect, 46, 368);
            sfClock_restart(game->clock);
        }
    } else {
        if (game->seconds > (MOVE_VAL[game->jump]).time) {
            move_jump(game, objects, wind);
            game->jump++;
        }
    }
    if (game->jump == 31) {
        game->jump = 0;
        sfClock_restart(game->clock);
    }
}