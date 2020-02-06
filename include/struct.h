/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_game
{
    char **map;
    int *nb_on_line;
    int nb_line;
    int nb_total;
    int less_max;
    int turn;
    int poss_line;
    int *less;
    int *less_save;
    int difficult;
    int many_victori;
    int nb_v_ia;
    int nb_v_pl;
} game_t;

#endif /* !STRUCT_H_ */
