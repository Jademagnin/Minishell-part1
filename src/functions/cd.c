/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd
*/

#include "my.h"
#include "minishell.h"

static char *get_target_dir(parameters_t *param, char *prev_dir)
{
    char *target_dir;
    if (param->cmds[1] == NULL || my_strcmp(param->cmds[1], "~") == 0) {
        target_dir = my_getenv("HOME", param->env);
    } else if (my_strcmp(param->cmds[1], "-") == 0) {
        target_dir = prev_dir;
    } else {
        target_dir = param->cmds[1];
    }
    return target_dir;
}

int handle_cd_err(char *target_dir)
{
    if (errno == ENOENT) {
        my_putstr(target_dir, 2);
        my_putstr(": No such file or directory.\n", 2);
        return 1;
    }
    if (errno == ENOTDIR) {
        my_putstr(target_dir, 2);
        my_putstr(": Not a directory.\n", 2);
        return 1;
    }
    if (errno == EACCES) {
        my_putstr(target_dir, 2);
        my_putstr(": Permission denied.\n", 2);
        return 1;
    }
    return 0;
}

int exec_cd(parameters_t* param)
{
    static char* prev_dir = NULL;
    if (!prev_dir) prev_dir = getcwd(NULL, 0);
    char* target_dir = get_target_dir(param, prev_dir);
    char* current_dir = getcwd(NULL, 0);
    if (current_dir == NULL) {
        perror("getcwd");
        return 1;
    }
    chdir(target_dir);
    if (handle_cd_err(target_dir)) return 1;

    free(prev_dir);
    prev_dir = current_dir;
    return 0;
}
