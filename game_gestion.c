/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to launch my game
*/

#include "includes/sokoban.h"

void o_gestion(positions *pos_map)
{
    if (pos_map->in_o == 0) {
        pos_map->pos_end = pos_map->cible;
        pos_map->what_is = 1;
    }
    else if (pos_map->in_o == 1) {
        pos_map->pos_caisse = pos_map->obstacle;
        pos_map->what_is = 2;
    }
    else if (pos_map->change == 0) {
        pos_map->pos_end = -1;
        pos_map->pos_caisse = -1;
    }
}

void replace_o(positions *pos_map)
{
    if (pos_map->pos_end != -1 && pos_map->change == 0 && pos_map->what_is == 1) //HERE      
        pos_map->map[pos_map->player] = 'O';
    else if (pos_map->pos_caisse != -1 && pos_map->change == 0 && pos_map->what_is == 2 && pos_map->cible == 'X')
	pos_map->map[pos_map->pos_caisse] = 'O';
}

void check_inversion(positions *pos_map)
{
    pos_map->in_o = 2;
    pos_map->change = 0;
    if (pos_map->map[pos_map->cible] == ' ') {
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
    }
    if (pos_map->map[pos_map->cible] == 'X' && pos_map->map[pos_map->obstacle] != '#' && pos_map->map[pos_map->obstacle] != 'X') {
        if (pos_map->map[pos_map->obstacle] == 'O')
            pos_map->in_o = 1;
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
        pos_map->map[pos_map->obstacle] = 'X';
    }
    if (pos_map->map[pos_map->cible] == 'O') {
        pos_map->in_o = 0;
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
    }
    if (pos_map->map[pos_map->cible] == '#')
        pos_map->change = 1;
    replace_o(pos_map);
    o_gestion(pos_map);
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
    int stop = 2;
    int my_char;
    int size_line;
    positions *pos_map = malloc(sizeof(positions));
    char *copy_map = malloc(sizeof(char *) * 100);

    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1)
        copy_map[cmpt] = map[cmpt];
    pos_map->map = map;
    pos_map->pos_end = -1;
    for (size_line = 0; map[size_line] != '\n'; size_line += 1);
    win = initscr();
    while (stop == 2) {
        keypad(stdscr, TRUE);
        test_size(map);
        my_char = getch();
        refresh();
        if (my_char == ' ') {
            for	(int cmpt = 0; map[cmpt] != '\0'; cmpt += 1)
                map[cmpt] = copy_map[cmpt];
        } else
            move_p(my_char, pos_map, size_line + 1);
        if (check_end(map) == 0 && pos_map->pos_end == -1)
            stop = 0;
        else if (check_defeat(pos_map, size_line) == 0)
            stop = 1;
        clear(); //REMOVE THAT
    }
    endwin();
    return (stop);
}
