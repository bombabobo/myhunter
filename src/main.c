/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
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

void destroy_all(sfRenderWindow *window, sfMusic *theme)
{
    sfMusic_destroy(theme);
    sfRenderWindow_destroy(window);
}

static sfRenderWindow *crlw(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile(LOGO);
    sfVector2u iconSize = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);

    window = sfRenderWindow_create((sfVideoMode){1000, 630, 32},
        "launcher", BSTYLE, 0);
    sfRenderWindow_setFramerateLimit(window, 24);
    sfRenderWindow_setPosition(window, (sfVector2i){460, 260});
    sfRenderWindow_setIcon(window, iconSize.x, iconSize.y, pixels);
    sfImage_destroy(icon);
    return window;
}

static void lkey_events(sfRenderWindow *window, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}

void lmanage_mouse_click(sfRenderWindow *window, sfMusic *theme)
{
    sfMusic *play = sfMusic_createFromFile(PLAY);
    sfClock *duckclock = sfClock_create();
    int x = MGPR_(window).x;
    int y = MGPR_(window).y;

    if (x > 70 && x < 390 && y > 330 && y < 580){
        sfMusic_play(play);
        while (sfClock_getElapsedTime(duckclock).microseconds < 3000000.0);
        sfClock_destroy(duckclock);
        sfMusic_destroy(play);
        destroy_all(window, theme);
        myhunter();
    }
}

static void lanalyse_events(sfRenderWindow *window, sfEvent *event,
    sfMusic *theme)
{
    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtMouseButtonPressed)
            lmanage_mouse_click(window, theme);
        if (event->type == sfEvtKeyPressed)
            lkey_events(window, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void launcher(void)
{
    sfRenderWindow *window = crlw(window);
    sfEvent event;
    sfSprite *background = sfSprite_create();
    sfMusic *theme = sfMusic_createFromFile(LTHEME);

    sfSprite_setTexture(background, TX_(LBG_, 0), sfFalse);
    sfSprite_setScale(background, (sfVector2f){0.63, 0.63});
    sfMusic_play(theme);
    sfMusic_setLoop(theme, sfTrue);
    sfRenderWindow_drawSprite(window, background, 0);
        sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)){
        lanalyse_events(window, &event, theme);
    }
    sfSprite_destroy(background);
}

int main(int ac, char **av)
{
    if (ac == 1 || (ac > 1 && my_strcmp(av[1], "-l") == 0))
        launcher();
    if (ac > 1 && my_strcmp(av[1], "-h") == 0)
        my_printf("USAGE\n    ./myhunter\n");
    if (ac > 1 && my_strcmp(av[1], "-p") == 0)
        myhunter();
    if (ac > 1 && my_strcmp(av[1], "-e") == 0)
        gameover(69);
    return 0;
}
