/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strlowcase
*/
#include <stdio.h>

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++){
        if (str[i] <= 90 && str[i] >= 65){
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
