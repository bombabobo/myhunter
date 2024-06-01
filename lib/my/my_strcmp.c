/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i; s1[i] != '\0' || s2[i] != '\0'; i++){
        if (s2[i] != s1[i]){
            return (s2[i] - s1[i]);
        }
    }
    return (s1[i] - s2[i]);
}
