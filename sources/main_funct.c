/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** main
*/

#include "assets.h"
#include "my_runner.h"

void display_arg(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("\n---------------------------- CYBERUNNER 1990");
        my_putstr(" --------------------------------\n\nCYBERUNNER 1990 is a");
        my_putstr(" running game. You play Bob, a pretty cool guy, and hav");
        my_putstr("e\nto run away to find your sidekick Tina, without get");
        my_putstr("ting caught by the cops.\n");
        my_putstr("Play with [SPACE] to jump over cops or turrels and use [");
        my_putstr("ESCAPE] to go back to\nmain menu whenever you want. LEVEL");
        my_putstr("S :\n\n      LEVEL 1 is a basic runner. The map is passe");
        my_putstr("d in parameters so you can\n      make your own.\n");
        my_putstr("      LEVEL 2 is an endless bonus level. (more or less");
        my_putstr(" functionnal)\n\n----------------------------------------");
        my_putstr("--------------------------------------\n\n");
    }
}

int main(int argc, char **argv)
{
    sfRenderWindow *window;
    s_game t_game;
    s_mus_t s_music;
    sfEvent event;
    t_game.restart = 0;
    sfVideoMode mode = {928, 793, 32};
    window = sfRenderWindow_create(mode, "MyRunner", sfResize | sfClose, NULL);
    t_game.check == rerun_game(&t_game, &s_music, window, &event);
    if (argc != 2)
        return (84);
    if (argc == 2) {
        display_arg(argv);
        if (t_game.check == 1) {
            t_game.file = argv[1];
            init_runner(&t_game, window, &event, &s_music);
        }
    }
    sfRenderWindow_destroy(window);
    return (0);
}
