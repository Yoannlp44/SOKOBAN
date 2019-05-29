/*
** EPITECH PROJECT, 2018
** check zero
** File description:
** check zero
*/

#include "sokoban.h"

void check_zero(sokoban_t *sokoban, int opt)
{
    if (sokoban->add_zero == 1) {
        sokoban->map[sokoban->save_pos_zero_x][sokoban->save_pos_zero_y] = 'O';
        sokoban->add_zero = 0;
    }
    else if (opt == 1)
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
}
