/*
** EPITECH PROJECT, 2019
** my_putnbr.c
** File description:
** putnbr
*/

#include <stdio.h>
#include <stdlib.h>

char *my_putnbr(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int j = 1;

    while ((nb / j) >= 10)
        j = j * 10;
    while (j > 0) {
        str[i] = (nb/j) % 10 + '0';
        j = j / 10;
        i = i + 1;
    }
    return (str);
}
