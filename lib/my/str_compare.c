/*
** EPITECH PROJECT, 2021
** str_compare
** File description:
** str_compare.c
*/
#include <stddef.h>
int my_strlen(char const *str);

int str_compare(char *str1, char *str2)
{
    int a = 0;
    int b = 0;
    int c = 0;

    if (str1 == NULL || str2 == NULL)
        return 84;
    a = my_strlen(str1);
    b = my_strlen(str2);
    if (a != b)
        return 84;
    while (str1[c] != '\0') {
        if (str1[c] != str2[c])
            return 84;
        c++;
    }
    return 0;
}
