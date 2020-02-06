/*
** EPITECH PROJECT, 2019
** Dossier modèle
** File description:
** main
*/

#include "include.h"

int error(int argc, char **av)
{
    if (argc == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        usage();
        return (42);
    }
    if (argc != 3)
        return (84);
    for (int i = 0; av[1][i] != 0; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
    for (int i = 0; av[2][i] != 0; i++)
        if (av[2][i] < '0' || av[2][i] > '9')
            return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (84);
    if (my_getnbr(av[2]) <= 0)
        return (84);
    return (0);

}

int main(int argc, char **argv)
{
    int error_return = error(argc, argv);
    int nb_line = 0;
    int nb_max = 0;

    if (error_return == 42)
        return (0);
    else if (error_return == 84)
        return (84);
    nb_line = my_getnbr(argv[1]);
    nb_max = my_getnbr(argv[2]);
    if ((error_return = matchstick(nb_line, nb_max)) == 2)
        my_putstr("You lost, too bad...\n");
    else if (error_return)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (error_return);
}