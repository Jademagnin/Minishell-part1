/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}
