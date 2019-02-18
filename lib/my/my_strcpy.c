/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy a string
*/

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;

    while (src[count] != '\0') {
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
    return (dest);
}
