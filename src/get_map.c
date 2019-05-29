/*
** EPITECH PROJECT, 2018
** get map
** File description:
** get map
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"
#include <fcntl.h>
#include <stdlib.h>

void malloc_map(sokoban_t *sokoban, char const *path)
{
    char *line = NULL;
    size_t len = 0;
    int size = 0;
    FILE *fp;

    fp = fopen(path, "r");
    while ((getline(&line, &len, fp)) != -1)
        size++;
    sokoban->col_size = size - 1;
    sokoban->map = malloc(sizeof(char *) * (size + 1));
    while (size != 0) {
        sokoban->map[size] = NULL;
        size--;
    }
    fclose(fp);
    if (line)
        free(line);
}

void malloc_save_map(sokoban_t *sokoban, char const *path)
{
    char *line = NULL;
    size_t len = 0;
    int size = 0;
    FILE *fp;

    fp = fopen(path, "r");
    while ((getline(&line, &len, fp)) != -1)
        size++;
    sokoban->save_map = malloc(sizeof(char *) * (size + 1));
    while (size != 0) {
        sokoban->save_map[size] = NULL;
        size--;
    }
    fclose(fp);
    if (line)
        free(line);
}

void get_map(sokoban_t *sokoban, char const *path)
{
    FILE *fp;
    char *line = NULL;
    int i = 0;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL) {
        my_putstr("Can't open the file\n");
        exit(84);
    }
    malloc_map(sokoban, path);
    while ((read = getline(&line, &len, fp)) != -1) {
        sokoban->len_size = read;
        sokoban->map[i] = line;
        line = NULL;
        i++;
    }
    sokoban->map[i] = '\0';
    fclose(fp);
    free(line);
}

void get_save_map(sokoban_t *sokoban, char const *path)
{
    FILE *fp;
    char *line = NULL;
    int i = 0;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL) {
        my_putstr("Can't open the file\n");
        exit(84);
    }
    malloc_save_map(sokoban, path);
    while ((read = getline(&line, &len, fp)) != -1) {
        sokoban->save_map[i] = line;
        line = NULL;
        i++;
    }
    sokoban->save_map[i] = '\0';
    fclose(fp);
    free(line);
}
