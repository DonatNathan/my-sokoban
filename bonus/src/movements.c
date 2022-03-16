/*
** EPITECH PROJECT, 2022
** MY_SOKOBAN
** File description:
** It's the file that contain functions to get movements event
*/

#include "../includes/sokoban.h"

void check_inversion2(positions *pos_map)
{
    if (pos_map->map[pos_map->cible[0]][pos_map->cible[1]] == 'O') {
        pos_map->in_o = 0;
        pos_map->map[pos_map->cible[0]][pos_map->cible[1]] = pos_map->map\
            [pos_map->player[0]][pos_map->player[1]];
        pos_map->map[pos_map->player[0]][pos_map->player[1]] = ' ';
    }
    if (pos_map->map[pos_map->cible[0]][pos_map->cible[1]] == '#')
        pos_map->change = 1;
    if (pos_map->map[pos_map->cible[0]][pos_map->cible[1]] == ' ') {
        pos_map->map[pos_map->cible[0]][pos_map->cible[1]] = pos_map->map\
            [pos_map->player[0]][pos_map->player[1]];
        pos_map->map[pos_map->player[0]][pos_map->player[1]] = ' ';
    }
}

void check_inversion(positions *pos_map)
{
    pos_map->in_o = 2;
    pos_map->change = 0;
    check_inversion2(pos_map);
    if (pos_map->map[pos_map->cible[0]][pos_map->cible[1]] == 'X' && \
pos_map->map[pos_map->obstacle[0]][pos_map->obstacle[1]] != '#' && \
pos_map->map[pos_map->obstacle[0]][pos_map->obstacle[1]] != 'X') {
        if (pos_map->map[pos_map->obstacle[0]][pos_map->obstacle[1]] == 'O') {
            pos_map->in_o = 1;
            pos_map->change = 1;
        }
        pos_map->map[pos_map->cible[0]][pos_map->cible[1]] = pos_map->map\
            [pos_map->player[0]][pos_map->player[1]];
        pos_map->map[pos_map->player[0]][pos_map->player[1]] = ' ';
        pos_map->map[pos_map->obstacle[0]][pos_map->obstacle[1]] = 'X';
    }
    replace_o(pos_map);
    o_gestion(pos_map);
}

void move_p(int my_char, positions *pos_map)
{
    if (my_char == KEY_RIGHT) {
        pos_map->cible[0] = pos_map->player[0];
        pos_map->cible[1] = pos_map->player[1] + 1;
        pos_map->obstacle[0] = pos_map->player[0];
        pos_map->obstacle[1] = pos_map->player[1] + 2;
        check_inversion(pos_map);
    } if (my_char == KEY_UP) {
        pos_map->cible[0] = pos_map->player[0] - 1;
        pos_map->cible[1] = pos_map->player[1];
        pos_map->obstacle[0] = pos_map->player[0] - 2;
        pos_map->obstacle[1] = pos_map->player[1];
        check_inversion(pos_map);
    } if (my_char == KEY_DOWN) {
        pos_map->cible[0] = pos_map->player[0] + 1;
        pos_map->cible[1] = pos_map->player[1];
        pos_map->obstacle[0] = pos_map->player[0] + 2;
        pos_map->obstacle[1] = pos_map->player[1];
        check_inversion(pos_map);
    }
}

void get_p(int my_char, positions *pos_map)
{
    for (int line = 0; pos_map->map[line]; line += 1) {
        for (int chara = 0; pos_map->map[line][chara] != '\0'; chara += 1) {
            if (pos_map->map[line][chara] == 'P') {
                pos_map->player[0] = line;
                pos_map->player[1] = chara;
            }
        }
    }
    if (my_char == KEY_LEFT) {
        pos_map->cible[0] = pos_map->player[0];
        pos_map->cible[1] = pos_map->player[1] - 1;
        pos_map->obstacle[0] = pos_map->player[0];
        pos_map->obstacle[1] = pos_map->player[1] - 2;
        check_inversion(pos_map);
    }
    move_p(my_char, pos_map);
}

int draw_all(positions *pos_map, int my_char)
{
    if (my_char == ' ') {
        for (int cmpt = 0; pos_map->map[cmpt]; cmpt += 1) {
            for (int chara = 0; pos_map->map[cmpt][chara] != '\0'; \
            chara += 1) {
                pos_map->map[cmpt][chara] = pos_map->copy_map[cmpt][chara];
            }
        }
    } else
        get_p(my_char, pos_map);
    if (check_end(pos_map->map, pos_map) == 0 && check_pos_p(pos_map) == 0)
        return (0);
    if (check_defeat(pos_map) == 0)
        return (1);
    return (2);
}
