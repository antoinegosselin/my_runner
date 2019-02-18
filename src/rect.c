/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** rect
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

sfIntRect initialize_rect(int width, int height)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return (rect);
}