/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct parameters_s {
    char* input;
    char** env;
    char* path;
    char** cmds;
} parameters_t;

#endif /* !STRUCT_H_ */
