/*
** EPITECH PROJECT, 2021
** soko
** File description:
** soko include
*/

#ifndef SOKOBAN_H
    #define MY_SOKOBAN_H

    #define ALPHA_NUM 0
    #define NON_ALPHA_NUM 1
    #define MAX_INT_VALUE 2147483647
    #include <stdio.h>
    #include <ncurses.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "my.h"
    #include <sys/types.h>
    #include <sys/ioctl.h>

typedef struct pos_s {
    int compartment;
    int species;
    int reaction;
    int cursor;
    int cursor2;
    int *detector;
    int good_line;
}
position_t;

int array_line(char **tab);
void display_error(void);
void ncurses(void);
char **compartment_array(struct pos_s *);
char **tab_add(char **tab, char *string, struct pos_s *);
char **get_tagsattributes(char **tab, struct pos_s *);
char **alphabetical_order(char **tab, struct pos_s *);
int d_good_line(char **tab);
char **add_speci(char **tab, int x, char *string, int cursor);
char **argument_add(char **tab, char *string, struct pos_s *);
char **get_display(char **tab, struct pos_s *);
int get_speci(char **tab);
char *get_arg(char *arg, char *string);
int is_a_speci(char *string);
char **alpha_betical_order(char **tab, struct pos_s *);
void display_1(char **av, struct pos_s *);
char *extract(char *pathname);
void display_basic_list(char **tab);
int detect_reaction(char **all_arg, char *string2);
void display_rp2(char *string2);
void display_reaction(char *string2);
void display_rp1(char *string1);
int detect_rp(char **all_arg, char *string2);
char **filter_tab(char **tab2, char **all_arg);
void display_species(char *string2);
int detect_species(char **all_arg, char *string2);
void display_compartment(char **av, struct pos_s *);

#endif
