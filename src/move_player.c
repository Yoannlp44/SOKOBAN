/*
** EPITECH PROJECT, 2018
** move player
** File description:
** move player
*/

#include "sokoban.h"

int move_player_down(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x + 1][sokoban->player_y] != 'X')
        move_player_down2(sokoban);
    else if (sokoban->map[sokoban->player_x + 1][sokoban->player_y] == 'X')
        move_box_down(sokoban);
    return (0);
}

int move_player_left(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x][sokoban->player_y - 1] != 'X')
        move_player_left2(sokoban);
    else if (sokoban->map[sokoban->player_x][sokoban->player_y - 1] == 'X')
        move_box_left(sokoban);
    return (0);
}

int move_player_right(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x][sokoban->player_y + 1] != 'X')
        move_player_right2(sokoban);
    else if (sokoban->map[sokoban->player_x][sokoban->player_y + 1] == 'X')
        move_box_right(sokoban);
    return (0);
}

int move_player_up(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x - 1][sokoban->player_y] != 'X')
        move_player_up2(sokoban);
    else if (sokoban->map[sokoban->player_x - 1][sokoban->player_y] == 'X')
        move_box_up(sokoban);
    return (0);
}