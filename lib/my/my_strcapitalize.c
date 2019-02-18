/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** my_strcapitalize
*/

static void strcap(char *str, int count)
{
    if (str[count] >= 'A' && str[count] <= 'Z') {
        if (str[count - 1] != ' ')
            str[count] = str[count] - ('A' - 'a');
    }
    if (str[count] >= 'a' && str[count] <= 'z') {
        if (str[count - 1] == ' ')
            str[count] = str[count] + ('A' - 'a');
        if (str[count - 1] == '+')
            str[count] = str[count] + ('A' - 'a');
        if (str[count - 1] == '-')
            str[count] = str[count] + ('A' - 'a');
    }
}

char *my_strcapitalize(char *str)
{
    int	count;

    count = 1;
    while (str[count] != '\0')
    {
        strcap(str, count);
        count++;
    }
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] + ('A' - 'a');
    return (str);
}
