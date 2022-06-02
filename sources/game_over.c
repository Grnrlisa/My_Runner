/*
** EPITECH PROJECT, 2021
** My_Runner
** File description:
** ini menu + parallaxs
*/

#include "assets.h"
#include "my_runner.h"

void ini_game_over_txt_annex(s_game *t_game)
{
    t_game->ovr.scr_o2 = sfText_create();
    sfText_setFont(t_game->ovr.scr_o2, t_game->ovr.font_o);
    sfText_setColor(t_game->ovr.scr_o2, sfMagenta);
    t_game->ovr.pos_scr_o2.x = 650;
    t_game->ovr.pos_scr_o2.y = 170;
    sfText_setCharacterSize(t_game->ovr.scr_o2, 40);
    sfText_setPosition(t_game->ovr.scr_o2, t_game->ovr.pos_scr_o2);

    t_game->ovr.r = sfText_create();
    sfText_setFont(t_game->ovr.r, t_game->ovr.font_o);
    sfText_setColor(t_game->ovr.r, sfMagenta);
    t_game->ovr.pos_retry.x = 500;
    t_game->ovr.pos_retry.y = 760;
    sfText_setCharacterSize(t_game->ovr.r, 20);
    sfText_setPosition(t_game->ovr.r, t_game->ovr.pos_retry);
}

void ini_game_over_txt(s_game *t_game)
{
    t_game->ovr.font_o = sfFont_createFromFile("sprites/drab.otf");

    t_game->ovr.text_o = sfText_create();
    sfText_setFont(t_game->ovr.text_o, t_game->ovr.font_o);
    sfText_setColor(t_game->ovr.text_o, sfMagenta);
    t_game->ovr.pos_txt_o.x = 370;
    t_game->ovr.pos_txt_o.y = 80;
    sfText_setCharacterSize(t_game->ovr.text_o, 80);
    sfText_setPosition(t_game->ovr.text_o, t_game->ovr.pos_txt_o);

    t_game->ovr.scr_o = sfText_create();
    sfText_setFont(t_game->ovr.scr_o, t_game->ovr.font_o);
    sfText_setColor(t_game->ovr.scr_o, sfMagenta);
    t_game->ovr.pos_scr_o.x = 430;
    t_game->ovr.pos_scr_o.y = 170;
    sfText_setCharacterSize(t_game->ovr.scr_o, 40);
    sfText_setPosition(t_game->ovr.scr_o, t_game->ovr.pos_scr_o);
    ini_game_over_txt_annex(t_game);
}

void ini_game_over(s_game *t_game)
{
    t_game->ovr.bcktx = sfTexture_createFromFile("sprites/gamover2.png", NULL);
    t_game->ovr.bobtx = sfTexture_createFromFile("sprites/bob_go3.png", NULL);
    t_game->ovr.spr_bck_o = sfSprite_create();
    t_game->ovr.spr_bob_o = sfSprite_create();
    sfSprite_setTexture(t_game->ovr.spr_bck_o, t_game->ovr.bcktx, sfTrue);
    sfSprite_setTexture(t_game->ovr.spr_bob_o, t_game->ovr.bobtx, sfTrue);
    t_game->ovr.pos_bck_o.x = 0;
    t_game->ovr.pos_bck_o.y = 0;
    t_game->ovr.pos_bob_o.x = -20;
    t_game->ovr.pos_bob_o.y = 150;
    sfSprite_setPosition(t_game->ovr.spr_bck_o, t_game->ovr.pos_bck_o);
    sfSprite_setPosition(t_game->ovr.spr_bob_o, t_game->ovr.pos_bob_o);
    t_game->ovr.rect.height = 580;
    t_game->ovr.rect.width = 500;
    t_game->ovr.rect.left = 30;
    t_game->ovr.reset = 0;
    t_game->ovr.rect.top = 50;
    sfSprite_setTextureRect(t_game->ovr.spr_bob_o, t_game->ovr.rect);

    ini_game_over_txt(t_game);
}

void bob_over_animation(s_game *t_game)
{
    clock_bob(t_game);
    if (t_game->bob.sec > 0.2) {
        if (t_game->ovr.rect.top <= 0)
            t_game->ovr.reset = 0;
        if (t_game->ovr.reset == 0)
            t_game->ovr.rect.top += 574.75;
        if (t_game->ovr.rect.top >= 2200)
            t_game->ovr.rect.top = 50;
        sfClock_restart(t_game->bob.clock_bob);
    }
    sfSprite_setTextureRect(t_game->ovr.spr_bob_o, t_game->ovr.rect);
}

void is_game_over(s_game *t_game, sfRenderWindow *window)
{
    int recup_scr = recup_score_on_file();
    sfRenderWindow_drawSprite(window, t_game->ovr.spr_bck_o, NULL);
    bob_over_animation(t_game);
    sfRenderWindow_drawSprite(window, t_game->ovr.spr_bob_o, NULL);
    if (t_game->is_game_win == 1) {
        write_on_file("sources/score", my_itoa(t_game->scr.score));
        sfText_setString(t_game->ovr.text_o, "You Win");
        t_game->ovr.pos_txt_o.x = 430;
        sfText_setPosition(t_game->ovr.text_o, t_game->ovr.pos_txt_o);
    } else if (t_game->is_game_win == 0) {
        write_on_file("sources/score", my_itoa(t_game->scr.score));
        sfText_setString(t_game->ovr.text_o, "Game Over");
    }
    sfRenderWindow_drawText(window, t_game->ovr.text_o, NULL);
    sfText_setString(t_game->ovr.scr_o, "    score : ");
    sfRenderWindow_drawText(window, t_game->ovr.scr_o, NULL);
    sfText_setString(t_game->ovr.scr_o2, my_itoa(recup_scr));
    sfRenderWindow_drawText(window, t_game->ovr.scr_o2, NULL);
    sfText_setString(t_game->ovr.r, "Press [ESCAPE] to go back to main menu");
    sfRenderWindow_drawText(window, t_game->ovr.r, NULL);
}
