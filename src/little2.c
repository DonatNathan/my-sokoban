/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain little functions
*/

#include "../includes/sokoban.h"

void is_p(positions *pos_map, int line)
{
    for (int chara = 0; pos_map->map[line][chara] != '\0'; chara += 1) {
        if (pos_map->map[line][chara] == 'P') {
            pos_map->player[0] = line;
            pos_map->player[1] = chara;
        }
    }
}
