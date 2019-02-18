/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int count = 0;

    while (count < n && src[count] != '\0') {
        dest[count] = src[count];
        count++;
    }
    while (count < n) {
        dest[count] = '\0';
        count++;
    }
    return (dest);
}
