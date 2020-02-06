/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** error_turn
*/

#include "include.h"

void suite_error_line(game_t *game, char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] != '\n' && (buffer[i] < '0' || buffer[i] > '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            error_line(game);
            return;
        }
    game->less[0] = my_getnbr(buffer);
    if (game->less[0] < 1 || game->less[0] > game->nb_line) {
        my_putstr("Error: this line is out of range\n");
        error_line(game);
    }
}

void error_line(game_t *game)
{
    char *buffer = NULL;

    my_putstr("Line: ");
    if ((buffer = read_output()) == 0 || buffer == NULL) {
        game->less[0] = -1;
        return;
    }
    if (buffer[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        error_line(game);
        return;
    }
    if (key_word(game, buffer)) {
        error_line(game);
        return;
    }
    suite_error_line(game, buffer);
}

void not_good_number(game_t *game, char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] != '\n' && (buffer[i] < '0' || buffer[i] > '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            error_line(game);
            if (game->less[0] != -1)
                error_match(game);
            return;
        }
    game->less[1] = my_getnbr(buffer);
    if (game->less[1] > game->nb_on_line[game->less[0] - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        error_line(game);
        if (game->less[0] != -1)
            error_match(game);
    }
    else if (game->less[1] < 1 || game->less[1] > game->less_max) {
        my_putstr("Error: you have to remove at least one match\n");
        error_line(game);
        if (game->less[0] != -1)
            error_match(game);
    }
}

void error_match(game_t *game)
{
    char *buffer = NULL;

    my_putstr("Matches: ");
    if ((buffer = read_output()) == NULL) {
        game->less[0] = -1;
        return;
    }
    if (buffer[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        error_line(game);
        if (game->less[0] != -1)
            error_match(game);
        return;
    }
    if (key_word(game, buffer)) {
        error_line(game);
        if (game->less[0] != -1)
            error_match(game);
        return;
    }
    not_good_number(game, buffer);
}