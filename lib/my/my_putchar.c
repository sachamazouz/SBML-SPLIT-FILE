/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** epitech
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
