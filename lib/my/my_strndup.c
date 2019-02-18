/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** my_strndup
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strndup(char *str, int n)
{
    char *new_str;
    int len = 0;
    int i = 0;

    while (str[len] != '\0' && (n == -1 || (n != -1 && len < n)))
        len++;
    new_str = malloc(sizeof(char) * (len + 1));
    if (new_str == NULL)
        return (NULL);
    for (; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return (new_str);
}