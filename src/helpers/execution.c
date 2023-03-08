/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execution
*/

#include "my.h"
#include "minishell.h"

char *extract_env(char *env)
{
    if (env == NULL) {
        return NULL;
    }

    const char *end = my_strchr(env, '=');
    if (end == NULL) {
        return NULL;
    }

    size_t len = end - env;
    char *limit = malloc(len + 1);
    if (limit != NULL) {
        my_strncpy(limit, env, len);
        limit[len] = '\0';
    }

    return limit;
}

int number_args(char **env, const char *value, int arg)
{
    int nb = 0;
    int i = 0;
    if (env == NULL || value == NULL) {
        return -1;
    }
    if (arg == 0) {
        while (env[i] != NULL) {
            nb++;
            i++;
        }
    } else {
        while (env[i] != NULL && my_strcmp(env[i], value) != 0) {
            i++;
        }
        if (env[i] == NULL) {
            return -1;
        }
        nb = i;
    }
    return nb;
}

char *get_cmd_full_path(parameters_t *param)
{
    char *path_env = my_strdup(param->path);
    char *path = strtok(path_env, ":");
    char *cmd_path = NULL;
    char *full_path = NULL;
    while (path != NULL) {
        full_path = my_strcat(path, "/");
        full_path = my_strcat(full_path, param->cmds[0]);
        if (access(full_path, X_OK) == 0) {
            cmd_path = full_path;
            break;
        }
        path = strtok(NULL, ":");
        free(full_path);
    }
    return cmd_path;
}

int execute_command(parameters_t *param)
{
    int status;
    char *full_bin_path = get_cmd_full_path(param);
    if (full_bin_path != NULL) param->cmds[0] = full_bin_path;
    pid_t pid = fork();
    if (pid == -1) return 1;
    if (pid == 0) {
        execve(param->cmds[0], param->cmds, param->env);
        exit(interpret_return(errno, -1, param->cmds[0]));
    }
    pid_t ret = waitpid(pid, &status, 0);
    if (ret == -1) {
        my_putstr("Error: waitpid() failed.\n", 2);
        return 1;
    }

    return (interpret_return(errno, status, param->cmds[0]));
}
