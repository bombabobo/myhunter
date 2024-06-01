/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** gstruct_creator
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

sfRenderWindow *create_render_window(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile(LOGO);
    sfVector2u iconSize = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    window = sfRenderWindow_create((sfVideoMode){V_MODE}, TITLE, FSTYLE, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, iconSize.x, iconSize.y, pixels);
    togglemousecapture(window, sfFalse);
    sfImage_destroy(icon);
    return window;
}

sprite spmk(sprite sprite, init base, sfTexture *texture
    , sfSprite *my_sprite)
{
    sprite.id = base.id;
    sprite.type = base.type;
    sprite.name = base.name;
    sprite.sprite = my_sprite;
    sprite.tex = texture;
    sprite.pos = base.pos;
    sprite.scale = base.scale;
    sprite.origin = base.origin;
    sprite.rect = base.rect;
    sprite.color = base.color;
    sprite.rot = base.rot;
    sprite.killed = 0;
    return sprite;
}

static void gunsound_maker(gstruct *gstruct)
{
    sfMusic_setLoop(gstruct->music.music, sfTrue);
    sfMusic_setLoop(gstruct->music.wind, sfTrue);
    sfSound_setPitch(gstruct->sound.bang, SHOTPITCH);
    sfSound_setPitch(gstruct->sound.rel, RELOADPITCH);
    sfSound_setBuffer(gstruct->sound.bang, SBCFF(SHOT1_));
    sfSound_setBuffer(gstruct->sound.rel, SBCFF(REL1_));
    sfSound_setBuffer(gstruct->sound.bonus, SBCFF(BNS_));
    sfSound_setBuffer(gstruct->sound.death, SBCFF(DUCKD_));
    sfMusic_setVolume(gstruct->music.music, 75);
    sfSound_play(gstruct->sound.rel);
    sfMusic_play(gstruct->music.music);
    sfMusic_play(gstruct->music.wind);
}

void game_struct_creator(gstruct *gstruct)
{
    for (int i = 0; i < SPNB_; i++) {
        gstruct->sprites[i] = spmk(gstruct->sprites[i],
        vectabs[i], TX_(vectabs[i].image, 0), SC_());
    }
    gstruct->gun = (weapon){{1472, 1124}, {1472, 1124}, {0, 0}};
    gstruct->gun.cooldown = 120;
    gstruct->sound.bang = sfSound_create();
    gstruct->sound.rel = sfSound_create();
    gstruct->sound.bonus = sfSound_create();
    gstruct->sound.death = sfSound_create();
    gstruct->music.music = sfMusic_createFromFile(MUSIC);
    gstruct->music.wind = sfMusic_createFromFile(WIND);
    gstruct->Score = 0;
    gstruct->pause = sfFalse;
    gstruct->gun.ammo = ROUND_;
    gstruct->gun.mags = MAG_;
    gstruct->duckescape = 0;
    gstruct->GameOver = 0;
    gunsound_maker(gstruct);
}
