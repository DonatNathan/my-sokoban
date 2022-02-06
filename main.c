/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the main file of my program sokoban
*/

#include "includes/sokoban.h"

void test_size(char *map)
{
    struct winsize size;
    int x;
    int y = 0;

    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1)
        if (map[cmpt] == '\n')
            y += 1;
    for (x = 0; map[x] != '\n'; x += 1);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    if (y > size.ws_row || x + 1 > size.ws_col)
        mvaddstr((size.ws_row - 1) / 2, size.ws_col / 2, "RESIZE THE WINDOW");
    else
        addstr(map);
}

int count_walls(positions *pos_map, int cmpt, int size_line)
{
    if ((pos_map->map[cmpt - 1] == 'X' || pos_map->map[cmpt - 1] == '#') && (pos_map->map[cmpt - size_line] == 'X' || pos_map->map[cmpt - size_line] == '#'))
        return (0);
    if ((pos_map->map[cmpt + 1] == 'X' || pos_map->map[cmpt + 1] == '#') && (pos_map->map[cmpt + size_line] == 'X' || pos_map->map[cmpt + size_line] == '#'))
        return (0);
    if ((pos_map->map[cmpt + 1] == 'X' || pos_map->map[cmpt + 1] == '#') && (pos_map->map[cmpt - size_line - 1] == 'X' || pos_map->map[cmpt - size_line - 1] == '#'))
        return (0);
    if ((pos_map->map[cmpt - 1] == 'X' || pos_map->map[cmpt - 1] == '#') && (pos_map->map[cmpt + size_line + 1] == 'X' || pos_map->map[cmpt + size_line + 1] == '#'))
        return (0);
    return (1);
}

int check_defeat(positions *pos_map, int size_line)
{
    for (int cmpt = 0; pos_map->map[cmpt] != '\0'; cmpt += 1) {
        if (pos_map->map[cmpt] == 'X') {
            if (count_walls(pos_map, cmpt, size_line) == 1)
                return (1);
        }
    }
    return (0);
}

void h_params(char **argv)
{
    my_printf("USAGE\n     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n     map file representing the warehouse map,\
containing '#' fro walls,\n         'P' for the player, 'X' for boxes and 'O'\
for storage locations.\n");
}

int main(int argc, char **argv)
{
    struct stat *my_file = malloc(sizeof(struct stat));
    char *map = malloc(sizeof(char) * my_file->st_size);

    stat(argv[1], my_file);
    if (argc != 2) {
        write(2, "invalid number of params\n", 25);
        return (84);
    }
    if (my_strcmp(argv[1], "-h") == 0)
        h_params(argv);
    else {
        if (my_file->st_mode == 16877 || my_file->st_mode == 0) {
            write(2, "invalid filepath\n", 17);
            return (84);
        }
        map = get_map(argv, my_file);
        if (map == "84")
            return (84);
        return (launch_game(map));
    }
}
