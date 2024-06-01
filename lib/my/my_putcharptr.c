/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putchar
*/
#include "my.h"
#include <unistd.h>

void my_putcharptr(char c, int *ptr)
{
    write(1, &c, 1);
    (*ptr)++;
}
