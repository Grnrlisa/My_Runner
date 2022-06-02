/*
** EPITECH PROJECT, 2021
** Mu Runner
** File description:
** sprite gest for character
*/

#include "assets.h"
#include "my_runner.h"

void obj_spr_animate(object_t *object)
{
    if (object->rect.top >= (100 * object->nb))
        object->reset = 1;
    if (object->rect.top <= 0)
        object->reset = 0;
    if (object->reset == 0)
        object->rect.top += 128;
    if (object->rect.top >= (100 * object->nb))
        object->rect.top = 0;
}

void obj_animation(object_t *object)
{
    sfVector2f offset;
    sfTime time = sfClock_getElapsedTime(object->clock_obj);
    float sec = time.microseconds / 1000000.0f;
    if (sec > 0.1) {
        obj_spr_animate(object);
        if (object->nb == 4) {
            offset.x = -5;
            offset.y = +7;
            sfSprite_move(object->sprite, offset);
        }
        if (object->pos.y <= 200 && object->nb == 4) {
            offset.x = -5;
            offset.y = -7;
            sfSprite_move(object->sprite, offset);
        }
        sfClock_restart(object->clock_obj);
    }
    sfSprite_setTextureRect(object->sprite, object->rect);
}
