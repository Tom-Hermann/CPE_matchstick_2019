/*
** EPITECH PROJECT, 2019
** header of file system
** File description:
** header file
*/

#ifndef FILE_SYS_H_
#define FILE_SYS_H_

//init
char **init_map(int nb_line);
void init_game(game_t *game, int nb_line, int less_max);
void set_bo(game_t *game);

//game
int matchstick(int nb_line, int less_max);
void error_line(game_t *game);
void error_match(game_t *game);
char *read_output(void);
void set_difficult(game_t *game);
void ask_to_player(game_t *game);

//info
void usage(void);
void level_ia(void);

//keyword
int key_word(game_t *game, char *buffer);


//usefull
void display_map(game_t *game);
void change_map(game_t *game);
int my_strcmp(char *str1, char *str2);
void restore_map(game_t *game);

//put
void my_put_nbr(int nb);
int my_getnbr(char const *str);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);

//ai level 5
    //ia turn
void turn_ia(game_t *game);

    //other turn
void level_4(game_t *game);
void set_line_max_plus_one(game_t *game);

    //end_game
int end_game(game_t *game);
void set_end_game(game_t *game);

    //last turn
void last_turn(game_t *game);
void loose(game_t *game);

    //sppr line
void sppr_line_unpair(game_t *game);
void sppr_line_pair(game_t *game);

    //turn_total
void pair_total (game_t *game);
void unpair_total(game_t *game);

//ai level 1
void level_1(game_t *game);

//ai level 3
void level_2(game_t *game);

//ai_3
void level_3(game_t *game);

#endif