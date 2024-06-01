/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_put_ptr
*/
#include "my.h"

int my_put_ptr(unsigned long nb, int *ptr)
{
    int i = 1;
    char hexanum[15];
    int temp;

    my_putstrptr("0x", ptr);
    while (nb != 0) {
        temp = nb % 16;
        if (temp < 10)
            temp = temp + '0';
        else
            temp = temp + 87;
        hexanum[i] = temp;
        i++;
        nb = nb / 16;
    }
    for (int j = i - 1; j > 0; j--)
        my_putcharptr(hexanum[j], ptr);
}
