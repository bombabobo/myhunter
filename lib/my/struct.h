/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#ifndef STRUCT_H_
    #define STRUCT_H_
    #define TX_ sfTexture_createFromFile
    #define SC_ sfSprite_create
    #define SGLB_ sfSprite_getLocalBounds
    #define MGPR_ sfMouse_getPositionRenderWindow
    #define MSPR_ sfMouse_setPositionRenderWindow
    #define SSTR_ sfSprite_setTextureRect
    #define VCFR sfView_createFromRect
    #define SBCFF sfSoundBuffer_createFromFile
    #define FR (sfFloatRect)
    #define SPNB_ 10
typedef struct sprite {
    int id;
    int type;
    char *name;
    sfSprite *sprite;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    sfIntRect rect;
    sfColor color;
    float rot;
    int killed;
}sprite;
typedef struct tripleint {
    int a;
    int b;
    int c;
}t;
typedef struct intandcolor {
    int nbr;
    sfColor color;
}ic;
typedef struct cursorstruct {
    sfVector2i currentchc;
    sfVector2i oldchc;
    sfVector2i chcdiff;
    int cooldown;
    int ammo;
    int b_ammo;
    int mags;
}weapon;
typedef struct sound_struct {
    sfSound *bang;
    sfSound *rel;
    sfSound *bonus;
    sfSound *death;
}s_struct;
typedef struct music_struct {
    sfMusic *music;
    sfMusic *wind;
}m_struct;
typedef struct gamestruct {
    sprite sprites[SPNB_];
    s_struct sound;
    m_struct music;
    weapon gun;
    int GameOver;
    int Score;
    int duckescape;
    sfBool pause;
    sfView *view;
}gstruct;

#endif /* !STRUCT_H_ */
