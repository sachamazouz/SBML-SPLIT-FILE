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

int arg_value(char **tab, int x)
{
    int counter = 0;

    while (tab[x + 1][0] == '-') {
        counter++;
        x++;
    }
    return counter;
}

int checker_display1(char **tab, int x, int z)
{
    while (tab[x + 1][0] == '-') {
        x++;
        if (x == (z - 1))
            return MAX_INT_VALUE;
    }
    return x;
}
void display_basic_list(char **tab)
{
    int x = 0;
    int counter = 1;
    int z = 0;
    char *word = NULL;

    while (tab[z])
        z++;
    while (tab[x]) {
        if (str_compare(word, tab[x]) != 0) {
            my_putstr(tab[x]);
            my_putchar('\n');
        }
        if (str_compare(word, tab[x]) == 0)
            x = checker_display1(tab, x, z);
        if (x == MAX_INT_VALUE)
            return;
        if (tab[x][0] != '-')
            word = my_strdup(tab[x]);
        x++;
        counter++;
    }
}