/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** main
*/

#include "assets.h"
#include "my_runner.h"

object_t *textandpos_2(int type, object_t *object, int x, int y)
{
    sfVector2f scale;

    if (type == 3) {
        object->texture = sfTexture_createFromFile("sprites/tinabg.png", NULL);
        object->pos.x = x * 200;
        object->pos.y = y + 600;
        object->rect.left = 5;
        object->nb = 5;
        object->rect.top = 0;
        object->rect.height = 120;
        object->rect.width = 120;
        scale.x = 1.2;
        scale.y = 1.2;
        sfSprite_setScale(object->sprite, scale);
    }
    sfSprite_setTextureRect(object->sprite, object->rect);
    return (object);
}

object_t *textandpos(int type, object_t *object, int x, int y)
{
    if (type == 1) {
        object->texture = sfTexture_createFromFile("sprites/shtbig.png", NULL);
        object->pos.x = x * 220;
        object->pos.y = y + 300;
        object->rect.left = 5;
        object->rect.top = 0;
        object->rect.height = 110;
        object->rect.width = 120;
        object->nb = 4;
    } else if (type == 0) {
        object->texture = sfTexture_createFromFile("sprites/copbig.png", NULL);
        object->pos.x = x * 200;
        object->pos.y = y + 620;
        object->rect.left = 5;
        object->nb = 12;
        object->rect.height = 120;
        object->rect.width = 120;
    } textandpos_2(type, object, x, y);
    sfSprite_setTextureRect(object->sprite, object->rect);
    return (object);
}

int create_object(object_t **object_num, int y, int x, char type)
{
    object_t *new_object = malloc(sizeof(object_t));

    if (new_object == NULL)
        return (84);

    new_object->clock_obj = sfClock_create();
    new_object->sprite = sfSprite_create();
    new_object->type = type - '0';
    new_object = textandpos(type - '0', new_object, x, y);
    sfSprite_setTexture(new_object->sprite, new_object->texture, sfFalse);
    sfSprite_setPosition(new_object->sprite, new_object->pos);
    new_object->next = *object_num;
    *object_num = new_object;

    return (0);
}

int add_obj(object_t **object_num, int y, FILE *fd)
{
    int x = 0;
    char *buffer = NULL;
    size_t size = 0;
    int len = 0;

    if (fd == NULL)
        return (84);
    len = getline(&buffer, &size, fd);
    buffer[len - 1] = '\0';
    while (buffer[x] != '\0') {
        if (buffer[x] == '0' || buffer[x] == '1' || buffer[x] == '3')
            create_object(object_num, y, x, buffer[x]);
        x++;
    }
    free(buffer);
    return (0);
}

object_t *gest_objects(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    object_t *objects = NULL;

    for (int y = 0; y < 1; y++)
        add_obj(&objects, y, fd);
    fclose(fd);
    return (objects);
}
