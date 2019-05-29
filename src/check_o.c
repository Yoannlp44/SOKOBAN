/*
** EPITECH PROJECT, 2018
** check o
** File description:
** check o
*/

#include "sokoban.h"

void change_or_not_o(sokoban_t *sokoban, int i, int j)
{
    if (sokoban->save_map[i][j] == 'O')
        if (sokoban->map[i][j] != 'P' && sokoban->map[i][j] != 'X')
            sokoban->map[i][j] = 'O';
}

void check_o(sokoban_t *sokoban)
{
    int i = 0;
    int j = 0;

    while (sokoban->save_map[i]){
        while (sokoban->save_map[i][j]) {
            change_or_not_o(sokoban, i, j);
            j++;
        }
        j = 0;
        i++;
    }
}
