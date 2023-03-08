/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exit
*/

#include "my.h"
#include "minishell.h"

int exec_exit(parameters_t *param)
{
    (void)param;
    exit(0);
    return (0);
}
