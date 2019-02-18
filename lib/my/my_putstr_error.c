/*
** EPITECH PROJECT, 2018
** my_putstr_error.c
** File description:
** display characters of a string in error output
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
}