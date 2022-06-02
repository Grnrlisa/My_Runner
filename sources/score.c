/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** test
*/

#include "assets.h"
#include "my_runner.h"

void write_on_file(char *fname, char *str)
{
    int fd = open(fname, O_WRONLY | O_TRUNC);

    write(fd, str, my_strlen(str));
    fd = close(fd);
}

int recup_score_on_file(void)
{
    const char *filename = "sources/score";
    char *recup;

    FILE* input_file = fopen(filename, "r");

    char *contents = NULL;
    size_t len = 0;
    while (getline(&contents, &len, input_file) != -1)
        recup = contents;

    fclose(input_file);
    return (my_atoi(recup));
}

void clock_score(s_game *t_game)
{
    t_game->scr.time = sfClock_getElapsedTime(t_game->scr.clock_scr);
    t_game->scr.sec = t_game->parallax.time_paral.microseconds / 1000000.0f;
}

void put_score(s_game *t_game, sfRenderWindow *window)
{
    clock_score(t_game);
    if (t_game->scr.sec > 1) {
        t_game->scr.score += 0.1;
    }
    sfText_setString(t_game->scr.text_score, my_itoa(t_game->scr.score));
    sfRenderWindow_drawText(window, t_game->scr.text_score, NULL);
}

void init_score(s_game *t_game)
{
    t_game->scr.score = 0;
    t_game->scr.font_score = sfFont_createFromFile("sprites/drab.otf");
    t_game->scr.text_score = sfText_create();
    sfText_setFont(t_game->scr.text_score, t_game->scr.font_score);
    sfText_setColor(t_game->scr.text_score, sfMagenta);
    t_game->scr.pos_text.x = 600;
    t_game->scr.pos_text.y = 600;
    t_game->scr.pos_score.x = 870;
    t_game->scr.pos_score.y = 0;
    t_game->scr.clock_scr = sfClock_create();
    sfText_setCharacterSize(t_game->scr.text_score, 25);
    sfText_setPosition(t_game->scr.text_score, t_game->scr.pos_score);
}
