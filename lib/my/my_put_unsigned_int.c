/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_put_unsigned_int
*/
#include "my.h"

unsigned int my_put_unsigned_int(unsigned int nb, int *ptr)
{
    int c = '0';

    while (nb % 10 != 0){
        nb--;
        c++;
    }
    nb /= 10;
    if (nb != 0){
        my_put_unsigned_int(nb, ptr);
    }
    my_putcharptr(c, ptr);
}
