/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** nb_display
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

void nb_display(int nbr, sfIntRect *rect1, sfIntRect *rect2)
{
    int nb1 = nbr / 10;
    int nb2 = nbr % 10;

    rect1->left = nb1 * 20;
    rect2->left = nb2 * 20;
}

void nb_display2(ic *st, sfVector2f sc, sfRenderWindow *win, sfVector2f pos)
{
    int nb = 0;
    sfSprite *number = sfSprite_create();
    int i = 1;

    for (int tempnbr = st->nbr; tempnbr != 0; i++)
        tempnbr /= 10;
    for (; st->nbr % 10 != 0; st->nbr--)
        nb++;
    sfSprite_setPosition(number, (sfVector2f){pos.x + (i * 20 * sc.x), pos.y});
    sfSprite_setScale(number, sc);
    sfSprite_setTextureRect(number, (sfIntRect){nb * 20, 0, 20, 30});
    sfSprite_setColor(number, st->color);
    sfSprite_setTexture(number, sfTexture_createFromFile(NB_, NULL), sfFalse);
    st->nbr /= 10;
    if (st->nbr != 0)
        nb_display2(st, sc, win, pos);
    sfRenderWindow_drawSprite(win, number, sfFalse);
    sfSprite_destroy(number);
}
