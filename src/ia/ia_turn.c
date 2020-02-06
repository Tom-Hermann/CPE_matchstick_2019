/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia_turn
*/

#include "include.h"

void which_ai(game_t *game)
{
    switch (game->difficult) {
        case 4 :
            last_turn(game);
            if (game->less[1] == -1)
                level_4(game);
            break;
        case 3 :
            last_turn(game);
            if (game->less[1] == -1)
                level_3(game);
            break;
        case 2 :
            last_turn(game);
            if (game->less[1] == -1)
                level_2(game);
            break;
        case 1 :
            level_1(game);
            break;
    }
}

void turn_ia(game_t *game)
{
    my_putstr("AI's turn...\n");
    game->turn = 1;
    which_ai(game);
    my_putstr("Ai removed ");
    my_put_nbr(game->less[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->less[0]);
    my_putchar('\n');
    change_map(game);
    display_map(game);
}