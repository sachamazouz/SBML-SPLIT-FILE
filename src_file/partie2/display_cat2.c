/*
** EPITECH PROJECT, 2021
** disolay_way
** File description:
** disolay_way.c
*/
#include "my_sbml.h"
#include "my.h"

int get_line_tab(char **tab)
{
    int x = 0;

    while (tab[x])
        x++;
    return x;
}

void display_with_concat(char *string)
{
    my_putstr("----->");
    my_putstr(string);
    my_putchar('\n');
}

char *get_word_line(char *string)
{
    int x = 0;
    int j = 0;
    int z = 0;
    char *word;

    while (string[x] != '=' && string[x + 1] != '"') {
        x++;
    }
        x = x + 2;
    while (string[x + j] != '"')
        j++;
    z = j;
    word = malloc(sizeof(char) * j + 1);
    j = 0;
    while (j < z) {
        word[j] = string[x + j];
        j++;
    }
    word[j] = '\0';
    return word;
}

int check_container(char *string, char *argument)
{
    char *word = get_word_line(string);

    if (str_compare(word, argument) == 0)
        return 0;
    return 1;
}

char **get_space_tab(char **tab)
{
    int x = 0;
    int y = 0;
    int z;
    char **new_tab;

    while (str_compare(tab[x], "<listOfSpecies>") != 0)
        x++;
    while (str_compare(tab[x + y + 1], "</listOfSpecies>") != 0)
        y++;
    new_tab = malloc(sizeof(char *) * (y + 1));
    z = y;
    y = 0;
    x++;
    while (y < z) {
        new_tab[y] = my_strdup(tab[x + y]);
        y++;
    }
    new_tab[y] = NULL;
    return new_tab;
}
