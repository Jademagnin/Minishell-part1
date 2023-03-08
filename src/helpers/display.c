/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** display
*/

#include "my.h"
#include "minishell.h"

void handler(int signum)
{
    int wstat = 0;
    if (signum == SIGINT && getpid() != 0) {
        waitpid(-1, &wstat, 0);
        if (wstat == 0)
            write(1, "\n$> ", 4);
    }
}
