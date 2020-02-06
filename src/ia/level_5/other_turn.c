/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** other_turn
*/

#include "include.h"

void set_line_max_plus_one(game_t *game)
{
    for (int i = 0; unfinish; i++) {
        for (; unfinish &&  game->nb_on_line[i] <= game->less_max + 1; i++);
        if (i == game->nb_line)
            return;
        if (game->less_max >= game->nb_on_line[i] - (game->less_max + 1)) {
            game->less[0] = i + 1;
            game->less[1] = game->nb_on_line[i] - (game->less_max + 1);
            return;
        }
    }
}

void level_4(game_t *game)
{
    if (game->less_max != 1) {
        if (end_game(game))
            set_end_game(game);
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
    else
        sppr_line_unpair(game);
}