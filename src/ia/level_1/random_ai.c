/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** random_ai
*/

#include "include.h"

void level_1(game_t *game)
{
    srand(time(0));
    if (game->nb_total == 1) {
        loose(game);
        return;
    }
    game->less[0] = rand() % game->nb_line;
    if (game->nb_on_line[game->less[0]] == 0) {
        level_1(game);
        return;
    }
    game->less[0] = game->less[0] + 1;
    game->less[1] = 0;
    while (game->less[1] == 0 || game->less[1] > game->less_max)
        game->less[1] = rand() % game->nb_on_line[game->less[0] - 1];
    game->less[1] = game->less[1] + 1;
}