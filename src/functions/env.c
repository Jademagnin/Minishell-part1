/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** env
*/

#include "minishell.h"
#include "my.h"

int exec_env(parameters_t *param)
{
    for (int i = 0; param->env[i] != NULL; i++) {
        write(1, param->env[i], my_strlen(param->env[i]));
        write(1, "\n", 1);
    }
    return 0;
}
