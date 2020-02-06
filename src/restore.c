/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** restore
*/

#include "include.h"

void normal_restor(game_t *game, int *less)
{
    int x = 0;
    int nb_tmp = game->nb_on_line[less[0] - 1];

    for (; game->map[less[0] - 1][x] == ' '; x++);
    for (; game->map[less[0] - 1][x] == '|'; x++);
    for (int i = 0; i != less[1]; i++, x++)
        game->map[less[0] - 1][x] = '|';
    game->nb_on_line[less[0] - 1] = nb_tmp + less[1];
    game->nb_total = game->nb_total + less[1];
}

void line_null(game_t *game, int *less)
{
    int x = game->nb_line - less[0];
    int nb_tmp = game->nb_on_line[less[0] - 1];

    for (int i = 0; i != less[1]; i++, x++)
        game->map[less[0] - 1][x] = '|';
    game->nb_on_line[less[0] - 1] = nb_tmp + less[1];
    game->nb_total = game->nb_total + less[1];
}

void restore_map(game_t *game)
{
    if (game->nb_on_line[game->less[0] - 1] == 0)
        line_null(game, game->less);
    else
        normal_restor(game, game->less);
    if (game->nb_on_line[game->less_save[0] - 1] == 0)
        line_null(game, game->less_save);
    else
        normal_restor(game, game->less_save);
}