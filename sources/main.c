/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "arg_handler.h"

int main(int ac, char **av)
{
    if (arg_handler("./arg_handler -x alpha (-i name) [id] (-t [type])", ac, av) != 0)
        return 84;
    return 0;
}