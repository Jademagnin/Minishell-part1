/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_str_isalnum
*/

int my_char_isalnum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

int my_str_isalnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_isalnum(str[i]) == 0) return 0;
        i++;
    }
    return 1;
}
