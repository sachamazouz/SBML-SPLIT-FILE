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
}
position_t;

int array_line(char **tab);
//void malloc_struct(char *map, position_t *p);
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
#endif