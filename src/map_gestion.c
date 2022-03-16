/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to verify my map
*/

#include "../includes/sokoban.h"

int check_if_auto(char my_char)
{
    char *autorized_char = "\n XOP#";

    for (int cmpt = 0; autorized_char[cmpt] != '\0'; cmpt += 1)
        if (my_char == autorized_char[cmpt])
            return (0);
    return (1);
}

int count_line(char *map)
{
    int cmpt_line = 0;

    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1)
        if (map[cmpt] == '\n')
            cmpt_line += 1;
    return (cmpt_line);
}

void count_char(char_map *num_chars, char my_char)
{
    if (my_char == 'X')
        num_chars->cmpt_x += 1;
    if (my_char == 'P')
        num_chars->cmpt_p += 1;
    if (my_char == 'O')
        num_chars->cmpt_o += 1;
    if (my_char == '\n')
        num_chars->cmpt_return += 1;
}

int check_map(char *map)
{
    char_map *num_chars = malloc(sizeof(char_map));

    num_chars->cmpt_x = 0;
    num_chars->cmpt_o = 0;
    num_chars->cmpt_p = 0;
    num_chars->cmpt_return = 0;
    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1) {
        if (check_if_auto(map[cmpt]) == 1) {
            write(2, "invalid character\n", 18);
            return (84);
        }
        count_char(num_chars, map[cmpt]);
    }
    if (num_chars->cmpt_x != num_chars->cmpt_o || num_chars->cmpt_p != 1 || \
        num_chars->cmpt_return != count_line(map)) {
        write(2, "invalid number of char\n", 23);
        return (84);
    }
}

char *get_map(char **argv, struct stat *my_file)
{
    int file_desc = open(argv[1], O_RDONLY);
    char buffer[my_file->st_size];
    char *map = malloc(sizeof(char) * my_file->st_size + 1);
    int cmpt;

    if (read(file_desc, buffer, my_file->st_size) == -1 || file_desc == -1) {
        write(2, "failed to read\n", 15);
        return ("84");
    }
    for (cmpt = 0; cmpt != my_file->st_size; cmpt += 1)
        map[cmpt] = buffer[cmpt];
    map[cmpt] = '\0';
    if (check_map(map) == 84)
        return ("84");
    return (map);
}
