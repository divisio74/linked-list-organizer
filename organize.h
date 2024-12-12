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
int del(void *data, char **args);
int disp(void *data, char **args);
int del_cpf(hardware_t **current, hardware_t **previous,
    workshop_t *workshop, int id);
int my_strcmp(const char *s1, const char *s2);
char *my_strncpy(char *dest, const char *src, size_t n);
int add_token(workshop_t *workshop, char *type, char *name);
int my_atoi(const char *str);
char *my_strtok(char *str, const char *delim);
char *my_strchr(const char *str, int c);
void setup_id(workshop_t *workshop, int start_id);
int del_print(workshop_t *workshop, int id, int z);
int z_id(int z, int id);



#endif
