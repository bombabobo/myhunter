/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** endscreen
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/struct.h"
#include "../include/init.h"
#include "../include/my.h"

static sfRenderWindow *ecrw(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile(LOGO);
    sfVector2u iconSize = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    window = sfRenderWindow_create((sfVideoMode){1000, 630, 32},
        "game_over", BSTYLE, 0);
    sfRenderWindow_setFramerateLimit(window, 24);
    sfRenderWindow_setPosition(window, (sfVector2i){460, 260});
    sfRenderWindow_setIcon(window, iconSize.x, iconSize.y, pixels);
    sfImage_destroy(icon);
    return window;
}

static void ekey_events(sfRenderWindow *window, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}

void emanage_mouse_click(sfRenderWindow *window, sfMusic *theme, sfMusic *lau)
{
    int x = MGPR_(window).x;
    int y = MGPR_(window).y;

    if (x > 70 && x < 390 && y > 330 && y < 580){
        sfRenderWindow_close(window);
        sfMusic_destroy(theme);
        sfMusic_destroy(lau);
        myhunter();
    }
}

static void eanalyse_events(sfRenderWindow *window, sfEvent *event,
    sfMusic *theme, sfMusic *laugh)
{
    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtMouseButtonPressed)
            emanage_mouse_click(window, theme, laugh);
        if (event->type == sfEvtKeyPressed)
            ekey_events(window, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void init_manage(sfMusic *theme, sfMusic *laught, sfSprite *background)
{
    sfMusic_play(theme);
    sfMusic_play(laught);
    sfMusic_setLoop(theme, sfTrue);
    sfSprite_setTexture(background, TX_(GOBG_, 0), sfFalse);
    sfSprite_setScale(background, (sfVector2f){0.63, 0.63});
}

void destroy_bg_window(sfSprite *background, sfRenderWindow *window)
{
    sfSprite_destroy(background);
    sfRenderWindow_destroy(window);
}

int gameover(int score)
{
    sfRenderWindow *window = ecrw(window);
    sfEvent event;
    sfSprite *background = sfSprite_create();
    sfMusic *laught = sfMusic_createFromFile(LDU);
    sfMusic *theme = sfMusic_createFromFile(DUCK);
    sfClock *clock = sfClock_create();

    init_manage(theme, laught, background);
    sfRenderWindow_drawSprite(window, background, 0);
    nb_display2(&(ic){score, sfWhite}, (sfVector2f){2, 1.5}, window,
        (sfVector2f){600, 540});
        sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)){
        eanalyse_events(window, &event, theme, laught);
    }
    destroy_bg_window(background, window);
}
