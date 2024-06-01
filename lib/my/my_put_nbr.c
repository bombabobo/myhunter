/*
** EPITECH PROJECT, 2023
** 03-Github
** File description:
** my_put_nbr
*/
#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    int c;
    char neg;

    c = '0';
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    while (nb % 10 != 0){
        nb--;
        c++;
    }
    nb /= 10;
    if (nb != 0){
        my_put_nbr(nb);
    }
    my_putchar(c);
}
