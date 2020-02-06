/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** info
*/

#include "include.h"

void level_ia(void)
{
    my_putstr("This game have 4 level of difficult:\n");
    my_putstr("level 1 : random ai\n");
    my_putstr("level 2 : easy\n");
    my_putstr("level 3 : normal\n");
    my_putstr("level 4 : hard\n");
}

void usage(void)
{
    my_putstr("USAGE:\n\t\t./mathstick size_map nb_max\n");
    my_putstr("DESCRIPTION:\n\t\tmap_size:\tnumber of line\n");
    my_putstr("\t\tnb_max:\t\tmaximum number of matches that can be");
    my_putstr(" removed\nOUTPUT:\n\t\twrite how many victory");
    my_putstr(" you need for win\n\t\tafter pick enter the level of ai:\n");
    level_ia();
    my_putstr("\nFor each turn:\n");
    my_putstr("\t\tfirst write which line you want to reduce\n");
    my_putstr("\t\tsecond how many matches you want reduce\n");
    my_putstr("OTHER:\nYou can write 'help', ");
    my_putstr("AI will give you what she would have played\n");
    my_putstr("You can write 'cancel' for cancel your last turn\n");
    my_putstr("you can't use help and cancel in one turn\n");
}