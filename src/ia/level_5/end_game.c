/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** end_game
*/

#include "include.h"

void set_end_game(game_t *game)
{
    int i = 0;

    for (; unfinish &&  game->nb_on_line[i] <= 1; i++);
    if (i == game->nb_line)
        return;
    game->less[0] = i + 1;
    if (game->poss_line % 2 == 0 && game->nb_on_line[i] <= game->less_max &&
        game->nb_on_line[i] != 0)
        game->less[1] = game->nb_on_line[i];
    else if (game->poss_line % 2 == 1 &&
        (game->nb_on_line[i] - 1) <= game->less_max)
        game->less[1] = game->nb_on_line[i];
    else if (game->nb_on_line[i] > game->less_max + 1 &&
        game->nb_on_line[i] - game->less_max - 2 <= game->less_max &&
        game->nb_on_line[i] - game->less_max - 2 != 0)
        game->less[1] = game->nb_on_line[i] - game->less_max - 2;
}

int end_game(game_t *game)
{
    int nb_line_one_more = 0;

    for (int i = 0; unfinish; i++) {
        if (game->nb_on_line[i] > 1)
            nb_line_one_more = nb_line_one_more + 1;
    }
    if (nb_line_one_more > 1)
        return (0);
    return (1);
}