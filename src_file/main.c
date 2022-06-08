/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "my_sbml.h"
#include "my.h"

void display_usage(void)
{
    my_putstr("USAGE\n        ./SBMLparser SBMLfile  [-i ID [-e]] [-json]\n\n"
    "DESCRIPTION\n        SBMLfileSBML file\n"
    "        -i ID   id of the compartment, reaction or product to be extracted\n"
    "                (ignored if uncorrect)\n"
    "        -e      print the equation if\e[3mID\e[0m is given as argument\n"
    "                (ignored otherwise\n"
    "        -json   transform the file into a JSON file\n");
    return;
}

void fix_value(position_t *s)
{
    s->compartment = 0;
    s->reaction = 0;
    s->species = 0;
}

char *extract(char *pathname)
{
    int fd;
    char *file;
    struct stat buf;

    if ((fd = open(pathname, O_RDONLY)) == -1)
        exit(84);
    stat(pathname, &buf);
    file = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, file, buf.st_size);
    file[buf.st_size] = '\0';
    return file;
}

int main(int ac, char **av)
{
    position_t *s = malloc(sizeof(position_t));

    if (ac == 2 && ((str_compare(av[1], "-h") == 0))) {
        display_usage();
        return 0;
    }
    if (ac == 2)
        display_1(av, s);
    if (ac == 4 && (str_compare(av[2], "-i") == 0))
        display_compartment(av, s);
    return 0;
}
