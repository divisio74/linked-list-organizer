/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** disp_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "src/shell.h"
#include "struct.h"
#include "organize.h"

int disp(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    hardware_t *current;
    hardware_t *previous;
    int i = 0;

    current = workshop->head;
    previous = NULL;
    i = workshop->next_id;
    while (current != NULL && (current)->id <= i) {
        printf("%s n°%d - %s.\n", current->type, current->id,
            current->name);
        previous = current;
        current = (current)->next;
    }
    return 0;
}
