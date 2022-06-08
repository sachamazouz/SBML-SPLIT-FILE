/*
** EPITECH PROJECT, 2021
** concatstr
** File description:
** concatstr.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *concatstr(char *str,char *str2)
{
    int a = my_strlen(str);
    int b = my_strlen(str2);
    int c = a + b;
    int e = 0;
    int f = 1;
    int g = 0;
    char *result = malloc(sizeof(char) * c + 1);

    while (str[e] != '\0') {
        result[e] = str[e];
        e++;
    }
    e = 0;
    while (str2[e] != '\0') {
        result[a] = str2[g];
        a++;
        g++;
        e++;
    }
    result[c] = '\0';
    return result;
}
