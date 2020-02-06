/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** basic_ai
*/

#include "include.h"

void level_2(game_t *game)
{
    set_line_max_plus_one(game);
    if (game->less[1] != -1)
        return;
    if (game->nb_total % 2 == 0)
        sppr_line_pair(game);
    else
        sppr_line_unpair(game);
}