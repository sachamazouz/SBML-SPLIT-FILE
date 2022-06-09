/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

char *get_word_line2(char *string)
{
    int x = 0, j = 0, z = 0, detect = 0;
    char *word;

    while (detect != 3) {
        while (string[x] != '=' && string[x + 1] != '"') {
            x++;
        }
            x = x + 2;
            detect++;
    }
    while (string[x + j] != '"')
        j++;
    z = j;
    word = malloc(sizeof(char) * j + 1);
    j = 0;
    while (j < z) {
        word[j] = string[x + j];
        j++;
    }
    word[j] = '\0';
    return word;
}

void select_print_species(char **stwa, char **tab, char *argument, position_t *s)
{
    int j = 0, y = get_line_tab(tab), z = 0, jj = 0;
    char **new_tab = get_space_tab(stwa);
    char **comparator = malloc(sizeof(char * ) * (y + 1));
    char **final_tab = malloc(sizeof(char * ) * (y + 1));
    char **final_tab_t = malloc(sizeof(char *) * (y + 1));

    while (j != y) {
        if (check_container(new_tab[j], argument) == 0) {
            comparator[z] = my_strdup(new_tab[j]);
            z++;
        }
        j++;
    }
    comparator[z] = NULL;
    while (jj != z) {
        final_tab[jj] = get_word_line2(comparator[jj]);
        jj++;
    }
    final_tab[jj] = NULL;
    final_tab_t = ordre_alpha(final_tab, s);
    display_cat1(final_tab_t, 0);
}

void display_cat1(char **final_tab_t, int j)
{
    while (final_tab_t[j]) {
        my_putstr("----->");
        my_putstr(final_tab_t[j]);
        my_putchar('\n');
        j++;
    }
}