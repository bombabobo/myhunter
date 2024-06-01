/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strcapitalize
*/
#include <stdio.h>

char *my_strcapitalize(char *S)
{
    int i = 0;

    if (S[0] >= 97 && S[0] <= 122){
        S[0] = S[0] - 32;
    }
    for (i; S[i] != '\0'; i++){
        if ((S[i] < 'A' || S[i] > 'z') && S[i + 1] < 123 && S[i + 1] > 96){
            S[i + 1] = S[i + 1] - 32;
        }
        if (S[i] >= 'a' && S[i] <= 'z' && S[i + 1] >= 'A' && S[i + 1] <= 'Z'){
            S[i + 1] = S[i + 1] + 32;
        }
        if (S[i] >= '0' && S[i] <= '9' && S[i + 1] >= 'A' && S[i + 1] <= 'Z'){
            S[i + 1] = S[i + 1] + 32;
        }
    }
    return (S);
}
