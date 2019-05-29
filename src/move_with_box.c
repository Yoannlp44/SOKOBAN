/*
** EPITECH PROJECT, 2018
** move player with box
** File description:
** move
*/

#include "sokoban.h"

int move_box_down(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x + 2][sokoban->player_y] != '#'\
    && sokoban->map[sokoban->player_x + 2][sokoban->player_y] != 'X') {
        sokoban->map[sokoban->player_x + 2][sokoban->player_y] = 'X';
        sokoban->map[sokoban->player_x + 1][sokoban->player_y] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
    }
    return (0);
}

int move_box_up(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x - 2][sokoban->player_y] != '#'\
    && sokoban->map[sokoban->player_x - 2][sokoban->player_y] != 'X') {
        sokoban->map[sokoban->player_x - 2][sokoban->player_y] = 'X';
        sokoban->map[sokoban->player_x - 1][sokoban->player_y] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
    }
    return (0);
}

int move_box_left(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x][sokoban->player_y - 2] != '#'\
    && sokoban->map[sokoban->player_x][sokoban->player_y - 2] != 'X') {
        sokoban->map[sokoban->player_x][sokoban->player_y - 2] = 'X';
        sokoban->map[sokoban->player_x][sokoban->player_y - 1] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
    }
    return (0);
}

int move_box_right(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->player_x][sokoban->player_y + 2] != '#'\
    && sokoban->map[sokoban->player_x][sokoban->player_y + 2] != 'X') {
        sokoban->map[sokoban->player_x][sokoban->player_y + 2] = 'X';
        sokoban->map[sokoban->player_x][sokoban->player_y + 1] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
    }
    return (0);
}