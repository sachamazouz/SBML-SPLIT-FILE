/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

int get_line_tab(char **tab)
{
    int x = 0;

    while (tab[x])
        x++;
    return x;
}

void display_with_concat(char *string)
{
    my_putstr("----->");
    my_putstr(string);
    my_putchar('\n');
}

int check_container(char *string, char *argument)
{
    return 0;
}

void select_print_species(char **stwa, char **tab, char *argument)
{
    int x = 1;
    int j = 0;
    int y = get_line_tab(tab);

    while (str_compare(stwa[x - 1], "<listOfSpecies>") != 0)
        x++;
    while (j != y) {
        if (check_container(stwa[x + j], argument) == 0) {
            display_with_concat(tab[j]);
            my_putstr(stwa[x + j]);
        }
        j++;
    }
}