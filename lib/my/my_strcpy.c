/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    char i = 0;

    for (i; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = ('\0');
    return dest;
}
