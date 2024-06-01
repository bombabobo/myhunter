/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** decimal_to_hexa
*/
#include "my.h"

void decimal_to_hexa(int decinum, int *ptr, int l)
{
    int i = 1;
    char hexanum[10];
    int temp;

    while (decinum != 0){
        temp = decinum % 16;
        if (temp < 10)
            temp = temp + '0';
        else
            temp = temp + 55 + 32 * l;
        hexanum[i] = temp;
        i++;
        decinum = decinum / 16;
    }
    for (int j = i - 1; j > 0; j--)
        my_putcharptr(hexanum[j], ptr);
}
