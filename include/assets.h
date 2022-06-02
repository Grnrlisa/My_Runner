/*
** EPITECH PROJECT, 2021
** sprite
** File description:
** strcut for sprite
*/
#ifndef ASSETS_H
    #define ASSETS_H

    #include <SFML/Graphics.h>
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

    typedef struct parallax {
        sfClock *clock_paral;
        sfTime time_paral;
        float sec_paral;
        sfVector2f pos_bck;
        sfVector2f pos_bat;
        sfVector2f pos_first;
        sfVector2f pos_bck2;
        sfVector2f pos_bat2;
        sfVector2f pos_fit2;
        sfTexture *bck_t;
        sfSprite *bck_s;
        sfSprite *filter;
        sfTexture *bat_t;
        sfSprite *bat_s;
        sfTexture *first_t;
        sfSprite *first_s;
        sfTexture *bck_t2;
        sfSprite *bck_s2;
        sfTexture *bat_t2;
        sfSprite *bat_s2;
        sfTexture *first_t2;
        sfSprite *first_s2;
    } paral_t;

    typedef struct sprite_bob {
        sfVector2f speed;
        sfVector2f pos_pop;
        sfIntRect rect;
        sfClock *clock_bob;
        sfTime time;
        float sec;
        sfSprite *sprite;
        sfTexture *txt;
        int reset;
        int jmp;
        int move_left;
        int status_jump;
    } s_bob_t;

    typedef struct sprite_menu {
        sfVector2f speed;
        sfVector2f pos1;
        sfVector2f pos2;
        sfVector2f pos12;
        sfVector2f pos22;
        sfSprite *sprite1;
        sfSprite *sprite2;
        sfSprite *sprite12;
        sfSprite *sprite22;
        sfTexture *txt1;
        sfTexture *txt2;
        int open;
    } menu_t;

    typedef struct sprite_game_over {
        sfClock *clock_bob_o;
        sfIntRect rect;
        int reset;
        sfVector2f pos_bob_o;
        sfVector2f pos_bck_o;
        sfVector2f pos_but_o;
        sfVector2f pos_txt_o;
        sfVector2f pos_scr_o;
        sfVector2f pos_scr_o2;
        sfVector2f pos_retry;
        sfFont *font_o;
        sfText *text_o;
        sfText *scr_o;
        sfText *scr_o2;
        sfText *r;
        sfTexture *bobtx;
        sfTexture *bcktx;
        sfSprite *spr_bob_o;
        sfSprite *spr_bck_o;
    } game_over_t;

    typedef struct buttons_rect {
        sfIntRect rect;
    } rect_t;

    typedef struct sprite_buttons {
        rect_t rc;
        sfVector2f pos_lvl1;
        sfVector2f pos_lvl2;
        sfVector2f pos_titl;
        sfVector2f pos_sett;

        sfSprite *spr_lvl1;
        sfSprite *spr_lvl2;
        sfSprite *spr_titl;
        sfSprite *spr_sett;

        sfTexture *tx_lvl1;
        sfTexture *tx_lvl2;
        sfTexture *tx_titl;
        sfTexture *tx_sett;
        sfTexture *tx_lvl1_b;
        sfTexture *tx_lvl2_b;
        sfTexture *tx_sett_b;
    } button_t;

    typedef struct sprite_health {
        sfVector2f pos_pop;
        sfVector2f m_pos;
        sfIntRect area;
        sfSprite *sprite;
        sfSprite *sprite2;
        sfTexture *txt1;
        sfTexture *txt2;
        int points;
        sfIntRect rect;
    } s_health_t;

    typedef struct score {
        float score;
        sfText *text_score;
        sfFont *font_score;
        sfVector2f pos_score;
        sfText *text;
        sfFont *font;
        sfVector2f pos_text;

        sfClock *clock_scr;
        sfTime time;
        float sec;
    } s_score_t;

    typedef struct sound_music {
        sfMusic *hit_sound;
        sfMusic *jump_sound;
        sfMusic *start_sound;
        sfMusic *menu_sound;
        sfMusic *over_sound;
        sfMusic *lvl2_sound;
    } s_mus_t;

    typedef struct object_s {
        sfVector2f speed;
        sfIntRect rect;
        sfClock *clock_obj;
        sfClock *clock_trl;
        sfTime timer;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        float sec;
        int reset;
        char const *file;
        int nb;
        int type;
        struct object_s *next;
    } object_t;

    typedef struct sprite_bird {
        sfVector2f speed;
        sfVector2f pos_pop;
        sfVector2f pos_pop2;
        sfVector2f m_pos;
        sfIntRect area;
        sfSprite *sprite;
        sfSprite *sprite2;
        sfTexture *txt;
        int reset;
        int nb;
        sfVector2i mouse_pos;
    } s_bird_t;

    typedef struct tot_game {
        s_bob_t bob;
        paral_t parallax;
        menu_t menu;
        game_over_t ovr;
        s_score_t scr;
        s_bird_t bird;
        button_t but;
        s_mus_t music;
        object_t obj;
        s_health_t lif;
        int scne;
        int restart;
        int check;
        char const *file;
        int status_hit;
        int is_game_win;
    } s_game;

#endif/* !ASSETS_H */
