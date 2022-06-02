/*
** EPITECH PROJECT, 2021
** Mu Runner
** File description:
** sprite gest for character
*/

#include "assets.h"
#include "my_runner.h"

void update_movement(s_game *t_game)
{
    if (t_game->bob.jmp == 1 && t_game->bob.status_jump == 1) {
        t_game->bob.pos_pop.y -= 6;
        t_game->bob.pos_pop.x += 2;
        t_game->bob.rect.left = 150;
        if (t_game->bob.pos_pop.y < 400)
            t_game->bob.status_jump = 0;
    } if (t_game->bob.rect.top >= 928)
            t_game->bob.rect.top = 0;
    if (t_game->bob.jmp == 1 && t_game->bob.status_jump == 0) {
        t_game->bob.pos_pop.y += 6;
        if (t_game->bob.pos_pop.y == 620) {
            t_game->bob.jmp = 0;
            t_game->bob.status_jump = 0;
            t_game->bob.rect.left = 0;
            t_game->bob.move_left = 1;
        } if (t_game->bob.move_left == 1 && t_game->bob.pos_pop.x > 100)
            t_game->bob.pos_pop.x -= 2;
    }
    sfSprite_setPosition(t_game->bob.sprite, t_game->bob.pos_pop);
    sfSprite_setTextureRect(t_game->bob.sprite, t_game->bob.rect);
}
