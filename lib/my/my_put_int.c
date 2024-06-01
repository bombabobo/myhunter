/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_put_int
*/
#include "my.h"

int my_put_int(int nb, int *ptr)
{
    int c;
    char neg;

    c = '0';
    if (nb < 0){
        my_putcharptr('-', ptr);
        nb *= -1;
    }
    while (nb % 10 != 0){
        nb--;
        c++;
    }
    nb /= 10;
    if (nb != 0){
        my_put_int(nb, ptr);
    }
    my_putcharptr(c, ptr);
}
