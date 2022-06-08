/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include "my_sbml.h"
#include "my.h"

char **get_display(char **tab, position_t *s)
{
    int i = get_speci(tab);
    int j = 0;
    char *arg;
    char **new_tab = malloc(sizeof(char *) * (i + 1));

    s->cursor = 0;
    while (s->cursor != i) {
        arg = get_arg(arg, tab[j]);
        new_tab = tab_add(new_tab, arg, s);
        new_tab = argument_add(new_tab, tab[j], s);
        j++;
        continue;
    }
    new_tab[s->cursor] = NULL;
    return new_tab;
}

char **get_arg_tri(char *string)
{
    int i = is_a_speci(string);
    int cursor = 0;
    int x = 0;
    char **tab = malloc (sizeof(char *) * (i + 1));

    while (string[cursor]) {
         if (string[cursor] == '=') {
             while (string[cursor] != ' ')
                cursor--;
            tab = add_speci(tab, x, string, (cursor + 1));
            x++;
            while (string[cursor - 1] != '=')
                cursor++;
         }
         cursor++;
    }
    tab[x] = NULL;
    return tab;
}

char **add_speci(char **tab, int x, char *string, int cursor)
{
    int j = 0;
    int i = 0;

    while (string[i + cursor] != '=')
        i++;
    tab[x] = malloc(sizeof(char) * i + 1);
    while ((j + cursor) != ((i + cursor))) {
        tab[x][j] = string[j + cursor];
        j++;
    }
    tab[x][j] = '\0';
    return tab;
}

char **argument_add(char **tab, char *string, position_t *s)
{
    int x = 0;
    char **arg_tri = get_arg_tri(string);
    char **alpha_arg_tri = alpha_betical_order(arg_tri, s);

    while (alpha_arg_tri[x]) {
        alpha_arg_tri[x] = concatstr("----->", alpha_arg_tri[x]);
        x++;
    }
    x = 0;
    while (alpha_arg_tri[x]) {
        tab = tab_add(tab, alpha_arg_tri[x], s);
        x++;
    }
    return tab;
}
