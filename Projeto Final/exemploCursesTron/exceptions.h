#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include <stdio.h>
#include "game.h"
#include "graphics.h"

enum ERRORS {
    NOT_ENOUGHT_MEMORY = 0x1,
    FAIL_TO_CREATE_RENDERER,
    FAIL_TO_CREATE_WINDOW,
    FAIL_TO_CREATE_TEXTURE
};

void throwException(gameData * game, unsigned int type);
void writeLog(gameData * game, unsigned int type);

#endif // EXCEPTIONS_H_INCLUDED
