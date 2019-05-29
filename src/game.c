/*
** EPITECH PROJECT, 2018
** game
** File description:
** game
*/

#include "sokoban.h"
#include <ncurses.h>
#include "my.h"

void display_map(sokoban_t *sokoban)
{
    int i = 0;
    char *str = "Please enlarge the terminal";
    int size_message = my_strlen(str);

    while (sokoban->col_size >= LINES){
        clear();
        mvprintw(LINES / 2, (COLS / 2) - (size_message / 2), str);
        refresh();
    }
    clear();
    while (i <= sokoban->col_size){
        printw(sokoban->map[i]);
        i++;
    }
    refresh();
}

void check_key(int key, sokoban_t *sokoban)
{
    if (key == 32)
        main(sokoban->ac, sokoban->av);
    if (key == KEY_DOWN)
        move_player_down(sokoban);
    if (key == KEY_RIGHT)
        move_player_right(sokoban);
    if (key == KEY_UP)
        move_player_up(sokoban);
    if (key == KEY_LEFT)
        move_player_left(sokoban);
}

void save_pos_player(sokoban_t *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'P') {
        sokoban->player_x = i;
        sokoban->player_y = j;
    }
}

void get_player_pos(sokoban_t *sokoban)
{
    int i = 0;
    int j = 0;

    while (sokoban->map[i]){
        while (sokoban->map[i][j]){
            save_pos_player(sokoban, i, j);
            j++;
        }
        j = 0;
        i++;
    }
}

void start_game(sokoban_t *sokoban)
{
    int key;

    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    while (1){
        check_win(sokoban);
        check_lose(sokoban);
        display_map(sokoban);
        get_player_pos(sokoban);
        key = getch();
        check_key(key, sokoban);
        check_o(sokoban);
    }
    endwin();
}
