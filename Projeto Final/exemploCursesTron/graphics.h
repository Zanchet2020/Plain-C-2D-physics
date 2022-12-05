#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include <SDL.h>
#include "game.h"
#include "exceptions.h"



// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

void initScreen(gameData * game);
void endScreen(gameData * game);

#endif // GRAPHICS_H_INCLUDED
