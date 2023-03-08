/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "my.h"
#include "minishell.h"

//crash run simple command
//invalid exit status 11 core dump, pas num segfault 139
//div 0 exit status 8 but 134
//path passent tous
//setenv crash 139
//cd error message exit status 1
//len formatimg space and tab crash
//unsetenv crash
//test bin not compatible : bin pas de la bonne archi pour mon processeur

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac != 1) return (84);
    if (env == NULL) return (84);

    int ret_code = minish(env);
    if (isatty(0)) my_putstr("exit\n", 1);
    return (ret_code);
}
