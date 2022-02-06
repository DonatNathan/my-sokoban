/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the .h of my sokoban
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include "my.h"
    #include <stdlib.h>
    #include <curses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <locale.h>
    #include <sys/ioctl.h>

struct char_map {
    int cmpt_x;
    int cmpt_o;
    int cmpt_p;
    int cmpt_return;
};
typedef struct char_map char_map;

struct positions {
    int cible;
    int player;
    int obstacle;
    char *map;
    int pos_end;
    int pos_caisse;
    int what_is;
    int change;
    int in_o;
};
typedef struct positions positions;

char *get_map(char **argv, struct stat *my_file);
int launch_game(char *map);
int check_defeat(positions *pos_map, int size_line);
void test_size(char *map);

#endif /* SOKOBAN_H_ */
