/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

int my_getnbr(char *str)
{
    long long result = 0;
    long long resultat;
    int sign = 1;

    while (((*str) == '-') || ((*str) == '+')) {
        if (*str == '-')
            sign = sign * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9')) {
        resultat = (result * 10) + ((*str) - '0');
        if ((result != 0) && (((resultat / 10) != result)))
            return (0);
        str++;
        result = resultat;
    }
    result = result * sign;
    if ((result < -2147483648) || (result > 2147483647))
        result = 0;
    return (result);
}
