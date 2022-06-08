/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

void display_species(char *string2)
{
    my_putstr("List of species in compartment ");
    my_putstr(string2);
    my_putchar('\n');
}

void display_rp1(char *string2)
{
    my_putstr("List of reactants of reaction ");
    my_putstr(string2);
    my_putchar('\n');
}

void display_rp2(char *string2)
{
    my_putstr("List of products of reaction ");
    my_putstr(string2);
    my_putchar('\n');
}

void display_reaction(char *string2)
{
    my_putstr("List of reactions consuming species ");
    my_putstr(string2);
    my_putstr(" (quantities)\n");
}