/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** my_str_isupper
*/

static int char_is_alpha_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (char_is_alpha_upper(str[count]) == 0)
            return (0);
        count++;
    }
    return (1);
}
