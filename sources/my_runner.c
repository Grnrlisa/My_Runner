/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** my_runner
*/

#include "assets.h"
#include "my_runner.h"

void destroy_objects(object_t *objects)
{
    object_t *prev_object = NULL;

    while (objects != NULL) {
        prev_object = objects;
        objects = objects->next;
        sfSprite_destroy(prev_object->sprite);
        sfTexture_destroy(prev_object->texture);
        free(prev_object);
    }
}

void destroy_music(s_mus_t *s_music)
{
    sfMusic_destroy(s_music->start_sound);
    sfMusic_destroy(s_music->lvl2_sound);
    sfMusic_destroy(s_music->menu_sound);
    sfMusic_destroy(s_music->over_sound);
    sfMusic_destroy(s_music->jump_sound);
    sfMusic_destroy(s_music->hit_sound);
}

void init_evrthng(s_game *t_game, s_mus_t *s_music)
{
    init_bob(t_game);
    init_bird(t_game);
    set_parallax(t_game);
    ini_parallax(t_game);
    ini_menu(t_game);
    init_health(t_game);
    ini_menu_annex(t_game);
    ini_button(t_game);
    init_score(t_game);
    ini_game_over(t_game);
    init_sound(t_game, s_music);
}

int init_runner(s_game *t_game, sfRenderWindow *window, sfEvent *event,
                s_mus_t *s_music)
{
    t_game->scne = 1;
    t_game->is_game_win = 0;
    object_t *objects = gest_objects(t_game->file);

    init_evrthng(t_game, s_music);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfMusic_play(t_game->music.menu_sound);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        t_game->check = events(window, t_game, event);
        display_scnes(t_game, window, event);
        display_obj(objects, window, t_game);
        check_collisions(objects, t_game);
        sfRenderWindow_display(window);
    }
    destroy_music(s_music);
    destroy_objects(objects);
    return (t_game->check);
}
