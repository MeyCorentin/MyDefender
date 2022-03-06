/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the main file of my program "my_defender"
*/

#include "../../includes/my_defender.h"

int read_level(void)
{
    char *buffer = malloc(sizeof(char) * 2);
    int fd = open("src/txt/level", O_RDONLY);
    char *level = malloc(sizeof(char) * 3);
    int cmpt;

    read(fd, buffer, 2);
    for (cmpt = 0; cmpt != 2; cmpt += 1)
        level[cmpt] = buffer[cmpt];
    level[cmpt] = '\0';
    close(fd);
    return (my_getnbr(level));
}

void draw_help(void)
{
    my_printf("\n\n\n############### MY DEFENDER ###############\n\n");
    my_printf("The goal of our game is to protect the \nTown Hall from waves \
of ennemis. \nTo do this, we must buy differents towers \nto kill ennemis.\n");
    my_printf("We have 10 levels and, when the game is \nlaunch, we can \
choose to continue our \nsession or to restart a new game.\n\n");
    my_printf("Commands : \n");
    my_printf("-> In menu : \n\tR : Restart\n\tC : Continue\n\tQ : Quit\n");
    my_printf("-> In game : \n\tEscape : Pause\n\tS : Shop\n\tO : \
Cheatmod\n\n");
    my_printf("By : Corentin & Nathan\n");
}

int error_gestion(int argc, char **argv, int level)
{
    if (argc > 2)
        return (84);
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        draw_help();
    else if (argc == 1)
        create_window(level);
    else
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    int level = read_level();

    if (error_gestion(argc, argv, level) == 84)
        return (84);
    return (0);
}
