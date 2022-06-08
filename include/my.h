/*
** EPITECH PROJECT, 2021
** myh
** File description:
** my.h
*/
#ifndef MY_H_
    #define MY_H_

int my_atoi(char *str);
void get_error(char c);
void print_error(char *sentance);
char *concatstr(char *str,char *str2);
int my_getnbr(char *str);
int my_putchar(char c);
int my_putnbr(int n);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int checker(char const *string, char *delim, int counter, int counter2);
int get_obstacle1(char const *string, char *delim);
int special_strlen1(char const *string, int counter, char *c);
char **str_to_word_array1(char const *string, char *c);
int mooving2(char const *string, int counter, char *c);
int get_obstacle(char const *string);
int special_strlen(char const *string, int counter, char c);
int mooving(char *string, int counter, char c);
char **str_to_word_array(char *string, char c);
void infinite_putstr(char **tab);
int my_strcmp(char *string1 , char *string2);
char **my_strtowordtab_synthesis(char const *str);
int str_compare(char *str1, char *str2);
int gett_obstacle(char *string, char delim);
char **my_str_to_word_array(char *string, char delim);

#endif /* MY_H_ */
