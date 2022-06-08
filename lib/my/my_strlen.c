/*
** EPITECH PROJECT, 2021
** BINKSSS
** File description:
** BINKSSSS
*/

int my_strlen(char const *str)
{
    int b;

    b = 0;
    while (str[b] != '\0') {
        b = b + 1;
    }
    return (b);
}
