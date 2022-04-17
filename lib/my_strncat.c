/*
** EPITECH PROJECT, 2021
** MY_STRNCAT
** File description:
** It's a program that concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int size = my_strlen(dest);
    int cmpt;

    for (cmpt = 0; src[cmpt] != '\0'; cmpt += 1) {
        dest[size + cmpt] = src[cmpt];
    }
    dest[size + cmpt] = '\0';
    return (dest);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = my_strlen(dest);
    int cmpt;

    if (nb == 0)
        dest = my_strcat(dest, src);
    else {
        for (cmpt = 0; cmpt <= nb && src[cmpt] != '\0'; cmpt += 1)
            dest[size + cmpt] = src[cmpt];
        dest[size + cmpt] = '\0';
    }
    return (dest);
}
