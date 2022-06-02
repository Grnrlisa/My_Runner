/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** parallax
*/

#include "assets.h"
#include "my_runner.h"

void parallax_start2(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->parallax.first_s).x > -1467) {
        sfSprite_setPosition(t_game->parallax.first_s,
                            t_game->parallax.pos_first);
        t_game->parallax.pos_first.x -= 3;
    }
    if (sfSprite_getPosition(t_game->parallax.first_s).x <= -1467) {
        t_game->parallax.pos_first.x = 1464;
        sfSprite_setPosition(t_game->parallax.first_s,
                            t_game->parallax.pos_first);
    }
}

void parallax_start(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->parallax.bck_s).x > -1067) {
        sfSprite_setPosition(t_game->parallax.bck_s,
                            t_game->parallax.pos_bck);
        t_game->parallax.pos_bck.x -= 0.5;
    }
    if (sfSprite_getPosition(t_game->parallax.bck_s).x <= -1067) {
        t_game->parallax.pos_bck.x = 928;
        sfSprite_setPosition(t_game->parallax.bck_s,
                            t_game->parallax.pos_bck);
    }
    if (sfSprite_getPosition(t_game->parallax.bat_s).x > -1067) {
        sfSprite_setPosition(t_game->parallax.bat_s,
                            t_game->parallax.pos_bat);
        t_game->parallax.pos_bat.x -= 1;
    }
    if (sfSprite_getPosition(t_game->parallax.bat_s).x <= -1067) {
        t_game->parallax.pos_bat.x = 928;
        sfSprite_setPosition(t_game->parallax.bat_s,
                            t_game->parallax.pos_bat);
    }
}

void parallax_start4(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->parallax.first_s2).x > -1467) {
        sfSprite_setPosition(t_game->parallax.first_s2,
                            t_game->parallax.pos_fit2);
        t_game->parallax.pos_fit2.x -= 3;
    }
    if (sfSprite_getPosition(t_game->parallax.first_s2).x <= -1467) {
        t_game->parallax.pos_fit2.x = 1464;
        sfSprite_setPosition(t_game->parallax.first_s2,
                            t_game->parallax.pos_fit2);
    }
}

void parallax_start3(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->parallax.bck_s2).x > -1067) {
        sfSprite_setPosition(t_game->parallax.bck_s2,
                            t_game->parallax.pos_bck2);
        t_game->parallax.pos_bck2.x -= 0.5;
    }
    if (sfSprite_getPosition(t_game->parallax.bck_s2).x <= -1067) {
        t_game->parallax.pos_bck2.x = 928;
        sfSprite_setPosition(t_game->parallax.bck_s2,
                            t_game->parallax.pos_bck2);
    }
    if (sfSprite_getPosition(t_game->parallax.bat_s2).x > -1067) {
        sfSprite_setPosition(t_game->parallax.bat_s2,
                            t_game->parallax.pos_bat2);
        t_game->parallax.pos_bat2.x -= 1;
    }
    if (sfSprite_getPosition(t_game->parallax.bat_s2).x <= -1067) {
        t_game->parallax.pos_bat2.x = 928;
        sfSprite_setPosition(t_game->parallax.bat_s2,
                            t_game->parallax.pos_bat2);
    }
}
