/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_putstr
*/

#include "include.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != 0)
        i = i + 1;
    return (i);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        my_putchar(str[i]);
}