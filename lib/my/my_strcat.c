/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int count;

    for (count = 0; src[count] != '\0'; count++)
        dest[dest_len + count] = src[count];
    dest[dest_len + count] = '\0';
    return (dest);
}
