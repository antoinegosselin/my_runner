/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** returns the smallest prime number greater or equal to nb
*/

static int my_is_prime(int nb)
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

int my_find_prime_sup(int nb)
{
    if (nb > 2147483629)
        return (0);
    if (nb <= 1)
        return (2);
    if (my_is_prime(nb) == 1)
        return (nb);
    return (my_find_prime_sup(nb + 1));
}
