/*
** EPITECH PROJECT, 2021
** BABA
** File description:
** BABA
*/
int my_putchar(char c);

int my_putstr(char const *str)
{
    int b;

    b = 0;
    while (str[b] != '\0') {
        my_putchar(str[b]);
        b = b + 1;
    }
}
