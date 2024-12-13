/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.baud
** File description:
** annexe_2
*/
#include <unistd.h>
#include "src/shell.h"
#include "struct.h"
#include "organize.h"

void my_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

void my_putstr(const char *str)
{
    while (*str) {
        my_putchar(*str++);
    }
}

void my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_putnbr(n / 10);
    }
    my_putchar((n % 10) + '0');
}

void print_info(const char *type, int id, const char *name)
{
    my_putstr(type);
    my_putstr(" n°");
    my_putnbr(id);
    my_putstr(" - \"");
    my_putstr(name);
    my_putstr("\"");
}
