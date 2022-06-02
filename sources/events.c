/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** events gest
*/

#include "assets.h"
#include "my_runner.h"

int rerun_game(s_game *t_game, s_mus_t *s_music,
                sfRenderWindow *window, sfEvent *event)
{
    if (t_game->restart == 0) {
        t_game->check = 1;
        return (t_game->check);
    }
    if (t_game->restart != 0) {
    t_game->scr.score = 0;
    init_runner(t_game, window, event, s_music);
    t_game->check = 2;
    return (t_game->check);
    }
    return (0);
}

void analyse_evs(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void annex_jump(s_game *t_game)
{
    if (t_game->bob.jmp == 1)
        update_movement(t_game);
    if (t_game->bob.jmp == 0)
        sfMusic_pause(t_game->music.jump_sound);
}

int events(sfRenderWindow *window, s_game *t_game, sfEvent *event)
{
    s_mus_t s_music;
    while (sfRenderWindow_pollEvent(window, event)) {
        analyse_evs(window, event);
        if (sfKeyboard_isKeyPressed(sfKeySpace) && t_game->bob.pos_pop.y == 620
        && t_game->bob.jmp == 0 && (t_game->scne == 2 || t_game->scne == 4)) {
                t_game->bob.jmp = 1;
                t_game->bob.status_jump = 1;
                sfMusic_play(t_game->music.jump_sound);
        } if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            t_game->restart = 1;
            sfMusic_stop(t_game->music.start_sound);
            sfMusic_stop(t_game->music.lvl2_sound);
            sfMusic_stop(t_game->music.over_sound);
            sfMusic_stop(t_game->music.menu_sound);
            t_game->check = rerun_game(t_game, &s_music, window, event);
            return (t_game->check);
        }
    } annex_jump(t_game);
    return (0);
}
