/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const  *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (dest[i] != '\0') {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
