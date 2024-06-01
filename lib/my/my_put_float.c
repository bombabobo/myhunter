/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_put_float.c
*/
#include "my.h"
#include <stdio.h>

double num_negative(double nb, int *ptr)
{
    if (nb < 0) {
        my_putcharptr('-', ptr);
        nb = -nb;
    }
    return nb;
}

int if_my_put_float(double float_portion, int *ptr, int precision, int i)
{
    int n;

    if (i < precision) {
        float_portion = float_portion * 10;
        n = (int)(float_portion + 0.5);
        my_put_int(n, ptr);
    }
}

int my_put_float(double nb, int *ptr, int precision)
{
    int integer_portion = 0;
    double float_portion = 0;
    int i = 0;

    nb = num_negative(nb, ptr);
    integer_portion = (int)nb;
    my_put_int(integer_portion, ptr);
    my_putcharptr('.', ptr);
    float_portion = (nb - integer_portion);
    for (i; i < precision - 1; i++) {
        float_portion = float_portion * 10;
        integer_portion = (int)float_portion;
        my_putcharptr((integer_portion + '0'), ptr);
        float_portion = (float_portion - integer_portion);
    }
    if_my_put_float(float_portion, ptr, precision, i);
}
