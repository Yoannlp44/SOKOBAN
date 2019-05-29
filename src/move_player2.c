/*
** EPITECH PROJECT, 2018
** move
** File description:
** move
*/

#include "sokoban.h"

int move_player_down2(sokoban_t *sokoban)
{
    int opt = 0;

    if (sokoban->map[sokoban->player_x + 1][sokoban->player_y] == '#')
        return (0);
    if (sokoban->map[sokoban->player_x + 1][sokoban->player_y] == 'O') {
        sokoban->save_pos_zero_x = sokoban->player_x + 1;
        sokoban->save_pos_zero_y = sokoban->player_y;
        sokoban->add_zero = 1;
        sokoban->map[sokoban->player_x + 1][sokoban->player_y] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
        return (0);
    }
    else if (sokoban->map[sokoban->player_x + 1][sokoban->player_y] == ' ') {
        sokoban->map[sokoban->player_x + 1][sokoban->player_y] = 'P';
        opt = 1;
    }
    check_zero(sokoban, opt);
    return (0);
}

int move_player_left2(sokoban_t *sokoban)
{
    int opt = 0;

    if (sokoban->map[sokoban->player_x][sokoban->player_y - 1] == '#')
        return (0);
    if (sokoban->map[sokoban->player_x][sokoban->player_y - 1] == 'O') {
        sokoban->save_pos_zero_x = sokoban->player_x;
        sokoban->save_pos_zero_y = sokoban->player_y - 1;
        sokoban->add_zero = 1;
        sokoban->map[sokoban->player_x][sokoban->player_y - 1] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
        return (0);
    }
    else if (sokoban->map[sokoban->player_x][sokoban->player_y - 1] == ' '){
        sokoban->map[sokoban->player_x][sokoban->player_y - 1] = 'P';
        opt = 1;
    }
    check_zero(sokoban, opt);
    return (0);
}

int move_player_right2(sokoban_t *sokoban)
{
    int opt = 0;

    if (sokoban->map[sokoban->player_x][sokoban->player_y + 1] == '#')
        return (0);
    if (sokoban->map[sokoban->player_x][sokoban->player_y + 1] == 'O') {
        sokoban->save_pos_zero_x = sokoban->player_x;
        sokoban->save_pos_zero_y = sokoban->player_y + 1;
        sokoban->add_zero = 1;
        sokoban->map[sokoban->player_x][sokoban->player_y + 1] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
        return (0);
    }
    else if (sokoban->map[sokoban->player_x][sokoban->player_y + 1] == ' ') {
        sokoban->map[sokoban->player_x][sokoban->player_y + 1] = 'P';
        opt = 1;
    }
    check_zero(sokoban, opt);
    return (0);
}

int move_player_up2(sokoban_t *sokoban)
{
    int opt = 0;

    if (sokoban->map[sokoban->player_x - 1][sokoban->player_y] == '#')
        return (0);
    if (sokoban->map[sokoban->player_x - 1][sokoban->player_y] == 'O') {
        sokoban->save_pos_zero_x = sokoban->player_x - 1;
        sokoban->save_pos_zero_y = sokoban->player_y;
        sokoban->add_zero = 1;
        sokoban->map[sokoban->player_x - 1][sokoban->player_y] = 'P';
        sokoban->map[sokoban->player_x][sokoban->player_y] = ' ';
        return (0);
    }
    else if (sokoban->map[sokoban->player_x - 1][sokoban->player_y] == ' ') {
        sokoban->map[sokoban->player_x - 1][sokoban->player_y] = 'P';
        opt = 1;
    }
    check_zero(sokoban, opt);
    return (0);
}
