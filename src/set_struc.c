/*
** EPITECH PROJECT, 2018
** set_struc.c
** File description:
** set
*/

#include "my_runner.h"

void *set_sprite(char const *pathfile)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

void set_my_struct(runner_t *my_struct)
{
    my_struct->video_mode.width = 1920;
    my_struct->video_mode.height = 1080;
    my_struct->video_mode.bitsPerPixel = 32;
    my_struct->background = set_sprite("outil/background.png");
    my_struct->target = set_sprite("outil/sprite2.PNG");
    my_struct->rect.top = 0;
    my_struct->rect.left= 0;
    my_struct->rect.width = 110;
    my_struct->rect.height = 110;
    my_struct->pos.x = 00.0;
    my_struct->pos.y = 750;
    my_struct->pos_ground1.x = 0;
    my_struct->pos_ground1.y = 0;
    my_struct->clock = sfClock_create();
    my_struct->ground = set_sprite("outil/sprite.png");
    my_struct->ground1 = set_sprite("outil/sprite.png");
    my_struct->veg = set_sprite("outil/vegetation.png");
    my_struct->cloud = set_sprite("outil/cloud.png");
    my_struct->pos_veg.x = 1920;
    my_struct->pos_veg.y = 500;
    my_struct->pos_cloud.x = 1920;
    my_struct->pos_cloud.y = 0;
    my_struct->pos_ground2.x = 1920;
    my_struct->pos_ground2.y = 0;
    my_struct->saut = 0;
    my_struct->font = sfFont_createFromFile("arial.ttf");
    my_struct->text = sfText_create();
    my_struct->score = 0;
}
