#ifndef HANDLEINPUTS_H_INCLUDED
#define HANDLEINPUTS_H_INCLUDED
#include <SDL.h>
#include "game.h"
#include "graphics.h"

void handleInputs(gameData * game);

void mousePress(gameData * game, SDL_MouseButtonEvent b);
void mouseRelease(gameData * game, SDL_MouseButtonEvent b);
void keyPress(gameData * game, SDL_KeyboardEvent k);

#endif // HANDLEINPUTS_H_INCLUDED
