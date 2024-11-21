#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SDL.h>
#include <stdlib.h>
#include "objects.h"

#define WINDOWSIZE_X 1920
#define WINDOWSIZE_Y 1080

// Estrutura com estado interno da aplicação
typedef struct gameData
{
    SDL_Window *window;
    SDL_Texture *texture;
    SDL_Renderer *renderer;

    Uint64 lastTime;
    Uint64 currentTime;
    double deltaTime;

    void * buffer;
    int pitch;

    ball_t * balls;
    unsigned int ballAmout;
    ball_t * selectedBall;
    ball_t * ballToThrow;

    line_t * lines;
    unsigned int lineAmount;
    line_t * selectedLine;

    vec2 mousePos;

    collidedBallPairs * collidedBalls;
    unsigned int ammoutOfCollisions;

    int fps;

    int gravity;


} gameData;


void updateClock(gameData * game);
void setupGame(gameData * game);
void endGame(gameData * game);

void newBall(gameData * game, float x, float y, float rad, float mass, color_t col);
void newLine(gameData * game, float x0, float y0, float x1, float y1, float radius, color_t col);
void pushCollidedBalls(gameData * game, ball_t * a, ball_t * b);
void ClearBallCollisions(gameData * game);


#endif // GAME_H_INCLUDED
