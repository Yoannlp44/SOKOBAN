/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

typedef struct sokoban
{
    char **map;
    char **save_map;
    int ac;
    char const **av;
    int player_x;
    int player_y;
    int len_size;
    int col_size;
    int save_pos_zero_x;
    int save_pos_zero_y;
    int add_zero;
    int cmpt_zero;
    int cmpt_box;
    int check_lose;
    int nbr_player;
} sokoban_t;

void check_error(sokoban_t sokoban);
void my_free_map(sokoban_t *sokoban);
void start_game(sokoban_t *sokoban);
int move_player_down(sokoban_t *sokoban);
int move_player_left(sokoban_t *sokoban);
int move_player_up(sokoban_t *sokoban);
int move_player_right(sokoban_t *sokoban);
int move_box_down(sokoban_t *sokoban);
int move_box_up(sokoban_t *sokoban);
int move_box_left(sokoban_t *sokoban);
int move_box_right(sokoban_t *sokoban);
void count_box(sokoban_t *sokoban);
void check_win(sokoban_t *sokoban);
void check_lose(sokoban_t *sokoban);
int main(int ac, char const **av);
void check_zero(sokoban_t *sokoban, int opt);
int move_player_up2(sokoban_t *sokoban);
int move_player_right2(sokoban_t *sokoban);
int move_player_left2(sokoban_t *sokoban);
int move_player_down2(sokoban_t *sokoban);
void display_map(sokoban_t *sokoban);
void check_o(sokoban_t *sokoban);
void get_map(sokoban_t *sokoban, char const *path);
void get_save_map(sokoban_t *sokoban, char const *path);
void get_player_pos(sokoban_t *sokoban);

#endif /* !SOKOBAN_H_ */
