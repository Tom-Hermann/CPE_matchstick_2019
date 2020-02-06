/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the number given as parameter
*/

#include "include.h"

void my_put_nbr(int nb)
{
    int n = 1;
    if (nb == 0)
        my_putchar (48);
    if (nb < 0) {
        nb = nb * -1;
        my_putchar ('-');
    }
    while (nb / n != 0) {
        n = n * 10;
    }
    n = n / 10;
    while (n != 0) {
        my_putchar (nb / n + 48);
        nb = nb % n;
        n = n / 10;
    }
}