/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i; s1[i] != '\0' || s2[i] != '\0'; i++){
        n--;
        if (s2[i] != s1[i] || n == 0){
            return (s2[i] - s1[i]);
        }
    }
    return (s1[i] - s2[i]);
}
