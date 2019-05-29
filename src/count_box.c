/*
** EPITECH PROJECT, 2018
** count box
** File description:
** box
*/

#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

void verif_box(sokoban_t *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'O')
        sokoban->cmpt_zero++;
    if (sokoban->map[i][j] == 'X')
        sokoban->cmpt_box++;
    if (sokoban->map[i][j] == 'P')
        sokoban->nbr_player++;
}

void count_box(sokoban_t *sokoban)
{
    int i = 0;
    int j = 0;

    while (sokoban->map[i]){
        while (sokoban->map[i][j]){
            verif_box(sokoban, i, j);
            j++;
        }
        j = 0;
        i++;
    }
}
