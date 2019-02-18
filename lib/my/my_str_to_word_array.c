/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

static int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

static int words_count(char const *str, int str_len)
{
    int words_count = 0;

    for (int i = 0; i < str_len; i++) {
        if (is_alphanumeric(str[i]) == 1 && i == 0) {
            words_count++;
        }
        if (is_alphanumeric(str[i]) == 1 && is_alphanumeric(str[i - 1]) == 0)
            if (i != 0)
                words_count++;
    }
    return (words_count);
}

char **my_str_to_word_array(char const *str)
{
    int pos[5] = { 0, 0, 0, 0, 0 };
    int word_count = words_count(str, my_strlen(str));
    char **return_array = malloc(sizeof(char *) * (word_count + 1));

    while (pos[3] < word_count) {
        while (is_alphanumeric(str[pos[1]]) == 0)
            pos[1]++;
        pos[0] = pos[1];
        while (is_alphanumeric(str[pos[1]]) == 1)
            pos[1]++;
        pos[2] = pos[0];
        return_array[pos[3]] = malloc(sizeof(char) * (pos[1] - pos[2] + 1));
        for (pos[4] = 0; pos[2] < pos[1]; pos[4]++) {
            return_array[pos[3]][pos[4]] = str[pos[2]++];
        }
        return_array[pos[3]++][pos[4]] = '\0';
    }
    return_array[pos[3]] = malloc(sizeof(int));
    return_array[pos[3]] = 0;
    return (return_array);
}
