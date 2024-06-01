/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    char i = 0;

    for (char i = 0; src[i] != '\0' && n > 0; i++){
        dest[i] = src[i];
        n--;
    }
    dest[i + 1] = ('\0');
    return dest;
}
