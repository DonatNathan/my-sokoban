/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** It's a program that return a number enter in parameter
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    int cmpt = 0;
    int cmpt_moins = 0;
    int number = 0;

    while (str[cmpt] == '+' || str[cmpt] == '-') {
        if (str[cmpt] == '-')
            cmpt_moins += 1;
        cmpt += 1;
    }
    while (str[cmpt] <= '9' && str[cmpt] >= '0') {
        number = number * 10 + str[cmpt] - 48;
        cmpt += 1;
    }
    if (cmpt_moins % 2 != 0)
        number *= -1;
    return (number);
}
