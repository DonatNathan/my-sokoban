/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the main file of my program sokoban
*/

#include "../includes/sokoban.h"

void h_params(char **argv)
{
    my_printf("USAGE\n ./my_sokoban map\n");
    my_printf("DESCRIPTION\n map file representing the warehouse map,\
containing '#' fro walls,\n 'P' for the player, 'X' for boxes and 'O'\
for storage locations.\n");
}

int error_gestion(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "invalid number of params\n", 25);
        return (84);
    }
    return (0);
}

char *do_else(struct stat *my_file, char *map, char **argv)
{
    if (my_file->st_mode == 16877 || my_file->st_mode == 0) {
        write(2, "invalid filepath\n", 17);
        return ("84");
    }
    map = get_map(argv, my_file);
    return (map);
}

int main(int argc, char **argv)
{
    struct stat my_file;
    char *map;
    char **new_map;

    stat(argv[1], &my_file);
    map = malloc(sizeof(char) * my_file.st_size + 1);
    if (error_gestion(argc, argv) == 84)
        return (84);
    if (my_strcmp(argv[1], "-h") == 0)
        h_params(argv);
    else {
        map = do_else(&my_file, map, argv);
        if (my_strcmp(map, "84") == 0)
            return (84);
        new_map = str_to_array(map, '\n');
        return (launch_game(new_map, 2));
    }
}
