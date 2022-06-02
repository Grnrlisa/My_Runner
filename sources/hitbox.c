/*
** EPITECH PROJECT, 2021
** Mu Runner
** File description:
** sprite gest for character
*/

#include "assets.h"
#include "my_runner.h"

int is_colliding(sfSprite *bob, sfSprite *obj, s_game *t_game)
{
    sfFloatRect bob_rect = sfSprite_getGlobalBounds(bob);
    sfFloatRect obj_rect = sfSprite_getGlobalBounds(obj);
    sfFloatRect lvl2_rect = sfSprite_getGlobalBounds(t_game->bird.sprite);
    sfVector2f pos_bob = sfSprite_getPosition(bob);
    sfVector2f pos_obj = sfSprite_getPosition(obj);
    sfVector2f pos_lvl2 = sfSprite_getPosition(t_game->bird.sprite);

    if (sfFloatRect_intersects(&bob_rect, &obj_rect, NULL) == sfTrue) {
        if (pos_bob.x + 80 >= pos_obj.x + 25 && pos_bob.x <= pos_obj.x)
            return (1);
        }
    if (sfFloatRect_intersects(&bob_rect, &lvl2_rect, NULL) == sfTrue) {
        if (pos_bob.x + 80 >= pos_lvl2.x + 25 && pos_bob.x <= pos_lvl2.x)
            return (1);
    }
    return (0);
}

void bob_is_suffering(s_game *t_game)
{
    int status_hit = 1;

    if (status_hit == 1) {
        t_game->bob.rect.left = 280;
        if (t_game->lif.points > 30 && t_game->lif.points < 20) {
            status_hit = 0;
        }
    }
    if (t_game->bob.rect.top >= 320)
            t_game->bob.rect.top = 0;
    if (status_hit == 0) {
        t_game->bob.rect.left = 0;
    }
    sfSprite_setTextureRect(t_game->bob.sprite, t_game->bob.rect);
}

int check_collisions(object_t *object, s_game *t_game)
{
    int collision = 0;

    while (object != NULL && t_game->lif.points >= 0) {
        collision = is_colliding(t_game->bob.sprite, object->sprite, t_game);
        if (collision == 1 && t_game->is_game_win != 1) {
            sfMusic_play(t_game->music.hit_sound);
            t_game->lif.points -= 1;
            bob_is_suffering(t_game);
            texture_lifz(t_game);
        }
        if (collision == 1 && object->type == 3) {
                t_game->scne = 3;
                t_game->is_game_win = 1;
        }
        object = object->next;
    }
    return (0);
}
