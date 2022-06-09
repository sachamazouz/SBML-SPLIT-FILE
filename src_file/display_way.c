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
    char *string2 = my_strdup(av[3]);
    char **all_arg = my_strtowordtab_synthesis(string);
    char **tab = my_str_to_word_array(string, '\n');
    char **get_array = ordre_alpha(scrap_species(all_arg, tab, s), s);
    char **tab2 = alphabetical_order(tab, s);

    //infinite_putstr(all_arg);
    //infinite_putstr(tab2);
    if (detect_species(all_arg, string2) == 0) {
        display_species(string2);
        select_print_species(tab, get_array, string2);
        return;
    }
    if (detect_rp(all_arg, string2) == 0) {
        display_rp1(string2);
        display_rp2(string2);
        return;
    }
    if (detect_reaction(all_arg, string2) == 0) {
        display_reaction(string2);
        return;
    }
    my_putstr("List of species\n");
    infinite_putstr(concating(get_array));
}

