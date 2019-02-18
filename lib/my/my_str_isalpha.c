/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** my_str_isalpha
*/

static int char_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (char_is_alpha(str[count]) == 0)
            return (0);
        count++;
    }
    return (1);
}
