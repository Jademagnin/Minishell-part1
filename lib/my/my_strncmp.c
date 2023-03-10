/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_strncmp
*/

#include <stddef.h>

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    if (n == 0) {
        return 0;
    }

    while (n-- != 0 && *s1 == *s2) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0') {
            break;
        }
        s1++;
        s2++;
    }

    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
