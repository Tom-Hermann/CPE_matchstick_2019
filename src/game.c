/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** game
*/

#include "include.h"

int turn_player(game_t *game)
{
    my_putstr("Your turn:\n");
    error_line(game);
    if (game->less[0] == -1)
        return (0);
    error_match(game);
    if (game->less[0] == -1)
        return (0);
    my_putstr("Player removed ");
    my_put_nbr(game->less[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->less[0]);
    my_putchar('\n');
    game->turn = 2;
    game->less_save[1] = game->less[1];
    game->less_save[0] = game->less[0];
    change_map(game);
    display_map(game);
    return (1);
}

void restart(game_t *game, int nb_line, int less_max)
{
    if (game->turn == 1) {
        game->nb_v_pl = game->nb_v_pl + 1;
        if (game->nb_v_pl != game->many_victori)
            my_putstr("You may have won this battle but not the war.\n");
    }
    else {
        game->nb_v_ia = game->nb_v_ia + 1;
        if (game->nb_v_ia != game->many_victori)
            my_putstr("This is not your last defat.\n");
    }
    if (game->nb_v_pl != game->many_victori &&
        game->nb_v_ia != game->many_victori) {
        my_putstr("--------------------New game--------------------\n");
        init_game(game, nb_line, less_max);
        my_putstr("SCORE:\nIA:\t");
        my_put_nbr(game->nb_v_ia);
        my_putstr("\nPLAYER:\t");
        my_putchar('\n');
        display_map(game);
    }
}

int matchstick(int nb_line, int less_max)
{
    game_t *game = malloc(sizeof(game_t));

    init_game(game, nb_line, less_max);
    game->nb_v_ia = 0;
    game->nb_v_pl = 0;
    game->turn = 0;
    display_map(game);
    ask_to_player(game);
    if (game->difficult == -1)
        return (0);
    while (game->nb_v_pl != game->many_victori &&
        game->nb_v_ia != game->many_victori) {
        if (!turn_player(game))
            return (0);
        if (game->nb_total != 0)
            turn_ia(game);
        if (game->nb_total == 0) {
            restart(game, nb_line, less_max);
        }
    }
    return (game->turn);
}