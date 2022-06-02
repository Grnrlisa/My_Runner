/*
** EPITECH PROJECT, 2021
** My_Runner
** File description:
** button menu + some evs
*/

#include "assets.h"
#include "my_runner.h"

sfMusic *sound_create_jump(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("sprites/jump2.ogg");
    return (loop_sound);
}

sfMusic *sound_create_hit(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("sprites/hit.ogg");
    return (loop_sound);
}
