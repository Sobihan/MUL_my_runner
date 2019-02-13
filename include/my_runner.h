/*
** EPITECH PROJECT, 2018
** my_runner.h
** File description:
** structure
*/

#ifndef HUNTER_H
#define HUNTER_H

#include  <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define def sfDefaultStyle

typedef struct runner_s
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *background;
    sfSprite *ground;
    sfSprite *ground1;
    sfSprite *veg;
    sfSprite *target;
    sfSprite *cloud;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f pos_ground1;
    sfVector2f pos_ground2;
    sfVector2f pos_veg;
    sfVector2f pos_cloud;
    sfClock *clock;
    sfTime time;
    float seconde;
    int score;
    int saut;
    sfClock *c;
    sfTime t;
    sfText *text;
    sfFont *font;
} runner_t;

int touch_sprite(sfEvent *event, runner_t *my_struct);
sfIntRect anim(runner_t *my_struct);
void destroy_all(runner_t *my_struct);
void display_game(runner_t *my_struct);
void set_my_struct(runner_t *my_struct);
void *set_sprite(char const *pathfile);
void my_putstr(char *str);
void jump(runner_t *my_struct);
void jump(runner_t *my_struct);
char *my_putnbr(int nb);
#endif
