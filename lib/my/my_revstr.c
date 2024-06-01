/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_revstr
*/

void swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;

    for (int c = 0; str[c] != '\0'; c++){
        j++;
    }
    while (i < j){
        swap(&str[j], &str[i]);
        i++;
        j--;
    }
    str[i + 1] = '\0';
    return (str);
}
