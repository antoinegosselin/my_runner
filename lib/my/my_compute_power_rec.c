/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** nb power p recursive
*/

int my_compute_power_rec(int nb, int p)
{
    long long result = nb;
    int test;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    result  = result * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647)
        return (0);
    else
        return (result);
}
