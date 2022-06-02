/*
** EPITECH PROJECT, 2021
** itoa
** File description:
** int to char *
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int i = 0;
    char *str;
    int tmp = 0;
    tmp = nb;

    while (tmp > 0) {
        tmp = tmp / 10;
        i++;
    }

    str = malloc(sizeof(*str) * (i + 1));
    str[i] = '\0';

    while (i--) {
        str[i] = nb % 10  + '0';
        nb = nb / 10;
    }

    return (str);
}
