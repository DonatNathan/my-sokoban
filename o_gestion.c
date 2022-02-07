/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to verify position of 'O'
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
    if (pos_map->pos_end != -1 && pos_map->change == 0 && pos_map->what_is == 1)
        pos_map->map[pos_map->player] = 'O';
    else if (pos_map->pos_caisse != -1 && pos_map->change == 0 && pos_map->what_is == 2 && pos_map->cible == 'X')
        pos_map->map[pos_map->pos_caisse] = 'O';
}

int check_end(char *map)
{
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
        if (map[cmpt] == 'O')
            return (1);
    return (0);
}

void check_inversion2(positions *pos_map)
{
    if (pos_map->map[pos_map->cible] == 'O') {
        pos_map->in_o = 0;
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
    }
    if (pos_map->map[pos_map->cible] == '#')
        pos_map->change = 1;
    if (pos_map->map[pos_map->cible] == ' ') {
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
    }
}
