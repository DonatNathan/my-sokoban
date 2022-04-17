/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to verify position of 'O'
*/

#include "../includes/sokoban.h"

void reset_line_chara(positions *pos_map)
{
    for (int cmpt = 0; pos_map->line[cmpt] != '\0'; cmpt += 1)
        pos_map->line[cmpt] = '\0';
    for	(int cmpt = 0; pos_map->chara[cmpt] != '\0'; cmpt += 1)
        pos_map->chara[cmpt] = '\0';
}

void get_line_chara(positions *pos_map, char *pos_o)
{
    int cmpt;

    for (cmpt = 0; pos_o[cmpt] != ':'; cmpt += 1)
        pos_map->line[cmpt] = pos_o[cmpt];
    cmpt += 1;
    for (int cmpt2 = 0; pos_o[cmpt] != '\0'; cmpt2 += 1) {
        pos_map->chara[cmpt2] = pos_o[cmpt];
        cmpt += 1;
    }
}

void replace_o(positions *pos_map)
{
    for (int cmpt = 0; pos_map->pos_o[cmpt]; cmpt += 1) {
        reset_line_chara(pos_map);
        get_line_chara(pos_map, pos_map->pos_o[cmpt]);
        if (pos_map->map[my_atoi(pos_map->line)][my_atoi(pos_map->chara)] \
        == ' ') {
            pos_map->map[my_atoi(pos_map->line)][my_atoi(pos_map->chara)] \
            = 'O';
        }
    }
}

void o_gestion(positions *pos_map)
{
    if (pos_map->in_o == 0) {
        pos_map->pos_end[0] = pos_map->cible[0];
        pos_map->pos_end[1] = pos_map->cible[1];
        pos_map->what_is = 1;
    } else if (pos_map->in_o == 1) {
        pos_map->pos_caisse[0] = pos_map->obstacle[0];
        pos_map->pos_caisse[1] = pos_map->obstacle[1];
        pos_map->what_is = 2;
    } else if (pos_map->change == 0) {
        pos_map->pos_end[0] = -1;
        pos_map->pos_caisse[0] = -1;
    }
}

void stock_o(positions *pos_map)
{
    int cmpt_o = 0;
    int nb_o = 0;

    for (int cmpt = 0; pos_map->map[cmpt]; cmpt += 1)
        nb_o = get_o_little(pos_map, cmpt, nb_o);
    pos_map->pos_o = malloc(sizeof(char *) * nb_o);
    for (int line = 0; pos_map->map[line]; line += 1) {
        cmpt_o = get_o(pos_map, cmpt_o, line);
    }
    pos_map->pos_o[cmpt_o] = NULL;
}
