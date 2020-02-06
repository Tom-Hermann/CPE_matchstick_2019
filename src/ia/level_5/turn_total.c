/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** turn_total
*/

#include "include.h"

void pair_total (game_t *game)
{
    if (game->poss_line % 2 == 0) {
        for (int i = 0; unfinish; i++) {
            for (; unfinish &&  game->nb_on_line[i] <= 2; i++);
            if (game->less_max >= game->nb_on_line[i] - 2) {
                game->less[1] = game->nb_on_line[i] - 2;
                game->less[0] = i + 1;
                return;
            }
        }
    }
    else {
        for (int i = 0; unfinish; i++) {
            for (; unfinish &&  game->nb_on_line[i] < 2; i++);
            if (game->less_max >= game->nb_on_line[i] - 1) {
                game->less[1] = game->nb_on_line[i] - 1;
                game->less[0] = i + 1;
                return;
            }
        }
    }
}

void unpair_total(game_t *game)
{
    for (int i = 0; unfinish; i++) {
        for (; unfinish &&  game->nb_on_line[i] >= 1; i++);
        if (i == game->nb_line)
            return;
        if (game->less_max <= game->nb_on_line[i] - 1) {
            game->less[1] = game->nb_on_line[i] - 1;
            game->less[0] = i + 1;
            return;
        }
    }
}