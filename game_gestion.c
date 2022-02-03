/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to launch my game
*/

#include "includes/sokoban.h"

void check_inversion(positions *pos_map)
{
    int in_o = 2;
    int change = 0;

    if (pos_map->map[pos_map->cible] == ' ') {
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
    }
    if (pos_map->map[pos_map->cible] == 'X' && pos_map->map[pos_map->obstacle] != '#' && pos_map->map[pos_map->obstacle] != 'X') {
//        if (pos_map->map[pos_map->obstacle] == 'O')
//            in_o = 1;
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
        pos_map->map[pos_map->obstacle] = 'X';
    }
    if (pos_map->map[pos_map->cible] == 'O') {
        in_o = 0;
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
    }
    if (pos_map->map[pos_map->cible] == '#')
        change = 1;
    if (pos_map->pos_end != -1 && change == 0)
        pos_map->map[pos_map->player] = 'O';
    if (in_o == 0)
        pos_map->pos_end = pos_map->cible;
//    else if (in_o == 1)
//        pos_map->pos_end = pos_map->obstacle;
    else if (change == 0)
        pos_map->pos_end = -1;
}

void move_p(int my_char, positions *pos_map, int size_line)
{
    for (pos_map->player = 1; pos_map->map[pos_map->player] != 'P'; \
         pos_map->player += 1);
    if (my_char == KEY_LEFT) {
        pos_map->cible = pos_map->player - 1;
        pos_map->obstacle = pos_map->player - 2;
        check_inversion(pos_map);
    } if (my_char == KEY_RIGHT) {
        pos_map->cible = pos_map->player + 1;
        pos_map->obstacle = pos_map->player + 2;
        check_inversion(pos_map);
    } if (my_char == KEY_UP) {
        pos_map->cible = pos_map->player - size_line;
        pos_map->obstacle = pos_map->player - 2 * size_line;
        check_inversion(pos_map);
    } if (my_char == KEY_DOWN) {
        pos_map->cible = pos_map->player + size_line;
        pos_map->obstacle = pos_map->player + 2 * size_line;
        check_inversion(pos_map);
    }
}

int check_end(char *map)
{
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
        if (map[cmpt] == 'O')
            return (1);
    return (0);
}

int launch_game(char *map)
{
    WINDOW *win;
    int stop = 1;
    int my_char;
    int size_line;
    positions *pos_map = malloc(sizeof(positions));

    pos_map->map = map;
    pos_map->pos_end = -1;
    for (size_line = 0; map[size_line] != '\n'; size_line += 1);
    while (stop == 1) {
        win = initscr();
        keypad(stdscr, TRUE);
        addstr(map);
        my_char = getch();
        move_p(my_char, pos_map, size_line + 1);
        refresh();
        endwin();
        if (check_end(map) == 0 && pos_map->pos_end == -1)
            stop = 0;
        clear(); //REMOVE THAT
    }
    return (0);
}
