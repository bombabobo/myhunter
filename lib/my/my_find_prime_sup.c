/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_find_prime_sup
*/

#include <unistd.h>
#include <stdio.h>

int prime(int nb)
{
    long int i = 3;

    if (nb == 2)
        return 1;
    if (nb <= 1 || nb % 2 == 0)
        return (0);
    for (i; i * i < nb; i += 2){
        if (nb % i == 0)
            return 0;
    }
    if (nb % i == 0)
        return 0;
    return 1;
}

int my_find_prime_sup(int nb)
{
    if (prime(nb) != 1){
        while (prime(nb) != 1){
            nb += 1;
        }
    }
    return nb;
}
