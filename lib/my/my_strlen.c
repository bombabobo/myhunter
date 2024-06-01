/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int c = 0;
    int nb = 0;

    while (str[c] != '\0'){
        nb++;
        c++;
    }
    return (nb);
}
