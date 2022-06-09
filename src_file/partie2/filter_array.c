/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

char **filter_tab(char **tab2, char **all_arg)
{
    char **test;
    return test;
}

char *get_word(char *string)
{
    int x = 0;
    int y = 1;
    int z;
    char *str;

    while (string[x] != 'n' || string[x + 1] != 'a' || string[x + 2] != 'm'
    || string[x + 3] != 'e' || string[x + 4] != '=' || string[x + 5] != '"')
            x++;
        x = x + 6;
    while (string[x + y] != '"')
        y++;
    z = y;
    str = malloc(sizeof(char) * (y + 1));
    y = 0;
    while (y < z) {
        str[y] = string[x + y];
        y++;
    }
    str[y] = '\0';
    return str;
}
char **scrap_species(char **all_arg, char **a_tab, position_t *s)
{
    int i = 0;
    int j = 0;
    int ii = 0;
    int jj = 0;
    char *string;
    char **new_tab;

    while (str_compare(a_tab[i], "<listOfSpecies>") != 0)
        i++;
    while (str_compare(a_tab[i + j + 1], "</listOfSpecies>") != 0)
        j++;
    new_tab = malloc(sizeof(char *) * (j + 1));
    ii = i;
    s->cursor = 0;
    while (i < (ii + j)) {
        string = get_word(a_tab[i + 1]);
        new_tab = tab_add(new_tab, string, s);
        i++;
        jj++;
    }
    new_tab[jj] = NULL;
    return new_tab;
}

int get_a_line(char **tab)
{
    int i = 0;

    while(tab[i])
        i++;
    return i + 1;
}

char **ordre_alpha(char **tab, position_t *s)
{
    int line_alpha = 0;
    int good_line = get_a_line(tab);
    char **new_tab = malloc(sizeof(char *) * ((good_line) + 1));

    s->cursor = 0;
    while (s->cursor != (good_line - 1)) {
        line_alpha = get_line_alpha(tab);
        new_tab = tab_add(new_tab, tab[line_alpha], s);
        tab[line_alpha][0] = 127;
        continue;
    }
    new_tab[s->cursor] = NULL;
    return new_tab;
}

char **concating(char **tab)
{
    int i = 0;
    int j = 0;

    while (tab[i])
        i++;
    while (j < i) {
        tab[j] = concatstr("----->", tab[j]);
        j++;
    }
    return tab;
}