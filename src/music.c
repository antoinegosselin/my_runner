/*
** EPITECH PROJECT, 2018
** music.c
** File description:
** set the music in the menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int set_music(options_t *game)
{
    sfMusic_setLoop(game->song, sfTrue);
    if (game->music == 0) {
        sfMusic_play(game->song);
        game->music = 1;
    } else {
        sfMusic_pause(game->song);
        game->music = 0;
    }
    return (game->music);
}