/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** my_show_word_array
*/

void my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int count = 0; tab[count] != 0; count++)
        my_putstr(tab[count]);
    return (0);
}
