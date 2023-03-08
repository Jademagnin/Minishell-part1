/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** errors
*/

#include "my.h"
#include "minishell.h"

int checking(char *input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && input[i] != '\n' && input[i] != '\t') {
            return 1;
        }
    }
    return (0);
}

int check_setenv_syntax(char** cmds)
{
    char* key = cmds[1];

    if (cmds[1] == NULL) {
        write(2, "setenv: Too few arguments.\n", 27); return 1;
    }
    if (cmds[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28); return 1;
    }
    if (!my_char_isalpha(key[0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    if (!my_str_isalnum(key)) {
        write(2, "setenv: Variable name must contain alphanumeric", 47);
        write(2, " characters.\n", 13);
        return 1;
    }
    return 0;
}

int threat_errno(int errno_status, char *cmd)
{
    if (errno_status == ENOENT) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Command not found.\n", 21);
        return (1);
    }
    if (errno_status == EACCES) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Permission denied.\n", 21);
        return (1);
    }
    if (errno_status == ENOEXEC) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
        return (1);
    }
    return (0);
}

int interpret_return(int errno_status, int status, char *cmd)
{
    if (!WIFSIGNALED(status) && status != -1)
        return (WEXITSTATUS(status));

    if (WTERMSIG(status) == 11) {
        write(2, "Segmentation fault", 18);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
        return (139);
    }
    if (WTERMSIG(status) == 8) {
        write(2, "Floating exception", 18);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
        return (136);
    }
    return (threat_errno(errno_status, cmd));
}
