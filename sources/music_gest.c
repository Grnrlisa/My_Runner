/*
** EPITECH PROJECT, 2021
** My_Runner
** File description:
** button menu + some evs
*/

#include "assets.h"
#include "my_runner.h"

sfMusic *mus_menu_create(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("sprites/pilotgo.ogg");
    sfMusic_setLoop(loop_sound, sfTrue);
    return (loop_sound);
}

sfMusic *music_create_lvl1(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("sprites/dec14.ogg");
    sfMusic_setLoop(loop_sound, sfTrue);
    return (loop_sound);
}

sfMusic *music_create_lvl2(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("sprites/laughcry2.ogg");
    sfMusic_setLoop(loop_sound, sfTrue);
    return (loop_sound);
}

sfMusic *music_create_game_over(void)
{
    sfMusic *loop_sound;

    loop_sound = sfMusic_createFromFile("sprites/laughcry.ogg");
    sfMusic_setLoop(loop_sound, sfTrue);
    return (loop_sound);
}

void init_sound(s_game *t_game, s_mus_t *s_music)
{
    s_music->menu_sound = mus_menu_create();
    s_music->start_sound = music_create_lvl1();
    s_music->lvl2_sound = music_create_lvl2();
    s_music->over_sound = music_create_game_over();
    s_music->jump_sound = sound_create_jump();
    s_music->hit_sound = sound_create_hit();
    t_game->music.menu_sound = s_music->menu_sound;
    t_game->music.start_sound = s_music->start_sound;
    t_game->music.lvl2_sound = s_music->lvl2_sound;
    t_game->music.over_sound = s_music->over_sound;
    t_game->music.jump_sound = s_music->jump_sound;
    t_game->music.hit_sound = s_music->hit_sound;
}
