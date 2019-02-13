/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putstr
*/

#include "my_runner.h"

void my_putstr(char *str)
{
    while (*str != '\0') {
        write(1, str, 1);
        str += 1;
    }
}
