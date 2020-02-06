/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** set_option
*/

#include "include.h"

void error_victori(game_t *game)
{
    if (game->many_victori < 1) {
        my_putstr("Error: invalide number ");
        my_putstr("(number greater than zero expected)\n");
        set_bo(game);
        return;
    }
}

void set_bo(game_t *game)
{
    char *buffer = NULL;

    my_putstr("How many victory for win : ");
    if ((buffer = read_output()) == NULL) {
        game->difficult = - 1;
        return;
    }
    if (buffer[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        set_bo(game);
        return;
    }
    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] != '\n' && (buffer[i] < '0' || buffer[i] > '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            set_bo(game);
            return;
        }
    game->many_victori = my_getnbr(buffer);
    error_victori(game);
}

void difficult_letter(game_t *game, char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] != '\n' && (buffer[i] < '0' || buffer[i] > '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            set_difficult(game);
            return;
        }
    game->difficult = my_getnbr(buffer);
    if (game->difficult < 1 || game->difficult > 4) {
        level_ia();
        set_difficult(game);
        return;
    }
}

void set_difficult(game_t *game)
{
    char *buffer = NULL;

    my_putstr("Difficult : ");
    if ((buffer = read_output()) == NULL) {
        game->difficult = - 1;
        return;
    }
    if (buffer[0] == '\n') {
        my_putstr("Error: invalid input (positive number expected)\n");
        set_difficult(game);
        return;
    }
    difficult_letter(game, buffer);
}

void ask_to_player(game_t *game)
{
    game->difficult = 0;
    set_bo(game);
    if (game->difficult != -1)
        set_difficult(game);
    }