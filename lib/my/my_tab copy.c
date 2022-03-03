/*
** EPITECH PROJECT, 2022
** my_tab.c
** File description:
** my_tab.c
*/

#include <stdlib.h>
#include "../../includes/my.h"

int my_count_split(char *argv, char char_) {
    int i = 0;
    int j = 0;

    for (; argv[i] != '\0'; i++) {
        if (argv[i] == char_)
            j++;
    }
    return (j + 1);
}

void my_print_tab(char **tab) {
    int k = 0;
    int i = 0;

    for (k; tab[k]; k++) {
        my_putstr(tab[k]);
        my_putchar('\n');
    }
}

char **my_malloc_tab(char **tab, int colum, int lines) {
    char **temp = malloc(sizeof(char*) * (colum + 1));
    int k = 0;

    for (; k != colum; k++)
        temp[k] = malloc(sizeof(char) * lines);
    return (temp);
}

char **my_split_tab(char * argv, char char_)
{
    int k = 0;
    int l = 0;
    int i = 0;
    int j = my_count_split(argv, char_);
    char **tab;

    tab = my_malloc_tab(tab, my_count_split(argv, char_), my_strlen(argv));
    for (; argv[k]  != '\0'; k++, l++) {
        if (argv[k] == char_) {
            l++;
            k++;
            tab[i][l] = '\0';
            l = 0;
            i++;
        }
        tab[i][l] = argv[k];
        tab[i][l + 1] = '\0';
    }
    tab[i + 1] = '\0';
    return (tab);
}

char **my_add_tab(char **tab, char * argv) {
    int k = 0;

    for (; tab[k]; k++);
    tab[k] = argv;
    tab[k + 1] = NULL;
    return (tab);
}