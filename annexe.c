/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** annexe
*/

#include <stdio.h>
#include "src/shell.h"
#include "struct.h"
#include "organize.h"

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
