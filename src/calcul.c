/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** calcul
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

void cursor_calc(sprite *sprite, sfRenderWindow *window, gstruct *gstruct)
{
    sprite->scale.x = ((sprite->scale.x > CS_) ? sprite->scale.x - CMS_ : CS_);
    sprite->scale.y = ((sprite->scale.y > CS_) ? sprite->scale.y - CMS_ : CS_);
    sprite->origin.x = SGLB_(sprite->sprite).width / 2;
    sprite->origin.y = SGLB_(sprite->sprite).height / 2;
    sprite->pos.x = X_ + sfRenderWindow_getSize(window).x / 4;
    sprite->pos.y = Y_ + sfRenderWindow_getSize(window).y / 4;
}

void number_calc(sprite *sprite, sfRenderWindow *window, gstruct *gstruct)
{
    sprite->pos.x = gstruct->sprites[1].pos.x - 40;
    sprite->pos.y = gstruct->sprites[1].pos.y + 200;
    if (sprite->id == 6)
        sprite->pos.x += 40;
    if (sprite->id == 7)
        sprite->pos.x -= 200;
}

void duck_calc(sprite *sp, float vel, int dmax, gstruct *gstruct)
{
    sp->origin.x = SGLB_(sp->sprite).width / 2;
    sp->origin.y = SGLB_(sp->sprite).height / 2;
    if (sp->pos.x >= 3000 && !(sp->killed > 0)){
        gstruct->gun.b_ammo -= ((sp->type == 1) ? 3 : 0);
        gstruct->gun.b_ammo -= ((sp->type == 2) ? 2 : 0);
        gstruct->gun.b_ammo -= ((sp->type == 3) ? 1 : 0);
        gstruct->gun.b_ammo = imax(0, gstruct->gun.b_ammo);
        gstruct->duckescape += 1;
    }
    sp->pos.y = ((sp->pos.x > 3000 - vel) ? (rand() % 950) + 160 : sp->pos.y);
    sp->pos.x = ((sp->pos.x < 3000) ? sp->pos.x + vel : -dmax);
    sp->killed = ((sp->pos.x == -dmax) ? 0 : sp->killed);
    sp->color = ((sp->pos.x == -dmax) ? (sfColor){WHITE_} : sp->color);
    sp->scale.x = (sp->pos.y + 875) / 900;
    sp->scale.y = sp->scale.x;
}

void bonus_calc(sprite *sprite, gstruct *gstruct)
{
    sprite->origin.x = SGLB_(sprite->sprite).width / 2;
    sprite->origin.y = SGLB_(sprite->sprite).height / 2;
    sprite->pos.x = gstruct->sprites[1].pos.x + 280;
    sprite->pos.y = gstruct->sprites[1].pos.y;
    sprite->rect.left = gstruct->gun.b_ammo / 2 * 280;
}

void sp_calcul(sprite *sprite, sfRenderWindow *window, gstruct *gstruct)
{
    if (sprite->type == 0)
        cursor_calc(sprite, window, gstruct);
    if (sprite->type == 9)
        number_calc(sprite, window, gstruct);
    if (sprite->type == 1)
        duck_calc(sprite, 10 + DIFF, (rand() % 500) + 2500, gstruct);
    if (sprite->type == 2)
        duck_calc(sprite, 15 + DIFF, (rand() % 2500) + 3000, gstruct);
    if (sprite->type == 3)
        duck_calc(sprite, 17 + DIFF, (rand() % 5500) + 9750, gstruct);
    if (sprite->type == 10)
        bonus_calc(sprite, gstruct);
}
