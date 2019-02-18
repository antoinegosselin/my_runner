/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;

    while (s1[count] == s2[count] && count < (n - 1)) {
        if (s1[count] == '\0')
            return (0);
        count++;
    }
    return (s1[count] - s2[count]);
}
