/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include "my_sbml.h"
#include "my.h"

int alpha_compare(int final, int i, char *string, char *good_string)
{
    int x = 0;

    while (string[x] || good_string[x]) {
        if (good_string[x] > string[x])
            return (i);
         if (good_string[x] < string[x])
            return (final);
        x++;
    }
    return final;
}

int alpha_get_line_alpha(char **filter)
{
    int i = 0;
    int final = 0;

    char *good_string = my_strdup(filter[0]);

    while (filter[i]) {
        final = alpha_compare(final, i, filter[i], good_string);
        good_string = my_strdup(filter[final]);
        i++;
    }
    return final;
}

char **alpha_tab_add(char **tab, char *string, position_t *s)
{
    int a = my_strlen(string);
    int d = 0;

    if (a == 0)
        return tab;
    tab[s->cursor2] = malloc(sizeof(char) * (a + 1));
    while (a >= d) {
        tab[s->cursor2][d] = string[d];
        d++;
    }
    tab[s->cursor2][d - 1] = '\0';
    s->cursor2++;
    return tab;
}

int alpha_d_good_line(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i + 1;
}

char **alpha_betical_order(char **tab, position_t *s)
{
    int line_alpha = 0;
    int good_line = alpha_d_good_line(tab);
    char **new_tab = malloc(sizeof(char *) * (good_line) + 1);

    s->cursor2 = 0;
    while (s->cursor2 != (good_line - 1)) {
        line_alpha = alpha_get_line_alpha(tab);
        new_tab = alpha_tab_add(new_tab, tab[line_alpha], s);
        tab[line_alpha][0] = 127;
        continue;
    }
    new_tab[s->cursor2] = NULL;
    return new_tab;
}
