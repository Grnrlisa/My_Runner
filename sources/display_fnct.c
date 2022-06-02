/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** my_runner
*/

#include "assets.h"
#include "my_runner.h"

void display_obj(object_t *object, sfRenderWindow *window, s_game *t_game)
{
    sfVector2f offset;
    sfVector2f obj_pos;

    while (object != NULL && t_game->scne == 2) {
        offset.x = -5;
        offset.y = 0;
        obj_pos = sfSprite_getPosition(object->sprite);
        sfSprite_move(object->sprite, offset);
        if (obj_pos.x < 1000 && obj_pos.x > -100) {
            obj_animation(object);
            sfRenderWindow_drawSprite(window, object->sprite, NULL);
        }
        object = object->next;
    }
}

void display_scnes_2(s_game *t_game, sfRenderWindow *wdw)
{
    if (t_game->scne == 4) {
        sfRenderWindow_clear(wdw, sfBlack);
        filter_lvl_2(t_game);
        parallax(wdw, t_game);
        bob_animation(t_game);
        sfRenderWindow_drawSprite(wdw, t_game->bob.sprite, NULL);
        sfRenderWindow_drawSprite(wdw, t_game->bird.sprite, NULL);
        sfRenderWindow_drawSprite(wdw, t_game->bird.sprite2, NULL);
        lvl_2_enm(t_game);
        sfRenderWindow_drawSprite(wdw,  t_game->parallax.filter, NULL);
        put_score(t_game, wdw);
    }
}

void display_scnes(s_game *t_game, sfRenderWindow *window, sfEvent *event)
{
    if (t_game->scne == 1)
        menu_is_open(window, t_game, event);
    if (t_game->scne == 2) {
        parallax(window, t_game);
        bob_animation(t_game);
        sfRenderWindow_drawSprite(window, t_game->bob.sprite, NULL);
        sfRenderWindow_drawSprite(window, t_game->lif.sprite2, NULL);
        sfRenderWindow_drawSprite(window, t_game->lif.sprite, NULL);
        put_score(t_game, window);
        }
    if (t_game->scne == 3)
        is_game_over(t_game, window);
    display_scnes_2(t_game, window);
}

void display_butt(sfRenderWindow *window, s_game *t_game)
{
    sfRenderWindow_drawSprite(window, t_game->but.spr_titl, NULL);
    sfRenderWindow_drawSprite(window, t_game->but.spr_lvl1, NULL);
    sfRenderWindow_drawSprite(window, t_game->but.spr_lvl2, NULL);
    sfRenderWindow_drawSprite(window, t_game->but.spr_sett, NULL);
}
