/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** init_map
*/

#include "include.h"

char **init_map(int nb_line)
{
    char **map = malloc(sizeof(char *) * (nb_line + 1));
    int nb_space = nb_line * 2 - 1;
    int x = 0;
    int stick = 1;

    for (int i = 0; i != nb_line; i++) {
        map[i] = malloc(sizeof(char) * (nb_space + 1));
        map[i][nb_space] = 0;
    }
    for (int y = 0; y != nb_line; y++, x = 0) {
        for (; x != (nb_space / 2 - y); x++)
            map[y][x] = ' ';
        for (int nb_stick = 0; nb_stick != stick; nb_stick++, x++)
            map[y][x] = '|';
        for (; x != nb_space; x++)
            map[y][x] = ' ';
        stick = stick + 2;
    }
    return (map);
}

void init_total(game_t *game)
{
    int nb = 1;
    int total = 0;

    game->nb_on_line = malloc(sizeof(int) * game->nb_line);
    for (int i = 0; unfinish; i++) {
        total = total + nb;
        game->nb_on_line[i] = nb;
        nb = nb + 2;
    }
    game->nb_total = total;
}

void init_game(game_t *game, int nb_line, int less_max)
{
    game->map = init_map(nb_line);
    game->less_max = less_max;
    game->nb_line = nb_line;
    game->poss_line = nb_line;
    game->less = malloc(sizeof(int) * 2);
    game->less_save = malloc(sizeof(int) * 2);
    game->less_save[1] = -1;
    init_total(game);
}