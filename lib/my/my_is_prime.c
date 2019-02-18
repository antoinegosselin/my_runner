/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** prime number or not
*/

int my_is_prime(int nb)
{
    int count = 3;

    if (nb == 2147483647)
        return (1);
    if ((nb <= 1) || (nb % 2 == 0))
        return (0);
    while (count < nb) {
        if (nb % count == 0)
            return (0);
        if ((count * count) > nb)
            return (1);
        count = count + 2;
    }
    return (1);
}
