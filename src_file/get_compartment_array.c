/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include "my_sbml.h"
#include "my.h"

char **tab_add(char **tab, char *string, position_t *s)
{
    int a = my_strlen(string);
    int d = 0;
    int j = 0;

    if (a == 0)
        return tab;
    while (string[j] == ' ' || string[j] == '\t' || string[j] == '\v')
        j++;
    printf("%d\n", j);
    tab[s->cursor] = malloc(sizeof(char) * ((a + 1) - (j)));
    while (a >= (d + j)) {
        tab[s->cursor][d] = string[d + j];
        d++;
    }
    tab[s->cursor][d - 1] = '\0';
    s->cursor++;
    return tab;
}

char **compartment_array(position_t *s)
{
    char **array = malloc(sizeof(char *) * 11);

    s->cursor = 0;
    array = tab_add(array, "compartment\n", s);
    array = tab_add(array, "model\n", s);
    array = tab_add(array, "listOfCompartments\n", s);
    array = tab_add(array, "listOfProducts\n", s);
    array = tab_add(array, "listOfReactants\n", s);
    array = tab_add(array, "listOfReactions\n", s);
    array = tab_add(array, "listOfSpecies\n", s);
    array = tab_add(array, "reaction\n", s);
    array = tab_add(array, "species\n", s);
    array = tab_add(array, "speciesReference\n", s);
    array[10] = NULL;

    return array;
}
