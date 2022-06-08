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

    if (s->good_line == 1) {
        infinite_putstr(tab);
        //créer un special display
        return;
    }
    display_basic_list(final_tab);
    return;
}