/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** usefull
*/

#include "include.h"

void change_map(game_t *game)
{
    int x = 0;
    int nb_tmp = game->nb_on_line[game->less[0] - 1];

    for (; game->map[game->less[0] - 1][x] == ' '; x++);
    for (; game->map[game->less[0] - 1][x] == '|'; x++);
    x = x - 1;
    for (int i = 0; i != game->less[1]; i++, x--)
        game->map[game->less[0] - 1][x] = ' ';
    game->nb_on_line[game->less[0] - 1] = nb_tmp - game->less[1];
    if (game->nb_on_line[game->less[0] - 1] == 0)
        game->poss_line = game->poss_line - 1;
    game->nb_total = game->nb_total - game->less[1];
}

void display_map(game_t *game)
{
    int max_line = game->nb_line;

    max_line = max_line * 2 - 1;
    for (int i = 0; i != max_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; unfinish; i++) {
        my_putchar('*');
        my_putstr(game->map[i]);
        my_putchar('*');
        my_put_nbr(game->nb_on_line[i]);
        my_putchar('\n');
    }
    for (int i = 0; i !=  max_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
    if (game->nb_total != 0)
        my_putchar('\n');
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != 0; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}