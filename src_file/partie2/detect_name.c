/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

int detect_name(char **all_arg, char *string2)
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

char **filter_tab(char **a_tab, char **all_arg)
{
    char **new_tab;
    return new_tab;
}