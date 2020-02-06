/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** key_word
*/

#include "include.h"

void help(game_t *game)
{
        last_turn(game);
        if (game->less[1] == -1)
            level_4(game);
        my_putstr("I advise you to removed ");
        my_put_nbr(game->less[1]);
        my_putstr(" match(es) from line ");
        my_put_nbr(game->less[0]);
        my_putchar('\n');
        game->less[1] = -1;
}

int key_word(game_t *game, char *buffer)
{
    if (my_strcmp(buffer, "help\n")) {
        help(game);
        return (1);
    }
    else if (my_strcmp(buffer, "cancel\n")) {
        if (game->less_save[1] != -1 && game->less[1] != -1) {
            restore_map(game);
            my_putstr("Welcome to the past\n");
            display_map(game);
            game->less[1] = -1;
        }
        else
            my_putstr("You can't go back\n");
        return (1);
    }
    return (0);
}
