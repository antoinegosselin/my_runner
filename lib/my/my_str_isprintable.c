/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** my_str_isprintable
*/

static int char_is_printable(char c)
{
    if (c >= ' ' && c <= '~')
        return (1);
    return (0);
}

int my_str_isprintable(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (char_is_printable(str[count]) == 0)
            return (0);
        count++;
    }
    return (1);
}
