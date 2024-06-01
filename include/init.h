/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include "struct.h"
#ifndef INIT_H_
    #define INIT_H_
    #define CH_ "ressources/jpg/crosshair"
    #define BG_ "ressources/jpg/background"
    #define GBG_ "ressources/jpg/Dbackground.jpg"
    #define LBG_ "ressources/jpg/launcher_BG.jpg"
    #define GOBG_ "ressources/jpg/gameover_BG.jpg"
    #define LOGO "ressources/jpg/logo.jpg"
    #define C1_ "ressources/png/sniper2.png"
    #define C2_ "ressources/png/sniper.png"
    #define D1_ "ressources/png/duckB.png"
    #define D2_ "ressources/png/duckR.png"
    #define D3_ "ressources/png/duckN.png"
    #define BONUS_ "ressources/png/bonus.png"
    #define NB_ "ressources/png/numbers.png"
    #define SHOT1_ "ressources/sounds/semi-auto_shot.ogg"
    #define SHOT2_ "ressources/sounds/lolisnipersound.ogg"
    #define SHOT3_ "ressources/sounds/funsnipersound.ogg"
    #define SHOT4_ "ressources/sounds/Vine-Gun-Shot.ogg"
    #define REL1_ "ressources/sounds/semi-auto_reload.ogg"
    #define REL2_ "ressources/sounds/reload.ogg"
    #define BNS_ "ressources/sounds/bonus.ogg"
    #define DUCKD_ "ressources/sounds/duckdeath.ogg"
    #define FUNDUCKD_ "ressources/sounds/funduckdeath.ogg"
    #define LTHEME "ressources/sounds/Lmusic.ogg"
    #define MUSIC "ressources/sounds/music.ogg"
    #define WIND "ressources/sounds/wind.ogg"
    #define PLAY "ressources/sounds/play.ogg"
    #define LDU "ressources/sounds/Lduck.ogg"
    #define DUCK "ressources/sounds/ducks.ogg"
    #define BLACK_ 0, 0, 0, 255
    #define WHITE_  255, 255, 255, 255
    #define RED_ 255, 0, 0, 255
    #define GRN_ 0, 255, 0, 255
    #define BLU_ 0, 0, 255, 255
    #define YEL_ 255, 255, 0, 255
    #define MGT_ 255, 0, 255, 255
    #define CYA_ 0, 255, 255, 255
    #define TRA_ 0, 0, 0, 0
    #define SHOTPITCH 0.75
    #define RELOADPITCH 0.75
    #define ROUND_ 20
    #define MAG_ 2
    #define V_MODE 1920, 1080, 32
    #define TITLE "my_hunter"
    #define BSTYLE sfClose | sfResize
    #define FSTYLE sfClose | sfResize | sfFullscreen
    #define BN1_ (ROUND_ / 10) * 20
    #define BN2_ (ROUND_ % 10) * 20
    #define BN3_ (MAG_ % 10) * 20
    #define DUCK1KILLED (gstruct->sprites[2].killed == 0)
    #define X_ imax(0, imin(1920, MGPR_(window).x)) - 470
    #define Y_ imax(0, imin(1080, MGPR_(window).y)) - 90
    #define DUCKT gstruct->sprites[i].type
    #define DUCKSCORE 100 * DUCKT * DUCKT

    #define DIFF (float)gstruct->Score / 10000
    #define CS_ 0.82
    #define BF_ 0.41
    #define CMS_ 0.1
typedef struct initizerstruct {
    int id;
    int type;
    char *name;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    sfIntRect rect;
    sfColor color;
    float rot;
    char *image;
}init;

static init vectabs[SPNB_] = {
    {-1, -1, BG_, {500, 500}, {1, 1}, {975, 600},
        {0, 0, 2944, 1630}, {WHITE_}, 0.0, GBG_},
    {0, 0, CH_, {0, 0}, {CS_, CS_}, {400, 715},
        {0, 0, 1089, 980}, {WHITE_}, 0.0, C2_},
    {1, 1, "bduck1", {-2250, 700}, {1.5, 1.5}, {400, 715},
        {0, 0, 110, 110}, {WHITE_}, 0.0, D1_},
    {2, 1, "bduck1", {-3500, 800}, {1.6, 1.6}, {400, 715},
        {0, 0, 110, 110}, {WHITE_}, 0.0, D1_},
    {3, 2, "rduck1", {-8700, 300}, {1.0, 1.0}, {400, 715},
        {0, 0, 110, 110}, {WHITE_}, 0.0, D2_},
    {4, 3, "Bduck1", {-17200, 500}, {1.3, 1.3}, {400, 715},
        {0, 0, 110, 110}, {WHITE_}, 0.0, D3_},
    {5, 9, "n1", {0, 0}, {2, 2}, {0, 0}, {BN1_, 0, 20, 30}, {GRN_}, 0.0, NB_},
    {6, 9, "n2", {0, 0}, {2, 2}, {0, 0}, {BN2_, 0, 20, 30}, {GRN_}, 0.0, NB_},
    {7, 9, "n3", {0, 0}, {2, 2}, {0, 0}, {BN3_, 0, 20, 30}, {RED_}, 0.0, NB_},
    {8, 10, "bonus", {0, 0}, {0.5, 0.5}, {0, 0},
        {0, 0, 280, 400}, {WHITE_}, 0.0, BONUS_},
};

#endif /* !INIT_H_ */
