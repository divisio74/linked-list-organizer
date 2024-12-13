/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** sort_f
*/
#include <stdlib.h>
#include "src/shell.h"
#include "struct.h"
#include "organize.h"

int get_list_length(workshop_t *workshop)
{
    int length = 0;
    hardware_t *current = workshop->head;

    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void swap_f(hardware_t *a, hardware_t *b)
{
    int temp_id = a->id;
    char temp_type[30];
    char temp_name[30];

    my_strncpy(temp_type, a->type, 30);
    my_strncpy(temp_name, a->name, 30);
    a->id = b->id;
    my_strncpy(a->type, b->type, 30);
    my_strncpy(a->name, b->name, 30);
    b->id = temp_id;
    my_strncpy(b->type, temp_type, 30);
    my_strncpy(b->name, temp_name, 30);
}

int swapped_f(workshop_t *workshop, int length)
{
    hardware_t *ptr1 = workshop->head;
    int swapped = 0;
    int j = 0;

    for (j; j < length - 1; j++) {
        if (ptr1->next != NULL && ptr1->id > ptr1->next->id) {
            swap_f(ptr1, ptr1->next);
            swapped = 1;
        }
        ptr1 = ptr1->next;
    }
    return swapped;
}

int sort(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    int length = get_list_length(workshop);
    int i = 0;
    int swapped = 0;

    if (length <= 1) {
        return 0;
    }
    for (i; i < length - 1; i++) {
        swapped = swapped_f(workshop, length - i);
        if (swapped == 0)
            break;
    }
    return 0;
}
