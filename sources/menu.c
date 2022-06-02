/*
** EPITECH PROJECT, 2021
** My_Runner
** File description:
** ini menu + parallaxs
*/

#include "assets.h"
#include "my_runner.h"

void ini_menu(s_game *t_game)
{
    t_game->menu.txt1 = sfTexture_createFromFile("sprites/menu1.png", NULL);
    t_game->menu.sprite1 = sfSprite_create();
    sfSprite_setTexture(t_game->menu.sprite1, t_game->menu.txt1, sfTrue);
    t_game->menu.pos1.x = 0;
    t_game->menu.pos1.y = 0;
    t_game->menu.txt2 = sfTexture_createFromFile("sprites/menu2.png", NULL);
    t_game->menu.sprite2 = sfSprite_create();
    sfSprite_setTexture(t_game->menu.sprite2, t_game->menu.txt2, sfTrue);
    t_game->menu.pos2.x = 0;
    t_game->menu.pos2.y = 10;
    sfSprite_setPosition(t_game->menu.sprite2, t_game->menu.pos2);
}

void ini_menu_annex(s_game *t_game)
{
    t_game->menu.sprite22 = sfSprite_create();
    sfSprite_setTexture(t_game->menu.sprite22, t_game->menu.txt2, sfTrue);
    t_game->menu.sprite12 = sfSprite_create();
    sfSprite_setTexture(t_game->menu.sprite12, t_game->menu.txt1, sfTrue);
    t_game->menu.pos12.x = 939;
    sfSprite_setPosition(t_game->menu.sprite12, t_game->menu.pos12);
    t_game->menu.pos22.x = -1410;
    t_game->menu.pos22.y = 10;
    sfSprite_setPosition(t_game->menu.sprite22, t_game->menu.pos22);
}

void parallax_menu_start(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->menu.sprite1).x > -940) {
        sfSprite_setPosition(t_game->menu.sprite1, t_game->menu.pos1);
        t_game->menu.pos1.x -= 0.3;
    }
    if (sfSprite_getPosition(t_game->menu.sprite1).x <= -940) {
        t_game->menu.pos1.x = 935;
        sfSprite_setPosition(t_game->menu.sprite1, t_game->menu.pos1);
    }
    if (sfSprite_getPosition(t_game->menu.sprite12).x > -940) {
        sfSprite_setPosition(t_game->menu.sprite12, t_game->menu.pos12);
        t_game->menu.pos12.x -= 0.3;
    }
    if (sfSprite_getPosition(t_game->menu.sprite12).x <= -940) {
        t_game->menu.pos12.x = 935;
        sfSprite_setPosition(t_game->menu.sprite12, t_game->menu.pos12);
    }
}

void parallax_menu_start_2(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->menu.sprite2).x > -1410) {
        sfSprite_setPosition(t_game->menu.sprite2, t_game->menu.pos2);
        t_game->menu.pos2.x += 0.5;
    }
    if (sfSprite_getPosition(t_game->menu.sprite2).x >= 1410) {
        t_game->menu.pos2.x = -1400;
        sfSprite_setPosition(t_game->menu.sprite2, t_game->menu.pos2);
    }
    if (sfSprite_getPosition(t_game->menu.sprite22).x >= -1410) {
        sfSprite_setPosition(t_game->menu.sprite22, t_game->menu.pos22);
        t_game->menu.pos22.x += 0.5;
    }
    if (sfSprite_getPosition(t_game->menu.sprite22).x >= 1410) {
        t_game->menu.pos22.x = -1400;
        sfSprite_setPosition(t_game->menu.sprite22, t_game->menu.pos22);
    }
}

void menu_is_open(sfRenderWindow *wdw, s_game *t_game, sfEvent *event)
{
    sfRenderWindow_drawSprite(wdw, t_game->menu.sprite1, NULL);
    sfRenderWindow_drawSprite(wdw, t_game->menu.sprite12, NULL);
    sfRenderWindow_drawSprite(wdw, t_game->menu.sprite2, NULL);
    sfRenderWindow_drawSprite(wdw, t_game->menu.sprite22, NULL);
    clock_parallax(t_game);
    if (t_game->parallax.sec_paral > 0.1) {
        parallax_menu_start(t_game);
        parallax_menu_start_2(t_game);
    }
    display_butt(wdw, t_game);
    menu_events_1(t_game, event, wdw);
}
