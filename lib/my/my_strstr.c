/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** my_strstr
*/

static int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

static int compare_end(char *str, char const *to_find, int count, int in_count)
{
    if (str[count + in_count] == to_find[in_count])
        if (str[count + in_count] != '\0')
            return (1);
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int len_to_find = my_strlen(to_find);
    char *match = "";
    int count = 0;
    int in_count;

    while (str[count] != '\0') {
        in_count = 0;
        while (compare_end(str, to_find, count, in_count) == 1) {
            if (in_count == len_to_find - 1)
                match = str + count;
            in_count++;
        }
        count++;
    }
    return (match);
}
