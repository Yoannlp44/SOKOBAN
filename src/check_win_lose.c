/*
** EPITECH PROJECT, 2018
** win or lose
** File description:
** win or lose
*/

#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

void check_box_lose(sokoban_t *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'X'){
        if ((sokoban->map[i][j - 1] == '#' && sokoban->map[i - 1][j] == '#')\
|| (sokoban->map[i][j + 1] == '#' && sokoban->map[i - 1][j] == '#')\
|| (sokoban->map[i + 1][j] == '#' && sokoban->map[i][j + 1] == '#')\
|| (sokoban->map[i][j - 1] == '#' && sokoban->map[i + 1][j] == '#'))
            sokoban->check_lose--;
        if (sokoban->check_lose == 0) {
            display_map(sokoban);
            endwin();
            my_free_map(sokoban);
            exit(1);
        }
    }
}

void check_lose(sokoban_t *sokoban)
{
    int i = 0;
    int j = 0;

    sokoban->check_lose = sokoban->cmpt_box;
    while (sokoban->map[i]){
        while (sokoban->map[i][j]){
            check_box_lose(sokoban, i, j);
            j++;
        }
        j = 0;
        i++;
    }
}

int check_win2(sokoban_t *sokoban, int i, int j, int cmpt)
{
    if (sokoban->save_map[i][j] == 'O' && sokoban->map[i][j] == 'X')
        cmpt++;
    return (cmpt);
}

void check_win(sokoban_t *sokoban)
{
    int cmpt = 0;
    int i = 0;
    int j = 0;

    while (sokoban->save_map[i]){
        while (sokoban->save_map[i][j]){
            cmpt = check_win2(sokoban, i, j, cmpt);
            j++;
        }
        if (cmpt == sokoban->cmpt_zero) {
            display_map(sokoban);
            endwin();
            my_free_map(sokoban);
            exit(0);
        }
        j = 0;
        i++;
    }
}
