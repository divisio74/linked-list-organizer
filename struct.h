/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H
typedef struct hardware {
    char name[30];
    char type[30];
    int id;
    struct hardware *next;
} hardware_t;

typedef struct workshop {
    hardware_t *head;
    int next_id;
} workshop_t;

#endif
