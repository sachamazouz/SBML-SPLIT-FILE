/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.c
*/
#include <unistd.h>

void get_error(char c)
{
    write(2, &c, 1);
}

void print_error(char *sentance)
{
    int  counter;

    counter = 0;
    while (sentance[counter] != '\0') {
        get_error(sentance[counter]);
        counter++;
    }
}
