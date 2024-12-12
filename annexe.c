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

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
        str[i] == '\v' || str[i] == '\f' || str[i] == '\r') {
        i++;
    }
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}

char *my_strtok(char *str, const char *delim)
{
    static char *saved_str = NULL;
    char *token_start;

    if (str != NULL)
        saved_str = str;
    if (saved_str == NULL)
        return NULL;
    while (*saved_str && my_strchr(delim, *saved_str))
        saved_str++;
    if (*saved_str == '\0')
        return NULL;
    token_start = saved_str;
    while (*saved_str && !my_strchr(delim, *saved_str))
        saved_str++;
    if (*saved_str != '\0') {
        *saved_str = '\0';
        saved_str++;
    } else
        saved_str = NULL;
    return token_start;
}

char *my_strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
