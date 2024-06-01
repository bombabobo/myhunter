/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putstr
*/
#include "my.h"
#include <unistd.h>

int my_putstrptr(char const *str, int *ptr)
{
    while (*str != 0){
        write(1, &*str, 1);
        (*ptr)++;
        str++;
    }
}
