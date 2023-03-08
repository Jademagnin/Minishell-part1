/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include "struct.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <signal.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <string.h>

    #define PATH_MAX 4096

typedef int (*FuncPtr)();

typedef void (*sighandler_t)(int);

int minish(char**env);
int exec_cd(parameters_t *parameters);
int exec_unsetenv(parameters_t *parameters);
int exec_setenv(parameters_t *parameters);
void handler(int signum);
int check_setenv_syntax(char **cmds);
int number_args(char **env, const char *value, int arg);
int execute_process(parameters_t *param);
int execute_command(parameters_t *param);
int exec_exit(parameters_t *param);
char *take_path(char *env);
int check_path(parameters_t *param, int set);
char *my_getenv(const char *name, char **env);
void free_all(char **str);
int check_disp(parameters_t *parameters);
char *extract_env(char *env);
int checking(char *input);
char *clean_str(char* str);
char *check_env(const char *limit, char **env);
int exec_env(parameters_t *parameters);
int interpret_return(int errno_status, int status, char *cmd);

#endif /* !MINISHELL_H_ */
