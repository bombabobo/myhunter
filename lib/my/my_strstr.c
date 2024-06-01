/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strstr
*/
#include <stdio.h>

char calclen(const char *str)
{
    char len = 0;

    for (char c = 0; str[c] != '\0'; c++){
        len++;
    }
    return len;
}

char *my_strstr(char *str, char const *to_find)
{
    int lenstr = calclen(str);
    int lentofind = calclen(to_find);
    int verif = 0;

    if (lentofind <= 0)
        return str;
    for (int i = 0; i < lenstr; i++){
        verif = 0;
        for (int j = 0; j < lentofind && str[i + j] == to_find[j]; j++){
            verif++;
        }
        if (verif == lentofind){
            return (char *)&str[i];
        }
    }
    return 0;
}
