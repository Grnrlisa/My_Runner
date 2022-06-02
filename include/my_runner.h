/*
** EPITECH PROJECT, 2021
** My_Runner
** File description:
** .h for my_runner prjct
*/

#ifndef MY_RUNNER_H
    #define MY_RUNNER_H

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <SFML/Config.h>
    #include <SFML/System.h>
    #include <SFML/Network.h>
    #include <SFML/Window.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>

    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    char *my_itoa(int nb);
    int my_atoi(char const *str);

    int rerun_game(s_game *t_game, s_mus_t *s_music,
                    sfRenderWindow *window, sfEvent *event);

    void init_evrthng(s_game *t_game, s_mus_t *s_music);
    void init_bob(s_game *t_game);
    int init_runner(s_game *t_game, sfRenderWindow *window,
                    sfEvent *event, s_mus_t *music);
    void ini_parallax(s_game *t_game);
    void ini_menu(s_game *t_game);
    void ini_button(s_game *t_game);
    void init_cops(s_game *t_game);
    void init_sound(s_game *t_game, s_mus_t *s_music);
    void init_health(s_game *t_game);
    void ini_menu(s_game *t_game);
    void ini_menu_annex(s_game *t_game);
    void init_score(s_game *t_game);
    void ini_game_over(s_game *t_game);

    void bob_animation(s_game *t_game);
    void clock_bob(s_game *t_game);
    void update_movement(s_game *t_game);
    void obj_animation(object_t *object);
    void clock_obj(object_t *object);
    int check_collisions(object_t *object, s_game *t_game);
    void texture_lifz(s_game *t_game);

    void set_parallax(s_game *t_game);
    void clock_parallax(s_game *t_game);
    void parallax(sfRenderWindow *window, s_game *t_game);
    void parallax_start2(s_game *t_game);
    void parallax_start(s_game *t_game);
    void parallax_start3(s_game *t_game);
    void parallax_start4(s_game *t_game);

    int events(sfRenderWindow *window, s_game *t_game, sfEvent *event);

    sfMusic *mus_menu_create(void);
    sfMusic *music_create_lvl1(void);
    sfMusic *music_create_game_over(void);
    sfMusic *sound_create_jump(void);
    sfMusic *sound_create_hit(void);

    void menu_is_open(sfRenderWindow *wdw, s_game *t_game, sfEvent *event);
    void menu_on_click(s_game *t_game, sfEvent *event, sfRenderWindow *window);
    void menu_events_1(s_game *t_game, sfEvent *event, sfRenderWindow *window);
    void menu_events_2(s_game *t_game, sfEvent *event, sfRenderWindow *window);
    void display_butt(sfRenderWindow *window, s_game *t_game);

    void display_scnes(s_game *t_game, sfRenderWindow *window, sfEvent *event);
    void display_obj(object_t *object, sfRenderWindow *window, s_game *t_game);

    void put_score(s_game *t_game, sfRenderWindow *window);
    void write_on_file(char *fname, char *str);
    int recup_score_on_file(void);
    void is_game_over(s_game *t_game, sfRenderWindow *window);

    void destroy_objects(object_t *objects);
    object_t *gest_objects(char const *filepath);
    void select_texture_and_pos(int type, object_t *object, int x, int y);

    void filter_lvl_2(s_game *t_game);
    void init_bird(s_game *t_game);
    void lvl_2_enm(s_game *t_game);
    void lvl2_animation(s_game *t_game);

#endif/* !MY_RUNNER_H */
