/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** event
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

void testkill(gstruct *gstruct)
{
    sfVector2f chpos;
    sfVector2f dpos;
    sfVector2f dori;

    for (int i = 2; i < 6; i++){
        chpos = sfSprite_getPosition(gstruct->sprites[1].sprite);
        dpos = sfSprite_getPosition(gstruct->sprites[i].sprite);
        dori = sfSprite_getOrigin(gstruct->sprites[i].sprite);
        if (chpos.x > dpos.x - dori.x && chpos.x < dpos.x + dori.x &&
            chpos.y > dpos.y - dori.y && chpos.y < dpos.y + dori.y) {
            gstruct->sprites[i].killed = 50;
            gstruct->gun.b_ammo += gstruct->sprites[i].type;
            sfSound_play(gstruct->sound.death);
            gstruct->Score += (int)(DUCKSCORE * (float)(1 + DIFF * 0.5));
            gstruct->duckescape = 0;
        }
    }
}

void manage_mouse_click(sfRenderWindow *window, gstruct *gst)
{
    gst->sound.bang = sfSound_create();
    sfSound_setPitch(gst->sound.bang, SHOTPITCH);
    sfSound_setBuffer(gst->sound.bang, SBCFF(SHOT1_));
    if (gst->gun.ammo > 0){
        gst->gun.ammo -= 1;
        gst->gun.cooldown = 15;
        sfSound_play(gst->sound.bang);
        gst->sprites[1].scale.x += BF_;
        gst->sprites[1].scale.y += BF_;
        testkill(gst);
    } else if (gst->gun.ammo <= 0 && gst->gun.mags >= 1) {
        gst->gun.mags -= 1;
        gst->gun.cooldown = 120;
        gst->gun.ammo = ROUND_;
        sfSound_play(gst->sound.rel);
    } else
        gst->GameOver = 1;
}

void key_events(sfRenderWindow *window, sfEvent *event, gstruct *gstruct)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        exit(0);
    if (sfKeyboard_isKeyPressed(sfKeySpace)){
        gstruct->pause = ((gstruct->pause) ? sfFalse : sfTrue);
        MSPR_((sfVector2i){(int)gstruct->sprites[1].pos.x - 10,
        (int)gstruct->sprites[1].pos.y - 170}, window);
        togglemousecapture(window, gstruct->pause);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) && gstruct->gun.mags > 0 &&
        gstruct->gun.cooldown == 0 && !gstruct->pause &&
        gstruct->gun.ammo < 20){
        gstruct->gun.mags -= 1;
        gstruct->gun.cooldown = 120;
        gstruct->gun.ammo = ROUND_;
        sfSound_play(gstruct->sound.rel);
    }
}

static void sound_play(gstruct *gstruct)
{
    if (sfSound_getStatus(gstruct->sound.rel) == sfPaused)
        sfSound_play(gstruct->sound.rel);
    if (sfSound_getStatus(gstruct->sound.death) == sfPaused)
        sfSound_play(gstruct->sound.death);
    if (sfSound_getStatus(gstruct->sound.bang) == sfPaused)
        sfSound_play(gstruct->sound.bang);
    if (sfSound_getStatus(gstruct->sound.bonus) == sfPaused)
        sfSound_play(gstruct->sound.bonus);
    if (sfMusic_getStatus(gstruct->music.wind) == sfPaused)
        sfMusic_play(gstruct->music.wind);
}

static void sound_pause(gstruct *gstruct)
{
    sfSound_pause(gstruct->sound.rel);
    sfSound_pause(gstruct->sound.death);
    sfSound_pause(gstruct->sound.bang);
    sfSound_pause(gstruct->sound.bonus);
    sfMusic_pause(gstruct->music.wind);
}

void gameover_event(gstruct *gstruct, sfRenderWindow *window)
{
    if (gstruct->GameOver == 1){
        my_printf("Score : %d\n", gstruct->Score);
        sfRenderWindow_close(window);
    }
    if (gstruct->duckescape >= 5){
        my_printf("Score : %d\n", gstruct->Score);
        sfRenderWindow_close(window);
    }
    if (gstruct->pause)
        sound_pause(gstruct);
    else
        sound_play(gstruct);
}

void analyse_events(sfRenderWindow *window, sfEvent *event, gstruct *gstruct)
{
    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtMouseButtonPressed &&
            gstruct->gun.cooldown == 0 && !gstruct->pause)
            manage_mouse_click(window, gstruct);
        if (event->type == sfEvtKeyPressed)
            key_events(window, event, gstruct);
        if (event->type == sfEvtClosed)
            gstruct->GameOver = 1;
    }
    gameover_event(gstruct, window);
}
