/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** sppr_line
*/

#include "include.h"

void sppr_line_pair(game_t *game)
{
    int i = 0;

    for (; unfinish && game->nb_on_line[i] != 2; i++);
    if (unfinish) {
        game->less[0] = i + 1;
        game->less[1] = 2;
        return;
    }
    for (i = 0; unfinish; i++) {
        for (; unfinish &&  game->nb_on_line[i] <= 1; i++);
        game->less[0] = i + 1;
        game->less[1] = 2;
        return;
    }
}

void sppr_line_unpair(game_t *game)
{
    int i = 0;

    for (; unfinish && game->nb_on_line[i] != 1; i++);
    if (unfinish) {
        game->less[0] = i + 1;
        game->less[1] = 1;
        return;
    }
    for (i = 0; i != game->nb_line; i++) {
        for (; unfinish &&  game->nb_on_line[i] <= 0; i++);
        game->less[0] = i + 1;
        game->less[1] = 1;
        return;
    }
}
