/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

int detect_species(char **all_arg, char *string2)
{
    int i = 0;

    while (all_arg[i + 1]) {
        if ((str_compare(all_arg[i], "compartment") == 0) &&
            (str_compare(all_arg[i + 1], string2) == 0))
            return 0;
        i++;
    }
    return 1;
}

int detect_reaction(char **all_arg, char *string2)
{
    int i = 0;
    int reaction = 0;

    while (all_arg[i + 1]) {
        if ((str_compare(all_arg[i], "reaction") == 0))
            reaction++;
        if ((str_compare(all_arg[i], "species") == 0) &&
            (str_compare(all_arg[i + 1], string2) == 0) && reaction == 1)
                return 0;
        i++;
    }
    return 1;
}

int detect_rp(char **all_arg, char *string2)
{
    int i = 0;
    int reactants = 0;
    int products = 0;
    int detect = 0;

    while (all_arg[i + 1]) {
        if ((str_compare(all_arg[i], "listOfReactants") == 0))
            reactants++;
        if ((str_compare(all_arg[i], "listOfProducts") == 0))
            products++;
        if ((str_compare(all_arg[i], "id") == 0) &&
            (str_compare(all_arg[i + 1], string2) == 0) && reactants == 0 &&
            products == 0 && (str_compare(all_arg[i], "species") != 0))
            detect++;
        i++;
    }
    if (detect == 1 && reactants == 2 && products == 2)
        return 0;
    return 1;
}

