/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** setenv
*/

#include "my.h"
#include "minishell.h"

void add_env(parameters_t *parameters, char *key, char *value)
{
    char *new_env = NULL;
    new_env = my_strcat(key, "=");
    new_env = my_strcat(new_env, value);
    int i = 0;
    for (; parameters->env[i] != NULL; i++) {
        if (my_strncmp(parameters->env[i], key, my_strlen(key)) == 0 &&
        parameters->env[i][my_strlen(key)] == '=') {
            parameters->env[i] = new_env;
            return;
        }
    }
    parameters->env[i] = new_env;
    parameters->env[i + 1] = NULL;
}

int exec_setenv(parameters_t *parameters)
{
    char *key = parameters->cmds[1];
    char *value = parameters->cmds[2];

    if (key == NULL) {
        exec_env(parameters);
        return (0);
    }
    if (value == NULL) {
        value = malloc(sizeof(char) * 1);
        value[0] = '\0';
    }
    if (check_setenv_syntax(parameters->cmds) == 1) return (1);

    add_env(parameters, key, value);
    return (0);
}
