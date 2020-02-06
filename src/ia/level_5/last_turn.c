/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** last_turn
*/

#include "include.h"

void loose(game_t *game)
{
    int i = 0;

    for (; unfinish &&  game->nb_on_line[i] != 1; i++);
    game->less[0] = i + 1;
    game->less[1] = 1;
}

int condition_win(game_t *game)
{
    for (int i = 0; unfinish; i++) {
        if (game->nb_on_line[i] == game->nb_total &&
            game->nb_on_line[i] - 1 <= game->less_max)
            return (1);
        else if (game->nb_on_line[i] == game->nb_total - 1 &&
            game->nb_on_line[i] <= game->less_max)
            return (1);
    }
    return (0);
}

void win(game_t *game)
{
    int i = 0;

    game->less[1] = game->nb_total - 1;
    for (;unfinish &&  game->nb_on_line[i] < game->nb_total - 1; i++);
    game->less[0] = i + 1;
}

void last_turn(game_t *game)
{

    game->less[1] = -1;
    if (game->nb_total == 1)
        loose(game);
    else if (condition_win(game))
        win(game);
}