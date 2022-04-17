/*
** EPITECH PROJECT, 2021
** MY.H
** File description:
** It's just all function's prototype of our library
*/

#ifndef MY_H_
    #define MY_H_

int my_atoi(char *str);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char *src, int n);
int my_printf(char *s, ...);
char *my_my_itoa(int nb);
int puissance(int y);
char **str_to_array(char *map, char stop);

#endif /* MY_H_ */
