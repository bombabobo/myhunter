/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_compute_square_root
*/
#include <unistd.h>
#include <stdio.h>

int my_compute_square_root(int nb)
{
    long int res = 100;

    if (nb < 0)
        return 0;
    for (long int i = 100; i * i < nb; i += 100) {
        res = i;
    }
    if (res * res == nb)
        return res;
    res -= 100;
    for (res; res * res < nb; res++) {
    }
    if (res * res != nb)
        return 0;
    return (res);
}
