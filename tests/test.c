/*
** EPITECH PROJECT, 2018
** unit test
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sokoban, player_pos)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n#P  #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    cr_assert_eq(2, sokoban.player_x);
    cr_assert_eq(1, sokoban.player_y);
}

Test(sokoban, player_pos2)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n#   #\n#   #\n##P##\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    cr_assert_eq(4, sokoban.player_x);
    cr_assert_eq(2, sokoban.player_y);
}

Test(sokoban, player_move_up)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n#   #\n#   #\n##P##\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_player_up2(&sokoban);
    cr_assert_str_eq(sokoban.map[3], "# P #");
}

Test(sokoban, player_move_down)
{
    sokoban_t sokoban;
    char *map = "#####\n# P #\n#   #\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_player_down2(&sokoban);
    cr_assert_str_eq(sokoban.map[2], "# P #");
}

Test(sokoban, player_move_left)
{
    sokoban_t sokoban;
    char *map = "#####\n# P #\n#   #\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_player_left2(&sokoban);
    cr_assert_str_eq(sokoban.map[1], "#P  #");
}

Test(sokoban, player_move_right)
{
    sokoban_t sokoban;
    char *map = "#####\n# P #\n#   #\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_player_right2(&sokoban);
    cr_assert_str_eq(sokoban.map[1], "#  P#");
}

Test(sokoban, player_move_box_up)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n# X #\n# P #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_box_up(&sokoban);
    cr_assert_str_eq(sokoban.map[1], "# X #");
    cr_assert_str_eq(sokoban.map[2], "# P #");
}

Test(sokoban, player_move_box_down)
{
    sokoban_t sokoban;
    char *map = "#####\n# P #\n# X #\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_box_down(&sokoban);
    cr_assert_str_eq(sokoban.map[2], "# P #");
    cr_assert_str_eq(sokoban.map[3], "# X #");
}

Test(sokoban, player_move_box_left)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n# XP#\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_box_left(&sokoban);
    cr_assert_str_eq(sokoban.map[2], "#XP #");
}

Test(sokoban, player_move_box_right)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n#PX #\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_box_right(&sokoban);
    cr_assert_str_eq(sokoban.map[2], "# PX#");
}

Test(sokoban, player_move_in_o)
{
    sokoban_t sokoban;
    char *map = "#####\n#   #\n#PO #\n#   #\n#####\n";

    sokoban.map = my_str_to_word_array(map);
    sokoban.save_map = my_str_to_word_array(map);
    get_player_pos(&sokoban);
    move_player_right2(&sokoban);
    cr_assert_str_eq(sokoban.map[2], "# P #");
    get_player_pos(&sokoban);
    move_player_right2(&sokoban);
    check_o(&sokoban);
    cr_assert_str_eq(sokoban.map[2], "# OP#");
}