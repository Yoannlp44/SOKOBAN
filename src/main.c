/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** sokoban
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"
#include <fcntl.h>
#include <stdlib.h>

void display_h(void)
{
    my_putstr("USAGE\n      ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse \
map, containing ‘#’ for walls,\n");
    my_putstr("         ‘P’ for the player, ‘X’ for \
boxes and ‘O’ for storage locations.\n");
}

void init_struct(sokoban_t *sokoban)
{
    sokoban->map = NULL;
    sokoban->save_map = NULL;
    sokoban->player_x = 0;
    sokoban->player_y = 0;
    sokoban->len_size = 0;
    sokoban->col_size = 0;
    sokoban->av = NULL;
    sokoban->ac = 0;
    sokoban->add_zero = 0;
    sokoban->save_pos_zero_x = 0;
    sokoban->save_pos_zero_y = 0;
    sokoban->cmpt_zero = 0;
    sokoban->cmpt_box = 0;
    sokoban->check_lose = 0;
    sokoban->nbr_player = 0;
}

int main(int ac, char const **av)
{
    sokoban_t sokoban;

    if (ac != 2)
        return (84);
    if (my_strcmp("-h", av[1]) == 0) {
        display_h();
        return (0);
    }
    init_struct(&sokoban);
    sokoban.ac = ac;
    sokoban.av = av;
    get_map(&sokoban, av[1]);
    count_box(&sokoban);
    check_error(sokoban);
    get_save_map(&sokoban, av[1]);
    start_game(&sokoban);
    return (0);
}
