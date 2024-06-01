/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** update
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

void togglemousecapture(sfRenderWindow *window, sfBool captureMouse)
{
    sfRenderWindow_setMouseCursorGrabbed(window, !captureMouse);
    sfRenderWindow_setMouseCursorVisible(window, captureMouse);
}

void sp_set_all(sprite *sprite, int type)
{
    if (sprite->type >= type){
        sfSprite_setPosition(sprite->sprite, sprite->pos);
        sfSprite_setScale(sprite->sprite, sprite->scale);
        sfSprite_setOrigin(sprite->sprite, sprite->origin);
        sfSprite_setRotation(sprite->sprite, sprite->rot);
        sfSprite_setTexture(sprite->sprite, sprite->tex, sfFalse);
        sfSprite_setColor(sprite->sprite, sprite->color);
        SSTR_(sprite->sprite, sprite->rect);
    }
}

void sp_upd(gstruct *gstruct, sfRenderWindow *window, int i, int type)
{
    sp_set_all(&gstruct->sprites[i], type);
    sp_calcul(&gstruct->sprites[i], window, gstruct);
    sfRenderWindow_drawSprite(window, gstruct->sprites[i].sprite, 0);
}

void extra_update(gstruct *gst, sfRenderWindow *window)
{
    gst->gun.cooldown = imax(0, gst->gun.cooldown - 1);
    if (gst->gun.b_ammo >= 20){
        gst->gun.mags++;
        gst->gun.b_ammo -= 20;
        sfSound_play(gst->sound.bonus);
    }
    nb_display(gst->gun.ammo, &gst->sprites[6].rect, &gst->sprites[7].rect);
    nb_display(gst->gun.mags, &gst->sprites[8].rect, &gst->sprites[8].rect);
    nb_display2(&(ic){gst->Score, sfWhite}, (sfVector2f){1.5, 1.5}, window,
    (sfVector2f){gst->sprites[1].pos.x - 480, gst->sprites[1].pos.y - 250});
}

void sp_upd_all(gstruct *gst, sfRenderWindow *window, sfView *view)
{
    view = sfView_createFromRect((sfFloatRect){X_, Y_, 970, 540});
    sfRenderWindow_setView(window, view);
    for (int i = 2; i < SPNB_; i++) {
        if (gst->sprites[i].type == 0 || gst->sprites[i].type >= 9)
            continue;
        sp_upd(gst, window, i, 0);
    }
    sp_upd(gst, window, 1, 0);
    for (int i = 6; i <= 9; i++)
        sp_upd(gst, window, i, 0);
    extra_update(gst, window);
}
