/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** return the square root of nb
*/

int my_compute_square_root(int nb)
{
    int count = 1;
    int product = count * count;
    int result = 1;

    if ((nb <= 0) || (nb > 2147395600)) {
        return (0);
    }
    while (product < nb) {
        count++;
        product = count * count;
        result++;
    }
    if ((result * result) == nb)
        return (result);
    else
        return (0);
}
