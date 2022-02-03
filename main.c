/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the main file of my program sokoban
*/

#include "includes/sokoban.h"

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
