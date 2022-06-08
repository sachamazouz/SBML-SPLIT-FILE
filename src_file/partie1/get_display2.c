/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include "my_sbml.h"
#include "my.h"

int is_a_speci(char *string)
{
    int speci = 0;
    int x = 0;

    while (string[x]) {
        if (string[x] == '=' && string[x + 1] == '"')
            speci++;
        x++;
    }
    return speci;
}

int get_speci(char **tab)
{
    int i = 0;
    int counter = 0;

    while (tab[i]) {
        counter = counter + is_a_speci(tab[i]);
        i++;
    }
    return (counter + i);
}

int my_special_strlen(char *string)
{
    int i = 0;
    int j = 0;

     while (string[i] != '<')
        i++;
    while (string[i + j] != ' ')
        j++;
    return j;
}

char *get_arg(char *arg, char *string)
{
    int x = my_special_strlen(string);
    int j = 0;
    int i = 0;

    arg = malloc(sizeof(char) * (x + 1));
    while (string[i] == '<') {
        i++;
    }
    while (string[j + i] != ' ') {
        arg[j] = string[j + i];
        j++;
    }
    arg[j] = '\0';
    return arg;
}

void display_basic_list(char **tab)
{
    int x = 0;
    int counter = 0;

    while (tab[x]) {
        my_putstr(tab[x]);
        my_putchar('\n');
        x++;
    }
}