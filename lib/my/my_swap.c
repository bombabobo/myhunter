/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_swap
*/
#include <unistd.h>
#include <stdio.h>

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
