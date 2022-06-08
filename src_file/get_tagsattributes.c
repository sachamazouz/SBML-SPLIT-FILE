/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include "my_sbml.h"
#include "my.h"

int check_line(char *string)
{
    int equal = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] == '?' && i == 1)
            return 1;
        if (string[i] == '=' && string[i + 1] == '"')
            equal++;
    }
    if (equal > 0)
        return 0;
    return 1;
}

int d_good_line(char **tab)
{
    int i = 0;
    int counter = 0;

    while (tab[i]) {
        if (check_line(tab[i]) == 0)
            counter++;
        i++;
    }
    return counter + 1;
}

char **get_tagsattributes(char **tab, position_t *s)
{
    int a = 0;
    int good_line = d_good_line(tab);
    char **new_tab = malloc(sizeof(char *) * (good_line) + 1);

    s->cursor = 0;
    while (s->cursor != (good_line - 1)) {
        if (check_line(tab[a]) == 0)
            new_tab = tab_add(new_tab, tab[a], s);
        a++;
    }
    new_tab[s->cursor] = NULL;
    return new_tab;
}
