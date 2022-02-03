/*
** EPITECH PROJECT, 2021
** MY_STR_ISALPHA
** File description:
** It's a program that return if a string contain non alphabeticals char
*/

int my_strlen(char const *str);

int test_lowcase(char const *str, int cmpt, int boolean)
{
    char cmpt_ascii;
    for (cmpt_ascii = 65; cmpt_ascii <= 90; cmpt_ascii += 1) {
        if (str[cmpt] == cmpt_ascii)
            boolean = 1;
    }
    return (boolean);
}

int test_upcase(char const *str, int cmpt, int boolean)
{
    char cmpt_ascii;
    for (cmpt_ascii = 97; cmpt_ascii <= 122; cmpt_ascii += 1) {
        if (str[cmpt] == cmpt_ascii)
            boolean = 1;
    }
    return (boolean);
}

int my_str_isalpha(char const *str)
{
    int cmpt;
    int boolean;
    if (my_strlen(str) <= 0)
        return (0);
    for (cmpt = 0; cmpt < my_strlen(str); cmpt += 1) {
        boolean = 0;
        boolean = test_lowcase(str, cmpt, boolean);
        boolean = test_upcase(str, cmpt, boolean);
        if (boolean == 0) {
            return (0);
        }
    }
    return (1);
}
