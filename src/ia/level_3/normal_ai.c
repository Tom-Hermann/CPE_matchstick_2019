/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** normal_ai
*/

#include "include.h"

void level_3(game_t *game)
{
    if (game->less[1] != -1)
        return;
    if (game->nb_total % 2 == 0)
        pair_total(game);
    else
        unpair_total(game);
    if (game->less[1] != -1)
        return;
    set_line_max_plus_one(game);
    if (game->less[1] != -1)
        return;
    if (game->nb_total % 2 == 0)
        sppr_line_pair(game);
    else
        sppr_line_unpair(game);
}