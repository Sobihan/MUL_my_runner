/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** main
*/

#include "my_runner.h"

void eventclose(sfEvent *event, runner_t *my_struct)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(my_struct->window);
    }
}

void set_music(void)
{
    sfSound *sound;
    sfSoundBuffer *soundbuffer;

    soundbuffer = sfSoundBuffer_createFromFile("outil/theme.ogg");
    sound = sfSound_create();
    sfSound_setBuffer(sound, soundbuffer);
    sfSound_play(sound);
    sfSound_setLoop(sound, sfTrue);
    sfSound_getLoop(sound);
}

void check_jump_win(runner_t *my_struct)
{
    if (my_struct->saut == 1) {
        if (my_struct->t.microseconds < 10000 && my_struct->pos.y >= 500)
            my_struct->pos.y =  my_struct->pos.y - 1;
        else
            my_struct->saut = 2;
    }
    if (my_struct->saut == 2) {
        sfClock_restart(my_struct->clock);
        my_struct->t = sfClock_getElapsedTime(my_struct->c);
        my_struct->saut = 3;
    }
    if (my_struct->saut == 3) {
        if (my_struct->t.microseconds < 10000 && my_struct->pos.y <= 750)
            my_struct->pos.y =  my_struct->pos.y + 1;
        else
            my_struct->saut = 0;                
        }
}
void game(void)
{
    runner_t my_struct;
    sfEvent event;

    set_my_struct(&my_struct);
    my_struct.window = sfRenderWindow_create(my_struct.video_mode, "my_hunter",
                                             def, NULL);
    set_music();
    while (sfRenderWindow_isOpen(my_struct.window)) {
        sfSprite_setPosition(my_struct.target, my_struct.pos);
        sfSprite_setPosition(my_struct.veg, my_struct.pos_veg);
        sfSprite_setPosition(my_struct.ground, my_struct.pos_ground1);
        sfSprite_setPosition(my_struct.ground1, my_struct.pos_ground2);
        sfSprite_setPosition(my_struct.cloud, my_struct.pos_cloud);
        sfRenderWindow_display(my_struct.window);
        display_game(&my_struct);
        sfText_setString(my_struct.text, my_putnbr(my_struct.score));
        sfText_setFont(my_struct.text, my_struct.font);
        sfText_setCharacterSize(my_struct.text, 50);
        sfRenderWindow_drawText(my_struct.window, my_struct.text, NULL);
        sfSprite_setTextureRect(my_struct.target, my_struct.rect);
        my_struct.rect = anim(&my_struct);
        check_jump_win(&my_struct);
        my_struct.score = my_struct.score + 1;
        while (sfRenderWindow_pollEvent(my_struct.window, &event)) {
            eventclose(&event, &my_struct);
            if (event.key.code == sfKeySpace && my_struct.saut == 0) {
                my_struct.saut = 1;
                my_struct.c = sfClock_create();
                my_struct.t = sfClock_getElapsedTime(my_struct.c);
            }
        }
    }
    destroy_all(&my_struct);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("Hello Gamer ! \n");
        my_putstr("Rules : To Jump : Space\n");
    } else if (ac == 2 || ac == 1)
        game();
    else {
        write(2, "Invalid Option\n", 15);
        return (84);
    }
    return (0);
}
