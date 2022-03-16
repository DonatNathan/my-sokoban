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
1][chara] == '#'))
        return (0);
    if ((pos_map->map[cmpt][chara + 1] == 'X' || pos_map->map[cmpt][chara + \
1] == '#') && (pos_map->map[cmpt + 1][chara] == 'X' || pos_map->map[cmpt + 1]\
[chara] == '#'))
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
            if (pos_map->map[cmpt][chara] == 'X' && count_walls(pos_map, \
            cmpt, chara) == 1)
                return (1);
        }
    }
    return (0);
}

int check_end(char **map, positions *pos_map)
{
    pos_map->placed = my_getnbr(pos_map->total);
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
        for (int chara = 0; map[cmpt][chara] != '\0'; chara += 1)
            if (map[cmpt][chara] == 'O')
                pos_map->placed -= 1;
    if (pos_map->pos_end[0] != -1)
        pos_map->placed -= 1;
    for (int cmpt = 0; map[cmpt]; cmpt += 1)
        for (int chara = 0; map[cmpt][chara] != '\0'; chara += 1)
            if (map[cmpt][chara] == 'O')
            return (1);
    return (0);
}

void add_menu(positions *pos_map)
{
    for (int cmpt = 0; pos_map->temp_placed[cmpt] != '\0'; cmpt += 1)
        pos_map->temp_placed[cmpt] = '\0';
    addstr("Box placed : ");
    addstr(new_put_nbr_str(pos_map->placed, pos_map->temp_placed));
    addstr("/");
    addstr(pos_map->total);
    addstr("\n\n");
}

int check_pos_p(positions *pos_map)
{
    for (int cmpt = 0; pos_map->pos_o[cmpt]; cmpt += 1) {
        reset_line_chara(pos_map);
        get_line_chara(pos_map, pos_map->pos_o[cmpt]);
        if (pos_map->cible[0] == my_getnbr(pos_map->line) && \
        pos_map->cible[1] == my_getnbr(pos_map->chara))
            return (1);
    }
    return (0);
}
