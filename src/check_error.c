/*
** EPITECH PROJECT, 2018
** error
** File description:
** error
*/

#include "sokoban.h"
#include <stdlib.h>
#include "my.h"

void my_free_map(sokoban_t *sokoban)
{
    int i = 0;

    while (sokoban->map[i]){
        free(sokoban->map[i]);
        i++;
    }
    free(sokoban->map[i]);
    free(sokoban->map);
}

void check_characters(int i, int j, sokoban_t sokoban)
{
    if (sokoban.map[i][j] != '#' && sokoban.map[i][j] != ' '\
    && sokoban.map[i][j] != 'P' && sokoban.map[i][j] != '\n'\
    && sokoban.map[i][j] != 'O' && sokoban.map[i][j] != 'X') {
        my_putstr("Invalid Map\n");
        exit(84);
    }
}

void check_error(sokoban_t sokoban)
{
    int i = 0;
    int j = 0;

    if (sokoban.cmpt_box != sokoban.cmpt_zero\
    || sokoban.nbr_player != 1 || sokoban.cmpt_box < 1) {
        my_putstr("Invalid map\n");
        exit(84);
    }
    while (sokoban.map[i]){
        while (sokoban.map[i][j]){
            check_characters(i, j , sokoban);
            j++;
        }
        j = 0;
        i++;
    }
}