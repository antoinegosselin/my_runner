/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int min = 0;
    int swap;

    while (i < size) {
        while (j < size) {
            min = (array[j] <= array[min]) ? j : min;
            j++;
        }
        swap = array[i];
        array[i] = array[min];
        array[min] = swap;
        i++;
        j = i;
        min = i;
    }
}
