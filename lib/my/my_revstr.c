/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** my_revstr
*/

static int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

char *my_revstr(char *str)
{
    char swap;
    int left;
    int right;

    left = 0;
    right = my_strlen(str) - 1;

    while (left < right) {
        swap = str[left];
        str[left] = str[right];
        str[right] = swap;
        left++;
        right--;
    }
    return (str);
}
