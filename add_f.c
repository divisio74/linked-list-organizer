/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** add_f
*/

#include <stdlib.h>
#include "src/shell.h"
#include "struct.h"
#include "organize.h"

int add(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    char *type;
    char *name;

    for (int i = 0; args[i] != NULL; i += 2) {
        type = args[i];
        name = args[i + 1];
        if (type == NULL || name == NULL)
            return 84;
        if (!is_valid_type(type))
            return 84;
        add_process(workshop, type, name);
    }
    return 0;
}

int add_process(workshop_t *workshop, char *type, char *name)
{
    hardware_t *new_hardware = malloc(sizeof(hardware_t));

    my_strncpy(new_hardware->type, type, 30);
    my_strncpy(new_hardware->name, name, 30);
    new_hardware->id = workshop->next_id;
    workshop->next_id++;
    new_hardware->next = workshop->head;
    workshop->head = new_hardware;
    print_info(new_hardware->type, new_hardware->id, new_hardware->name);
    my_putstr(" added.\n");
    return 0;
}

int is_valid_type(const char *type)
{
    const char *list_types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};
    const int nb = 5;

    for (int i = 0; i < nb; i++) {
        if (my_strcmp(type, list_types[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
