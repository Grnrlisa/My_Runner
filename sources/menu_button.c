/*
** EPITECH PROJECT, 2021
** My_Runner
** File description:
** button menu + some evs
*/

#include "assets.h"
#include "my_runner.h"

void ini_button_plus(s_game *t_game)
{
    t_game->but.tx_sett = sfTexture_createFromFile("sprites/b4.png", NULL);
    t_game->but.spr_sett = sfSprite_create();
    sfSprite_setTexture(t_game->but.spr_sett, t_game->but.tx_sett, sfTrue);
    t_game->but.pos_sett.x = 320;
    t_game->but.pos_sett.y = 650;
    sfSprite_setPosition(t_game->but.spr_sett, t_game->but.pos_sett);

    t_game->but.rc.rect.left = 0;
    t_game->but.rc.rect.top = 0;
    t_game->but.rc.rect.height = 90;
    t_game->but.rc.rect.width = 320;
    sfSprite_setTextureRect(t_game->but.spr_lvl1, t_game->but.rc.rect);
    sfSprite_setTextureRect(t_game->but.spr_lvl2, t_game->but.rc.rect);
    sfSprite_setTextureRect(t_game->but.spr_sett, t_game->but.rc.rect);
}

void ini_button(s_game *t_game)
{
    t_game->but.tx_titl = sfTexture_createFromFile("sprites/b1.png", NULL);
    t_game->but.spr_titl = sfSprite_create();
    sfSprite_setTexture(t_game->but.spr_titl, t_game->but.tx_titl, sfTrue);
    t_game->but.pos_titl.x = 200;
    t_game->but.pos_titl.y = 30;
    sfSprite_setPosition(t_game->but.spr_titl, t_game->but.pos_titl);
    t_game->but.tx_lvl1 = sfTexture_createFromFile("sprites/b2.png", NULL);
    t_game->but.spr_lvl1 = sfSprite_create();
    sfSprite_setTexture(t_game->but.spr_lvl1, t_game->but.tx_lvl1, sfTrue);
    t_game->but.pos_lvl1.x = 320;
    t_game->but.pos_lvl1.y = 450;
    sfSprite_setPosition(t_game->but.spr_lvl1, t_game->but.pos_lvl1);
    t_game->but.tx_lvl2 = sfTexture_createFromFile("sprites/b3.png", NULL);
    t_game->but.spr_lvl2 = sfSprite_create();
    sfSprite_setTexture(t_game->but.spr_lvl2, t_game->but.tx_lvl2, sfTrue);
    t_game->but.pos_lvl2.x = 320;
    t_game->but.pos_lvl2.y = 550;
    sfSprite_setPosition(t_game->but.spr_lvl2, t_game->but.pos_lvl2);
    ini_button_plus(t_game);
}

void menu_events_3(s_game *t_game, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mos = sfMouse_getPositionRenderWindow(window);
    if (event->type == sfEvtMouseButtonReleased) {
        if (mos.x >= 320 && mos.x <= 640 && mos.y >= 450 && mos.y <= 540) {
            t_game->scne = 2;
            sfMusic_stop(t_game->music.menu_sound);
            sfMusic_play(t_game->music.start_sound);

        }
        if (mos.x >= 320 && mos.x <= 640 && mos.y >= 550 && mos.y <= 640) {
            t_game->scne = 4;
            sfMusic_stop(t_game->music.menu_sound);
            sfMusic_play(t_game->music.lvl2_sound);
        }
    }
}

void menu_events_2(s_game *t_game, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mos = sfMouse_getPositionRenderWindow(window);
    if (event->type == sfEvtMouseButtonPressed) {
        if (mos.x >= 320 && mos.x <= 640 && mos.y >= 450 && mos.y <= 540) {
            t_game->but.rc.rect.top = 89;
            sfSprite_setTextureRect(t_game->but.spr_lvl1, t_game->but.rc.rect);
        }
        if (mos.x >= 320 && mos.x <= 640 && mos.y >= 550 && mos.y <= 640) {
            t_game->but.rc.rect.top = 89;
            sfSprite_setTextureRect(t_game->but.spr_lvl2, t_game->but.rc.rect);
        }
        if (mos.x >= 320 && mos.x <= 640 && mos.y >= 650 && mos.y <= 740) {
            t_game->but.rc.rect.top = 89;
            sfSprite_setTextureRect(t_game->but.spr_sett, t_game->but.rc.rect);
        }
    }
    menu_events_3(t_game, event, window);
}

void menu_events_1(s_game *t_game, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i m_ps = sfMouse_getPositionRenderWindow(window);
    if (m_ps.x >= 320 && m_ps.x <= 620 && m_ps.y >= 450 && m_ps.y <= 530) {
            t_game->but.rc.rect.top = 178;
            sfSprite_setTextureRect(t_game->but.spr_lvl1, t_game->but.rc.rect);
    } else {
        t_game->but.rc.rect.top = 0;
        sfSprite_setTextureRect(t_game->but.spr_lvl1, t_game->but.rc.rect);
    } if (m_ps.x >= 320 && m_ps.x <= 640 && m_ps.y >= 550 && m_ps.y <= 630) {
            t_game->but.rc.rect.top = 178;
            sfSprite_setTextureRect(t_game->but.spr_lvl2, t_game->but.rc.rect);
    } else {
        t_game->but.rc.rect.top = 0;
        sfSprite_setTextureRect(t_game->but.spr_lvl2, t_game->but.rc.rect);
    } if (m_ps.x >= 320 && m_ps.x <= 640 && m_ps.y >= 650 && m_ps.y <= 730) {
            t_game->but.rc.rect.top = 178;
            sfSprite_setTextureRect(t_game->but.spr_sett, t_game->but.rc.rect);
    } else {
        t_game->but.rc.rect.top = 0;
        sfSprite_setTextureRect(t_game->but.spr_sett, t_game->but.rc.rect);
    } menu_events_2(t_game, event, window);
}
