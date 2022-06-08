/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** strdupp
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int count;
    char *a;

    count = my_strlen(src);
    a = malloc(sizeof(char) * count + 1);
    for (int i = 0; i < count; i += 1)
        a[i] = src[i];
    a[count] = '\0';
    return a;
}
