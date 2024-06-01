/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** myhunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/init.h"
#include "../include/my.h"

static void end(gstruct *gstruct, sfClock *duckclock, sfView *view,
    sfRenderWindow *window)
{
    sfMusic_destroy(gstruct->music.music);
    sfMusic_destroy(gstruct->music.wind);
    sfSound_destroy(gstruct->sound.death);
    sfSound_destroy(gstruct->sound.rel);
    sfSound_destroy(gstruct->sound.bonus);
    sfSound_destroy(gstruct->sound.bang);
    sfClock_destroy(duckclock);
    sfView_destroy(view);
    sfRenderWindow_destroy(window);
    for (int i = 0; i < SPNB_; i++)
        sfSprite_destroy(gstruct->sprites[i].sprite);
    gameover(gstruct->Score);
}

int myhunter(void)
{
    sfRenderWindow *window = create_render_window(window);
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, 970, 540});
    sfClock *duckclock = sfClock_create();
    sfEvent event;
    gstruct gstruct;

    game_struct_creator(&gstruct);
    sfView_setCenter(view, (sfVector2f){970, 540});
    while (sfRenderWindow_isOpen(window)){
        if (!(gstruct.pause)){
            sfRenderWindow_clear(window, sfBlack);
            sp_upd(&gstruct, window, 0, -1);
            anime_duck(&gstruct, duckclock);
            sp_upd_all(&gstruct, window, view);
        }
        analyse_events(window, &event, &gstruct);
        sfRenderWindow_display(window);
    }
    end(&gstruct, duckclock, view, window);
}
