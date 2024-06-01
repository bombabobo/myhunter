/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strupcase
*/
#include <stdio.h>

char *my_strupcase(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++){
        if (str[i] < 123 && str[i] > 96){
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
