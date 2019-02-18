/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** flags
*/

#include "my.h"
#include "runner.h"

void print_usage(void)
{
    my_putstr("\nUSAGE\n");
    my_putstr("    ./my_runner map or ./my_runner flag\n\n");
    my_putstr("    map: map pack you want to use, ");
    my_putstr("choose between /maps/easy/ (/maps/medium/ /maps/hard/ are ");
    my_putstr("in development)\n    flag: -h for usage, -c for credits\n\n");
    my_putstr("DESCRIPTION\n\nIn this game, you have to run for your life\n");
    my_putstr("Don't forget to change the level if it's too easy\n\n");
    my_putstr("Enjoy the game :D !\n\nCONTROLS\n\n");
    my_putstr("Space -> Jump\n");
    my_putstr("F5 -> Mute/Unmute music\n");
    my_putstr("P -> Pause menu\n");
    my_putstr("M -> Go back to menu\n");
    my_putstr("Escape -> Close the game\n\n");
}

void print_credits(void)
{
    my_putstr("\nCREDITS\n\n");
    my_putstr("Producer: Antoine Gosselin\n");
    my_putstr("Game director: Antoine Gosselin\n");
    my_putstr("Graphist: Fabien Launay\n");
    my_putstr("Music: Assasin's Creed Opening\n");
    my_putstr("Paralax: Liz Molnar\n\n");
}

int check_flag(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        print_usage();
        return (0);
    }
    else if (av[1][0] == '-' && av[1][1] == 'c' && my_strlen(av[1]) == 2) {
        print_credits();
        return (0);
    } else
        return (1);
}