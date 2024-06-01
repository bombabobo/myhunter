/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putchar
*/
#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
