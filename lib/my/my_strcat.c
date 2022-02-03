/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** It's a program that concatenates two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int size = my_strlen(dest);
    int cmpt;

    for (cmpt = 0; src[cmpt] != '\0'; cmpt += 1)
        dest[size + cmpt] = src[cmpt];
    dest[size + cmpt] = '\0';
    return (dest);
}
