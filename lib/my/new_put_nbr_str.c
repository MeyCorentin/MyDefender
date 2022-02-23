/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** It's a program that take a string an return the result as an integer
*/

#include <stdlib.h>

int puissance(int y);
int my_strlen(char const *str);

char *calculs_str(int count, int nb, char *resultat, int cmpt_str)
{
    int result;

    while (count >= 0) {
        count = count - 1;
        result = nb / puissance(count);
        result = result % 10;
        resultat[cmpt_str] = result + 48;
        cmpt_str += 1;
    }
    return (resultat);
}

char *new_put_nbr_str(int nb, char *resultat)
{
    int count = -1;
    int digits = nb;
    int cmpt_str = 0;

    if (nb < 0) {
        nb = nb - nb * 2;
        resultat[cmpt_str] = '-';
        cmpt_str += 1;
    }
    if (nb == 0)
        resultat[cmpt_str] = '0';
    while (digits != 0) {
        digits = digits / 10;
        count = count + 1;
    }
    resultat = calculs_str(count, nb, resultat, cmpt_str);
    return (resultat);
}
