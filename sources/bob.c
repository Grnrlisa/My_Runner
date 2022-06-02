/*
** EPITECH PROJECT, 2021
** Mu Runner
** File description:
** sprite gest for character
*/

#include "assets.h"
#include "my_runner.h"

void texture_lifz(s_game *t_game)
{
    sfVector2f scale;
    scale.y = 1;
    scale.x = ((float)t_game->lif.points / (float)40);
    sfSprite_setScale(t_game->lif.sprite, scale);

    if (t_game->lif.points == 0) {
        sfMusic_stop(t_game->music.start_sound);
        sfMusic_play(t_game->music.over_sound);
        t_game->lif.area.top = 108;
        t_game->is_game_win = 0;
        t_game->scne = 3;
        write_on_file("sources/score", my_itoa(t_game->scr.score));
    }
}

void init_health(s_game *t_game)
{
    t_game->lif.pos_pop.x = 10;
    t_game->lif.pos_pop.y = 10;
    t_game->lif.points = 40;

    t_game->lif.txt1 = sfTexture_createFromFile("sprites/healhbar1.png", NULL);
    t_game->lif.txt2 = sfTexture_createFromFile("sprites/healtbar2.png", NULL);
    t_game->lif.sprite = sfSprite_create();
    t_game->lif.sprite2 = sfSprite_create();
    sfSprite_setTexture(t_game->lif.sprite, t_game->lif.txt1, sfTrue);
    sfSprite_setTexture(t_game->lif.sprite2, t_game->lif.txt2, sfTrue);
    sfSprite_setPosition(t_game->lif.sprite, t_game->lif.pos_pop);
    sfSprite_setPosition(t_game->lif.sprite2, t_game->lif.pos_pop);
}

void clock_bob(s_game *t_game)
{
    t_game->bob.time = sfClock_getElapsedTime(t_game->bob.clock_bob);
    t_game->bob.sec = t_game->bob.time.microseconds / 1000000.0f;
}

void bob_animation(s_game *t_game)
{
    clock_bob(t_game);
    if (t_game->bob.sec > 0.1) {
        if (t_game->bob.rect.top <= 0)
            t_game->bob.reset = 0;
        if (t_game->bob.reset == 0)
            t_game->bob.rect.top += 140;
        if (t_game->bob.rect.top >= 1100)
            t_game->bob.rect.top = 0;
        sfSprite_setTextureRect(t_game->bob.sprite, t_game->bob.rect);
        sfClock_restart(t_game->bob.clock_bob);
    }
}

void init_bob(s_game *t_game)
{
    t_game->bob.reset = 0;
    t_game->bob.move_left = 0;
    t_game->bob.pos_pop.x = 100;
    t_game->bob.pos_pop.y = 620;
    t_game->bob.rect.left = 5;
    t_game->bob.rect.top = 0;
    t_game->bob.jmp = 0;
    t_game->status_hit = 1;
    t_game->bob.status_jump = 0;
    t_game->bob.rect.height = 120;
    t_game->bob.rect.width = 120;
    t_game->bob.speed.x = 2;
    t_game->bob.txt = sfTexture_createFromFile("sprites/runcompall.png", NULL);
    t_game->bob.sprite = sfSprite_create();
    sfSprite_setTexture(t_game->bob.sprite, t_game->bob.txt, sfTrue);
    sfSprite_setTextureRect(t_game->bob.sprite, t_game->bob.rect);
    sfSprite_setPosition(t_game->bob.sprite, t_game->bob.pos_pop);
    t_game->bob.clock_bob = sfClock_create();
}
