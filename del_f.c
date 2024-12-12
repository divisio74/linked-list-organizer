/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** del_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "src/shell.h"
#include "struct.h"
#include "organize.h"

int del(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    int i;
    char *token_pair;
    char *pair;
    int id;
    int z = 0;

    for (i = 0; args[i] != NULL; i++) {
        token_pair = args[i];
        pair = my_strtok(token_pair, ",");
        while (pair != NULL) {
            id = my_atoi(pair);
            z_id(z, id);
            del_print(workshop, id, z);
            pair = my_strtok(NULL, ",");
        }
        z++;
    }
    return 0;
}

int z_id(int z, int id)
{
    if (z > 0)
        id = id - z;
}

int del_print(workshop_t *workshop, int id, int z)
{
    hardware_t *current;
    hardware_t *previous;

    if (del_cpf(&current, &previous, workshop, id) == 84)
        return 84;
    printf("%s n°%d - %s deleted.\n", current->type, current->id + z,
        current->name);
    free(current);
}

int del_cpf(hardware_t **current, hardware_t **previous,
    workshop_t *workshop, int id)
{
    *current = workshop->head;
    *previous = NULL;
    while (*current != NULL && (*current)->id != id) {
        *previous = *current;
        *current = (*current)->next;
    }
    if (*current == NULL)
        return 84;
    if (*previous == NULL)
        workshop->head = (*current)->next;
    else
        (*previous)->next = (*current)->next;
    setup_id(workshop, id);
    workshop->next_id--;
    return 0;
}

void setup_id(workshop_t *workshop, int start_id)
{
    hardware_t *current = workshop->head;

    while (current != NULL) {
        if (current->id > start_id)
            current->id--;
        current = current->next;
    }
}
