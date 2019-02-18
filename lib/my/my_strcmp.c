/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int count = 0;

    while (s1[count] == s2[count]) {
        if (s1[count] == '\0')
            return (0);
        count++;
    }
    return (s1[count] - s2[count]);
}
