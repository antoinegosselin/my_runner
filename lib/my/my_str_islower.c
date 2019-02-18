/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** my_str_islower
*/

static int char_is_lower_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (char_is_lower_alpha(str[count]) == 0)
            return (0);
        count++;
    }
    return (1);
}
