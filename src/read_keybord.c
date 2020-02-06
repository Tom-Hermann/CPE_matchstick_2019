/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** read_keybord
*/

#include "include.h"

char *add_memori(char *str, char buffer)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    while (str[i] != 0) {
        res[i] = str[i];
        i = i + 1;
    }
    res[i] = buffer;
    res[i + 1] = 0;
    return (res);
}

char *init_read(void)
{
    char *res = malloc(sizeof(char) * 2);

    res = "\0\0";
    if (read(0, res, 1) == 0)
        return (NULL);
    return (res);
}

char *read_output(void)
{
    char *str = NULL;
    char buffer[2] = "\0\0";

    if ((str = init_read()) == NULL)
        return (NULL);
    while (buffer[0] !=  '\n') {
        if (read(0, buffer, 1) == 0)
            return (NULL);
        str = add_memori(str, buffer[0]);
    }
    return (str);
}