/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_compute_power_rec
*/
#include <unistd.h>
#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    long int res = nb;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p - 1 > 0){
        res *= my_compute_power_rec(nb, p - 1);
    }
    return res;
}
