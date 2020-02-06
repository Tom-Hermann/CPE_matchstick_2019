/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return a  number  sent as a string
*/

#include "include.h"

int shorty(int i, char const *str)
{
    if (str[i + 1] >= 2 && str[i + 2] >= 1 && str[i + 3] >= 4
    && str[i + 4] >= 7 && str[i + 5] >= 4 && str[i + 6] >= 8
    && str[i + 7] >= 3 && str[i + 8] >= 2 && str[i + 9] >= 2)
        return (0);
    return (1);
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int nbr_neg = 1;
    int c = 0;

    if (str[0] == '-')
        nbr_neg = -1;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        if (shorty(i, str) == 0)
            return (0);
        if (str[i] > 42 && str[i] < 58 ) {
            c = str[i] - '0';
            nbr = (nbr + c) * 10; }
        i = i + 1;
    }
    nbr = nbr / 10;
    nbr = nbr * nbr_neg;
    return (nbr);
}
