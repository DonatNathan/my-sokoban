/*
** EPITECH PROJECT, 2022
** MY_SOKOBAN
** File description:
** It's the file that contain functions to create loose or win
*/

#include "../includes/sokoban.h"

int count_walls(positions *pos_map, int cmpt, int chara)
{
    if ((pos_map->map[cmpt][chara - 1] == 'X' || pos_map->map[cmpt][chara - \
1] == '#') && (pos_map->map[cmpt - 1][chara] == 'X' || pos_map->map[cmpt - \
1][chara]  == '#'))
        return (0);
    if ((pos_map->map[cmpt][chara + 1] == 'X' || pos_map->map[cmpt][chara + \
1] == '#') && (pos_map->map[cmpt + 1][chara] == 'X' || pos_map->map[cmpt + 1]\
[chara]  == '#'))
        return (0);
    if ((pos_map->map[cmpt][chara + 1] == 'X' || pos_map->map[cmpt][chara + \
1] == '#') && (pos_map->map[cmpt - 1][chara] == 'X' || pos_map->map[cmpt - 1]\
[chara] == '#'))
        return (0);
    if ((pos_map->map[cmpt][chara - 1] == 'X' || pos_map->map[cmpt][chara - \
1] == '#') && (pos_map->map[cmpt + 1][chara] == 'X' || pos_map->map[cmpt + 1]\
[chara] == '#'))
        return (0);
    return (1);
}

int check_defeat(positions *pos_map)
{
    for (int cmpt = 0; pos_map->map[cmpt]; cmpt += 1) {
	for (int chara = 0; pos_map->map[cmpt][chara] != '\0'; chara += 1) {
            my_printf("%c\n", pos_map->map[cmpt][chara]);
            if (pos_map->map[cmpt][chara] == 'X' && count_walls(pos_map, cmpt, \
                                                                chara) == 1)
                return (1);
        }
    }
    return (0);
}

int check_end(char **map)
{
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
	for (int chara = 0; map[cmpt][chara] != '\0'; chara += 1)
            if (map[cmpt][chara] == 'O')
            return (1);
    return (0);
}
