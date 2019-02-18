/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int destroy_game(options_t *game)
{
    int ret_val = game->error;

    for (int j = 0; j < 6; j++) {
        sfTexture_destroy(game->graphics[j]->texture);
        sfSprite_destroy(game->graphics[j]->sprite);
    }
    sfMusic_destroy(game->song);
    sfSound_destroy(game->sound);
    sfSoundBuffer_destroy(game->sound_buff);
    if (game->total == game->high_score) {
        if (setup_new_highscore(game->total, "highscore.txt") == -1) {
            free(game);
            return (84);
        }
    }
    free(game);
    return (ret_val);
}

int destroy_objects(game_obj_t **obj, options_t *game)
{
    int free = 13;
    int ret_val = game->error;

    for (int i = 0; i < free; i++) {
        sfTexture_destroy(obj[i]->texture);
        sfSprite_destroy(obj[i]->sprite);
    }
    return (ret_val);
}