/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** decimal_to_octal
*/
#include "my.h"

void decimal_to_octal(int decinum, int *ptr)
{
    int octalnum = 0;
    int countval = 1;
    int remainder;

    while (decinum != 0) {
        remainder = decinum % 8;
        octalnum += remainder * countval;
        countval = countval * 10;
        decinum /= 8;
    }
    my_put_int(octalnum, ptr);
}
