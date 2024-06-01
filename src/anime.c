/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** anime
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

void mrec(sfIntRect *rect, int offset, int max_value)
{
    rect->left = ((rect->left < max_value - offset) ? rect->left + offset : 0);
}

void duck_flight(gstruct *gst, sfClock *duckclock)
{
    sfInt64 t = sfClock_getElapsedTime(duckclock).microseconds;

    if (t > 100000.0){
        mrec(&gst->sprites[2].rect, ((gst->sprites[2].killed) ? 0 : 110), 330);
        mrec(&gst->sprites[3].rect, ((gst->sprites[3].killed) ? 0 : 110), 330);
        mrec(&gst->sprites[4].rect, ((gst->sprites[4].killed) ? 0 : 110), 330);
        mrec(&gst->sprites[5].rect, ((gst->sprites[5].killed) ? 0 : 110), 330);
        sfClock_restart(duckclock);
    }
    if ((t % 66666) > 50000)
        mrec(&gst->sprites[4].rect, ((gst->sprites[4].killed) ? 0 : 110), 330);
    if ((t % 50000) > 33333)
        mrec(&gst->sprites[5].rect, ((gst->sprites[5].killed) ? 0 : 110), 330);
}

void duck_kill(gstruct *gstruct, int i)
{
    if (gstruct->sprites[i].killed / 10 == 1){
        gstruct->sprites[i].killed -= 1;
        gstruct->sprites[i].color = (sfColor){TRA_};
        return;
    }
    if (gstruct->sprites[i].killed / 10 > 1){
        gstruct->sprites[i].killed -= 1;
        mrec(&gstruct->sprites[i].rect, 110, 880);
        gstruct->sprites[i].color = (sfColor){RED_};
        return;
    }
}

void anime_duck(gstruct *gstruct, sfClock *duckclock)
{
    duck_flight(gstruct, duckclock);
    for (int i = 2; i < 6; i++){
        if (gstruct->sprites[i].killed > 0){
            duck_kill(gstruct, i);
        }
    }
}
