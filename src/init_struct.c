/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** init_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

sfIntRect initialize_rect_char(int width, int height)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return (rect);
}

game_obj_t *create_object(const char *path, sfVector2f pos, float speed,
                                                        sfVector2f scale)
{
    game_obj_t *object = malloc(sizeof(game_obj_t) * 1);

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    object->speed = speed;
    object->pos = pos;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, scale);
    return (object);
}

game_obj_t **init_struct_two(window_t *wind, game_obj_t **objects,
                                                    options_t *game)
{
    objects[8] = create_object("files/3_trees.png", (sfVector2f){0, 0},
                                                            3, wind->scale);
    objects[9] = create_object("files/2_trees.png", (sfVector2f){0, 0},
                                                            4, wind->scale);
    objects[10] = create_object("files/1_ground.png", (sfVector2f){0, 0},
                                                            4, wind->scale);
    objects[11] = create_object("files/ac_perso.png",
                (sfVector2f){180, (480 * wind->scale.y)}, 0, wind->scale);
    objects[11]->rect = initialize_rect_char(46, 58);
    objects[12] = create_object("files/ac_jump.png",
                (sfVector2f){186, (480 * wind->scale.y)}, 0, wind->scale);
    objects[12]->rect = initialize_rect_char(40, 60);
    objects = fill_objects(wind, objects, game->map);
    return (objects);
}

game_obj_t **init_struct(window_t *wind, options_t *game)
{
    int mlc_size = 13 + game->map->enemies;
    game_obj_t **objects = malloc(sizeof(game_obj_t *) * (mlc_size));

    objects[0] = create_object("files/11_back.png", (sfVector2f){0, 0},
                                                            0, wind->scale);
    objects[1] = create_object("files/10_clouds.png", (sfVector2f){0, 0},
                                                            0.3, wind->scale);
    objects[2] = create_object("files/9_clouds.png", (sfVector2f){0, 0},
                                                            0.6, wind->scale);
    objects[3] = create_object("files/8_clouds.png", (sfVector2f){0, 0},
                                                            1, wind->scale);
    objects[4] = create_object("files/7_clouds.png", (sfVector2f){0, 0},
                                                            1.5, wind->scale);
    objects[5] = create_object("files/6_hill2.png", (sfVector2f){0, 0},
                                                            2, wind->scale);
    objects[6] = create_object("files/5_hill1.png", (sfVector2f){0, 0},
                                                            2.5, wind->scale);
    objects[7] = create_object("files/4_bushes.png", (sfVector2f){0, 0},
                                                            3, wind->scale);
    return (init_struct_two(wind, objects, game));
}