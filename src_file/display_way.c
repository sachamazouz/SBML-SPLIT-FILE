/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

void display_1(char **av, position_t *s)
{
    char *string = extract(av[1]);
    char **tab = my_str_to_word_array(string, '\n');
    char **tab2 = alphabetical_order(tab, s);
    char **final_tab = get_display(tab2, s);

    display_basic_list(final_tab);
    return;
}

void display_compartment(char **av, position_t *s)
{
    char *string = extract(av[1]);
    char **all_arg = my_strtowordtab_synthesis(string);
    char **tab = my_str_to_word_array(string, '\n');
    char **tab2 = alphabetical_order(tab, s);

    infinite_putstr(all_arg);
    return;
}