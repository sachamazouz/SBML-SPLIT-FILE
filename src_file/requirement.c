/*
** EPITECH PROJECT, 2021
** requirement
** File description:
** requirement.c
*/
#include "my_sbml.h"

int get_obstacle(char const *string)
{
    int cursor = 0;
    int obstacle = 0;

    while (string[cursor]) {
        if ((string[cursor] < '0' || string[cursor] > '9')
        && (string[cursor] < 'a' || string[cursor] > 'z')
        && (string[cursor] < 'A' || string[cursor] > 'Z'))
          obstacle++;
        cursor++;
    }
    return obstacle;
}

int detect_char(char c)
{
    if ((c < '0' || c > '9')
        && (c < 'a' || c > 'z')
        && (c < 'A' || c > 'Z'))
        return NON_ALPHA_NUM;
    return ALPHA_NUM;
}

char **get_attribution(char **tab, int i, char const *str, int j)
{
    int malloc_size = 0;
    int z = 0;

    while (detect_char(str[i]) != NON_ALPHA_NUM) {
        i++;
        malloc_size++;
    }
    if (i == 0)
        return tab;
    i = i - malloc_size;
    tab[j] = malloc(sizeof(char) * (malloc_size + 1));
    while (z < malloc_size) {
        tab[j][z] = str[i];
        z++;
        i++;
    }
    tab[j][z] = '\0';
    return tab;
}

char **my_strtowordtab_synthesis(char const *str)
{
    int obstacle = get_obstacle(str);
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * (obstacle + 1));

    tab = get_attribution(tab, 0, str, j);
    //if (tab[j] != NULL)
      //  j++;
    while (str[i]) {
        if ((j - 1) == obstacle) {
            break;
        }
        if (detect_char(str[i]) == NON_ALPHA_NUM && detect_char(str[i + 1]) == ALPHA_NUM) {
            tab = get_attribution(tab, (i + 1), str, j);
        }
        i++;
    }
    tab[j] = NULL;
    return tab;
}
