/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** create an array from a string
*/
#include <stddef.h>
#include "../../include/my.h"
#include <stdlib.h>

int moove_second(char *string, char delim, int i)
{
    while (string[i + 1] == delim)
        i++;
    return i;
}

int moove_first(char *string, char delim)
{
    int i = 0;

    while (string[i] == delim)
        i++;
    return i;
}

int gett_obstacle(char *string, char delim)
{
    int len = my_strlen(string);
    int i = moove_first(string, delim);
    int count = 0;
    int j = len - 1;

    while (string[j] == delim) {
        len--;
        j--;
    }
    for (int a = i; i < len; i++, a++) {
        if (string[i] != delim)
            continue;
        count++;
        i = moove_second(string, delim, i);
    }
    return count + 1;
}

char **my_str_to_word_array(char *string, char delim)
{
    int x = 0;
    int size = 0;
    int obstacle = gett_obstacle(string, delim);
    char **array = malloc(sizeof(char *) * (obstacle + 1));

    for (int i = 0; i < obstacle; i++) {
        while (string[x] == delim)
            x++;
        while (string[x] != delim && string[x] != '\0') {
            size++;
            x++;
        }
        array[i] = malloc(sizeof(char) * size + 1);
        array[i][size] = '\0';
        for (int j = 0; j < size; j++)
            array[i][j] = string[(x - size) + j];
        size = 0;
    }
    array[obstacle] = NULL;
    return array;
}

void infinite_putstr(char **tab)
{
    int x = 0;

    while (tab[x]) {
        my_putstr(tab[x]);
        my_putchar('\n');
        x++;
    }
}
