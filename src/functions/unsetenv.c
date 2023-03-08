/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** unsetenv
*/

#include "my.h"
#include "minishell.h"

void loop_unsetenv(parameters_t *parameters, int i, int j)
{
    for (j = i; parameters->env[j] != NULL; j++) {
        parameters->env[j] = parameters->env[j + 1];
    }
    parameters->env[j] = NULL;
}

int exec_unsetenv(parameters_t *parameters)
{
    char *var; int j = 0; int check = 0;
    if (parameters->cmds[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    for (int i = 0; parameters->env[i] != NULL; i++) {
        var = extract_env(parameters->env[i]);
        if (my_strcmp(parameters->cmds[1], var) == 0) {
            loop_unsetenv(parameters, i, j);
            check = 1;
        }
        free(var);
        if (check == 1) {
            break;
        }
    }
    return (0);
}
