/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** transforme char en int
*/

int my_atoi(char const *str)
{
    int val = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (val);
        str++;
    }
    return (val);
}
