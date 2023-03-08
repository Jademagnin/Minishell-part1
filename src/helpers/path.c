/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** path
*/

#include "my.h"
#include "minishell.h"

char *take_path(char *env)
{
    if (env == NULL) {
        return NULL;
    }

    char *limit = NULL;
    char *start = my_strchr(env, '=') + 1;
    if (start != NULL) {
        size_t len = my_strlen(start);
        limit = malloc(len + 1);
        if (limit != NULL) {
            my_strncpy(limit, start, len);
            limit[len] = '\0';
        }
    }

    return limit;
}
