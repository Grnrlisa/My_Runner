/*
** EPITECH PROJECT, 2021
** Mu Runner
** File description:
** sprite gest for character
*/

#include "assets.h"
#include "my_runner.h"

void filter_lvl_2(s_game *t_game)
{
    sfTexture *txt = sfTexture_createFromFile("sprites/filter.png", NULL);
    sfVector2f pos_pop;
    pos_pop.y = 0;
    pos_pop.x = 0;
    t_game->parallax.filter = sfSprite_create();
    sfSprite_setTexture(t_game->parallax.filter, txt, sfTrue);
    sfSprite_setPosition( t_game->parallax.filter, pos_pop);
}

void lvl_2_enm(s_game *t_game)
{
    if (sfSprite_getPosition(t_game->bird.sprite).x > -70) {
        sfSprite_setPosition(t_game->bird.sprite, t_game->bird.pos_pop);
        t_game->bird.pos_pop.x -= 9;
    }
    if (sfSprite_getPosition(t_game->bird.sprite).x <= -70) {
        t_game->bird.pos_pop.x = 900;
        sfSprite_setPosition(t_game->bird.sprite, t_game->bird.pos_pop);
        t_game->bird.pos_pop.x -= 9;
    }
    if (sfSprite_getPosition(t_game->bird.sprite2).x > -70) {
        sfSprite_setPosition(t_game->bird.sprite2, t_game->bird.pos_pop2);
        t_game->bird.pos_pop2.x -= 11;
    }
    if (sfSprite_getPosition(t_game->bird.sprite2).x <= -70) {
        t_game->bird.pos_pop2.x = 1200;
        sfSprite_setPosition(t_game->bird.sprite2, t_game->bird.pos_pop2);
    }
}

void init_bird(s_game *t_game)
{
    t_game->bird.reset = 0;
    t_game->bird.pos_pop2.x = 1200;
    t_game->bird.pos_pop2.y = 620;
    t_game->bird.pos_pop.x = 930;
    t_game->bird.pos_pop.y = 620;
    t_game->bird.area.left = 5;
    t_game->bird.area.top = 0;
    t_game->bird.area.height = 120;
    t_game->bird.nb = 4;
    t_game->bird.area.width = 127;
    t_game->bird.txt = sfTexture_createFromFile("sprites/shootbig.png", NULL);
    t_game->bird.sprite = sfSprite_create();
    t_game->bird.sprite2 = sfSprite_create();
    sfSprite_setTexture(t_game->bird.sprite2, t_game->bird.txt, sfTrue);
    sfSprite_setTexture(t_game->bird.sprite, t_game->bird.txt, sfTrue);
    sfSprite_setTextureRect(t_game->bird.sprite, t_game->bird.area);
    sfSprite_setTextureRect(t_game->bird.sprite2, t_game->bird.area);
    sfSprite_setPosition(t_game->bird.sprite, t_game->bird.pos_pop);
    sfSprite_setPosition(t_game->bird.sprite2, t_game->bird.pos_pop2);
}
