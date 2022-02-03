/*
** EPITECH PROJECT, 2021
** MY_FIND_PRIME_SUP
** File description:
** It's a program that return the prime greater than a number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int boolean = 0;

    for ( ; boolean != 1; nb += 1) {
        if (my_is_prime(nb) == 1) {
            boolean = 1;
            return (nb);
        }
    }
}
