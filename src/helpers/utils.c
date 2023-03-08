/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** utils
*/

#include "my.h"
#include "minishell.h"

int is_char_blank(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') return (1);
    return (0);
}

char *clean_str(char* str)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(str);

    while (is_char_blank(str[i])) i++;
    while (i < len) {
        if (!is_char_blank(str[i]) || (i > 0 && !is_char_blank(str[i - 1]))) {
            str[j++] = str[i];
        }
        i++;
    }
    if (j > 0 && is_char_blank(str[j - 1])) j--;

    str[j] = '\0';
    for (i = 0; i < j; i++)
        str[i] = (str[i] == '\t') ? ' ' : str[i];

    return (str);
}

char *my_getenv(const char *name, char **env)
{
    size_t len = my_strlen(name);

    while (*env != NULL) {
        if (my_strncmp(*env, name, len) == 0 && (*env)[len] == '=') {
            return &((*env)[len + 1]);
        }
        env++;
    }

    return NULL;
}

char *check_env(const char *limit, char **env)
{
    char *var;
    int i = 0;

    for (; env[i] != NULL; i++) {
        var = extract_env(env[i]);
        if (my_strcmp(limit, var) == 0) {
            free(var);
            break;
        }
        free(var);
    }
    if (env[i] == NULL)
        return NULL;
    else
        return env[i];
}

void free_all(char **str)
{
    if (str == NULL) {
        return;
    }

    char **p = str;
    while (*p != NULL) {
        free(*p);
        *p++ = NULL;
    }

    free(str);
}
