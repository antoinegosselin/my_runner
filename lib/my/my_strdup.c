/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return (NULL);
    my_strcpy(str, src);
    return (str);
}
