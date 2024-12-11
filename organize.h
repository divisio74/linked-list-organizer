/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** organize
*/

#include <stdio.h>
#include "src/shell.h"
#include "struct.h"

#ifndef INCLUDED_ORGANIZE_H
    #define INCLUDED_ORGANIZE_H
int is_valid_type(const char *type);
int add(void *data, char **args);
int my_strcmp(const char *s1, const char *s2);
char *my_strncpy(char *dest, const char *src, size_t n);
int add_token(workshop_t *workshop, char *type, char *name);




#endif
