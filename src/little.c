/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain little functions
*/

#include "../includes/sokoban.h"

int get_height(char *map)
{
    int height;

    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1)
        if (map[cmpt] == '\n')
            height += 1;
    return (height + 1);
}

int check_pos_p(positions *pos_map)
{
    for (int cmpt = 0; pos_map->pos_o[cmpt]; cmpt += 1) {
        reset_line_chara(pos_map);
        get_line_chara(pos_map, pos_map->pos_o[cmpt]);
        if (pos_map->cible[0] == my_atoi(pos_map->line) && \
        pos_map->cible[1] == my_atoi(pos_map->chara))
            return (1);
    }
    return (0);
}

void test_stop(positions *pos_map, int stop)
{
    if (stop != 2) {
        for (int cmpt = 0; pos_map->map[cmpt]; cmpt += 1)
            printw("%s", pos_map->map[cmpt]);
        printw("\n");
    }
}

int get_o_little(positions *pos_map, int cmpt, int nb_o)
{
    for (int col = 0; pos_map->map[cmpt][col] != '\0'; col += 1)
        if (pos_map->map[cmpt][col] == 'O')
            nb_o += 1;
    return (nb_o);
}

void restart_map(positions *pos_map)
{
    for (int cmpt = 0; pos_map->map[cmpt]; cmpt += 1) {
        for (int chara = 0; pos_map->map[cmpt][chara] != '\0'; chara += 1)
            pos_map->map[cmpt][chara] = pos_map->copy_map[cmpt][chara];
    }
}
