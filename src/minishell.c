/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

parameters_t *setup_parameters(char **env)
{
    parameters_t *parameters = malloc(sizeof(parameters_t));

    parameters->env = env;
    parameters->cmds = NULL;
    parameters->input = NULL;
    if (check_env("PATH", env)) {
        parameters->path = take_path(check_env("PATH", env));
    }

    return (parameters);
}

int exec_function(parameters_t *param)
{
    FuncPtr ptr_function[] = {exec_cd, exec_setenv, exec_unsetenv, exec_env,
                            exec_exit};
    const char *name_function[] = {"cd", "setenv", "unsetenv", "env", "exit"};
    int ret_code = -1;

    for (size_t i = 0; i < sizeof(ptr_function) / sizeof(*ptr_function); i++) {
        if (my_strcmp(name_function[i], param->cmds[0]) == 0) {
            ret_code = ptr_function[i](param);
            break;
        }
    }

    if (ret_code == -1) {
        ret_code = execute_command(param);
    }

    return ret_code;
}

int run_function(parameters_t *param)
{
    param->cmds = my_str_to_word_array(param->input, ' ');

    int ret_code = exec_function(param);
    free_all(param->cmds);
    return (ret_code);
}

int minish(char **env)
{
    size_t bufsize = 0; int ret_code = 0;
    parameters_t *param = setup_parameters(env);

    while (1) {
        signal(SIGINT, handler);
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "$> ", 3);
        }
        if (getline(&param->input, &bufsize, stdin) == -1) break;
        param->input = clean_str(param->input);
        if (checking(param->input) == 0) continue;
        ret_code = run_function(param);
    }
    free(param->input);
    free(param);
    return (ret_code);
}
