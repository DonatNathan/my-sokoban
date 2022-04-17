/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to launch my game
*/

#include "../includes/sokoban.h"

void test_size(char **map)
{
    struct winsize size;
    int x;
    int final_x = 0;
    int y;

    for (y = 0; map[y]; y += 1);
    for (int cmpt = 0; map[cmpt]; cmpt += 1) {
        for (x = 0; map[cmpt][x] != '\0'; x += 1);
        if (x > final_x)
            final_x = x;
    }
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    if (y > size.ws_row || final_x > size.ws_col)
        mvaddstr((size.ws_row - 1) / 2, size.ws_col / 2 - 6, "RESIZE WINDOW");
    else {
        for (int cmpt = 0; map[cmpt]; cmpt += 1)
            addstr(map[cmpt]);
    }
}

int get_o(positions *pos_map, int cmpt_o, int line)
{
    for (int cmpt = 0; pos_map->map[line][cmpt] != '\0'; cmpt += 1) {
        if (pos_map->map[line][cmpt] == 'O') {
            pos_map->pos_o[cmpt_o] = malloc(sizeof(char) *
            (my_strlen(my_itoa(line)) + 1));
            pos_map->pos_o[cmpt_o] = my_itoa(line);
            pos_map->pos_o[cmpt_o][my_strlen(my_itoa(line))] = '\0';
            pos_map->pos_o[cmpt_o] = my_strncat(pos_map->pos_o[cmpt_o], ":",
            0);
            pos_map->pos_o[cmpt_o] = my_strncat(pos_map->pos_o[cmpt_o], \
            my_itoa(cmpt), 0);
            pos_map->pos_o[cmpt_o] = my_strncat(pos_map->pos_o[cmpt_o], \
            "\0", 0);
            cmpt_o += 1;
        }
    }
    return (cmpt_o);
}

void allocs(positions *pos_map)
{
    pos_map->player = malloc(sizeof(int) * 2);
    pos_map->cible = malloc(sizeof(int) * 2);
    pos_map->obstacle = malloc(sizeof(int) * 2);
    pos_map->line = malloc(sizeof(char *));
    pos_map->chara = malloc(sizeof(char *));
}

void init_struct(positions *pos_map, char **map)
{
    int cmpt;
    int chara;

    pos_map->pos_end = malloc(sizeof(int) * 2);
    pos_map->pos_caisse = malloc(sizeof(int) * 2);
    for (cmpt = 0; map[cmpt]; cmpt += 1);
    pos_map->copy_map = malloc(sizeof(char *) * (cmpt + 1));
    allocs(pos_map);
    for (cmpt = 0; map[cmpt]; cmpt += 1) {
        pos_map->copy_map[cmpt] = malloc(sizeof(char *) *
        (my_strlen(map[cmpt]) + 1));
        for (chara = 0; map[cmpt][chara] != '\0'; chara += 1)
            pos_map->copy_map[cmpt][chara] = map[cmpt][chara];
        pos_map->copy_map[cmpt][chara] = '\0';
    }
    pos_map->copy_map[cmpt] = NULL;
    pos_map->map = map;
    pos_map->pos_end[0] = -1;
    pos_map->pos_caisse[0] = -1;
}

int launch_game(char **map, int stop)
{
    WINDOW *win = initscr();
    int my_char;
    positions *pos_map = malloc(sizeof(positions));

    init_struct(pos_map, map);
    stock_o(pos_map);
    while (stop == 2) {
        keypad(stdscr, TRUE);
        test_size(map);
        my_char = getch();
        stop = draw_all(pos_map, my_char);
        clear();
        test_stop(pos_map, stop);
        wrefresh(win);
    }
    endwin();
    return (stop);
}
