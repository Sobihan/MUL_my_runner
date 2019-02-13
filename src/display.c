/*
** EPITECH PROJECT, 2018
** my_runner.c
** File description:
** game
*/

#include "my_runner.h"

void display_game(runner_t *my_struct)
{
    my_struct->pos_ground1.x = my_struct->pos_ground1.x - 0.5;
    my_struct->pos_ground2.x = my_struct->pos_ground2.x - 0.5;
    my_struct->pos_cloud.x = my_struct->pos_cloud.x - 0.5;
    my_struct->pos_veg.x = my_struct->pos_veg.x - 0.75;
    if (my_struct->pos_ground1.x == 0) {
        my_struct->pos_ground2.x = 1920;
    }
    else if (my_struct->pos_ground2.x == 0)
        my_struct->pos_ground1.x = 1920;
    if (my_struct->pos_veg.x == -750)
        my_struct->pos_veg.x = 1930;
    if (my_struct->pos_cloud.x == -530)
        my_struct->pos_cloud.x = 1930;
    sfRenderWindow_drawSprite(my_struct->window, my_struct->background, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->veg, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->ground, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->ground1, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->target, NULL);
    sfRenderWindow_drawSprite(my_struct->window, my_struct->cloud, NULL);
}

void destroy_all(runner_t *my_struct)
{
    sfSprite_destroy(my_struct->background);
    sfSprite_destroy(my_struct->target);
    sfClock_destroy(my_struct->clock);
    sfRenderWindow_destroy(my_struct->window);
}

sfIntRect anim(runner_t *my_struct)
{
    my_struct-> time = sfClock_getElapsedTime(my_struct->clock);
    if (my_struct->time.microseconds < 150000)
        my_struct->rect.left = 0;
    if (my_struct->time.microseconds > 150000 &&
        my_struct->time.microseconds < 300000)
        my_struct->rect.left = 110;
    if (my_struct-> time.microseconds > 300000 &&
        my_struct-> time.microseconds < 450000)
        my_struct->rect.left = 220;
    if (my_struct->time.microseconds > 500000)
        sfClock_restart(my_struct->clock);
    return (my_struct->rect);
}