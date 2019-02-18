/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

void my_putchar(char c);

static void skip_this(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

static int count(int a)
{
    int count = 0;
    int reste = 1;

    while (reste > 0) {
        reste = (a / 10);
        count++;
        a = reste;
    }
    return (count);
}

static int display_numb(int nbcar, int nb, int p_dix)
{
    int nb_bis;

    while (nbcar > 0) {
        nb_bis = (nb / p_dix % 10);
        my_putchar(nb_bis + '0');
        nbcar--;
        p_dix = p_dix / 10;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int nbcar;
    int boucle;
    unsigned int p_dix = 1;
    int nb_bis;

    if (nb == -2147483648) {
        skip_this();
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    nbcar = count(nb);
    boucle = nbcar;
    while (--boucle > 0)
        p_dix = p_dix * 10;
    display_numb(nbcar, nb, p_dix);
    return (0);
}
