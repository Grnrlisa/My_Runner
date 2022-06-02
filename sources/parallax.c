/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** test
*/

#include "assets.h"
#include "my_runner.h"

void clock_parallax(s_game *t_game)
{
    t_game->parallax.time_paral =
    sfClock_getElapsedTime(t_game->parallax.clock_paral);
    t_game->parallax.sec_paral =
    t_game->parallax.time_paral.microseconds / 1000000.0f;
}

void set_parallax_2(s_game *t_game)
{
    t_game->parallax.bck_t2 = sfTexture_createFromFile
        ("sprites/bck_1.png", NULL);
    t_game->parallax.bat_t2 = sfTexture_createFromFile
        ("sprites/bck_2.png", NULL);
    t_game->parallax.first_t2 = sfTexture_createFromFile
        ("sprites/bck_3.png", NULL);
    t_game->parallax.bck_s2 = sfSprite_create();
    t_game->parallax.bat_s2 = sfSprite_create();
    t_game->parallax.first_s2 = sfSprite_create();
    sfSprite_setTexture(t_game->parallax.bck_s2,
                        t_game->parallax.bck_t2, sfTrue);
    sfSprite_setTexture(t_game->parallax.bat_s2,
                        t_game->parallax.bat_t2, sfTrue);
    sfSprite_setTexture(t_game->parallax.first_s2,
                        t_game->parallax.first_t2, sfTrue);
}

void set_parallax(s_game *t_game)
{
    t_game->parallax.clock_paral = sfClock_create();
    t_game->parallax.bck_t = sfTexture_createFromFile
        ("sprites/bck_1.png", NULL);
    t_game->parallax.bat_t = sfTexture_createFromFile
        ("sprites/bck_2.png", NULL);
    t_game->parallax.first_t = sfTexture_createFromFile
        ("sprites/bck_3.png", NULL);
    t_game->parallax.bck_s = sfSprite_create();
    t_game->parallax.bat_s = sfSprite_create();
    t_game->parallax.first_s = sfSprite_create();
    sfSprite_setTexture(t_game->parallax.bck_s,
                        t_game->parallax.bck_t, sfTrue);
    sfSprite_setTexture(t_game->parallax.bat_s,
                        t_game->parallax.bat_t, sfTrue);
    sfSprite_setTexture(t_game->parallax.first_s,
                        t_game->parallax.first_t, sfTrue);
    set_parallax_2(t_game);
}

void parallax(sfRenderWindow *window, s_game *t_game)
{
    sfRenderWindow_drawSprite(window, t_game->parallax.bck_s, NULL);
    sfRenderWindow_drawSprite(window, t_game->parallax.bck_s2, NULL);
    sfRenderWindow_drawSprite(window, t_game->parallax.bat_s, NULL);
    sfRenderWindow_drawSprite(window, t_game->parallax.bat_s2, NULL);
    sfRenderWindow_drawSprite(window, t_game->parallax.first_s, NULL);
    sfRenderWindow_drawSprite(window, t_game->parallax.first_s2, NULL);
    clock_parallax(t_game);
    if (t_game->parallax.sec_paral > 0.1) {
        parallax_start(t_game);
        parallax_start2(t_game);
        parallax_start3(t_game);
        parallax_start4(t_game);
    }
}

void ini_parallax(s_game *t_game)
{
    t_game->parallax.pos_first.x = 0;
    t_game->parallax.pos_first.y = 0;
    t_game->parallax.pos_bck.x = 0;
    t_game->parallax.pos_bck.y = 0;
    t_game->parallax.pos_bat.x = 0;
    t_game->parallax.pos_bat.y = 0;
    sfSprite_setPosition(t_game->parallax.first_s, t_game->parallax.pos_first);
    sfSprite_setPosition(t_game->parallax.bck_s, t_game->parallax.pos_bck);
    sfSprite_setPosition(t_game->parallax.bat_s, t_game->parallax.pos_bat);
    t_game->parallax.pos_fit2.x = 1467;
    t_game->parallax.pos_fit2.y = 0;
    t_game->parallax.pos_bck2.x = 1067;
    t_game->parallax.pos_bck2.y = 0;
    t_game->parallax.pos_bat2.x = 1067;
    t_game->parallax.pos_bat2.y = 0;
    sfSprite_setPosition(t_game->parallax.first_s2, t_game->parallax.pos_fit2);
    sfSprite_setPosition(t_game->parallax.bck_s2, t_game->parallax.pos_bck2);
    sfSprite_setPosition(t_game->parallax.bat_s2, t_game->parallax.pos_bat2);
}
