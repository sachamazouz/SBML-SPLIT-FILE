/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include "my_sbml.h"
#include "my.h"

int compare(int final, int i, char *string, char *good_string)
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

int get_line_alpha(char **filter)
{
    int i = 0;
    int final = 0;

    char *good_string = my_strdup(filter[0]);

    while (filter[i]) {
        final = compare(final, i, filter[i], good_string);
        good_string = my_strdup(filter[final]);
        i++;
    }
    return final;
}

char **alphabetical_order(char **tab, position_t *s)
{
    int line_alpha = 0;
    int good_line = d_good_line(tab);
    char **filter = get_tagsattributes(tab, s);
    char **new_tab = malloc(sizeof(char *) * (good_line) + 1);

    s->good_line = 0;
    if (good_line == 1)
        s->good_line = 1;
    s->cursor = 0;
    while (s->cursor != (good_line - 1)) {
        line_alpha = get_line_alpha(filter);
        new_tab = tab_add(new_tab, filter[line_alpha], s);
        filter[line_alpha][0] = 127;
        continue;
    }
    new_tab[s->cursor] = NULL;
    return new_tab;
}
