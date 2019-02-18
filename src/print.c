/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** print
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

void print_char(window_t *wind, game_obj_t *object, float scale)
{
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setScale(object->sprite,
(sfVector2f){(1.5 * scale * wind->scale.x), (1.5 * scale * wind->scale.y)});
    sfSprite_setPosition(object->sprite, object->pos);
    sfRenderWindow_drawSprite(wind->window, object->sprite, NULL);
}

void print_object(window_t *wind, game_obj_t *object)
{
    sfSprite_setPosition(object->sprite, object->pos);
    sfRenderWindow_drawSprite(wind->window, object->sprite, NULL);
}

void print_pause(window_t *wind, options_t *game)
{
    sfSprite_setPosition(game->graphics[PAUSE]->sprite,
                                    game->graphics[PAUSE]->pos);
    sfRenderWindow_drawSprite(wind->window,
                            game->graphics[PAUSE]->sprite , NULL);
}

void print_all(window_t *wind, game_obj_t **objects, options_t *game)
{
    get_framerate(wind);
    for (int i = 0; i < 11; i++)
        print_object(wind, objects[i]);
    for (int j = 13; j < (13 + game->map->enemies); j++)
        print_object(wind, objects[j]);
    if (game->jump == 0)
        print_char(wind, objects[11], 1.1);
    else
        print_char(wind, objects[12], 1.1);
    if (game->pause == 1)
        print_pause(wind, game);
    sfRenderWindow_drawText(wind->window, wind->FPS, NULL);
}