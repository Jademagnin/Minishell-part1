/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_pow
*/

int my_pow(int nb, int p)
{
    int limitult = 1;

    if (p < 0) return (0);
    for (int i = 0; i < p; i++) limitult *= nb;
    return (limitult);
}
