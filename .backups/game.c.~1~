#include "game.h"
#include "exceptions.h"

#define BALL_VECTOR_INIT_SIZE 500
#define LINE_VECTOR_INIT_SIZE 100

//////////////////////////////////////////////////////////////////////
// Funções da aplicação
//////////////////////////////////////////////////////////////////////

void updateClock(gameData * game){
    game->currentTime = SDL_GetPerformanceCounter();
    game->deltaTime = (double)((game->currentTime - game->lastTime)/ (double)SDL_GetPerformanceFrequency()); //(double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() )
    game->lastTime = game->currentTime;
}

void endGame(gameData * game){
    free(game->balls);
    free(game->lines);
    free(game->collidedBalls);
    endScreen(game);
}

void setupGame(gameData * game){
    game->balls = malloc(BALL_VECTOR_INIT_SIZE * sizeof(ball_t));
    game->lines = malloc(LINE_VECTOR_INIT_SIZE * sizeof(line_t));
    game->collidedBalls = malloc(BALL_VECTOR_INIT_SIZE * sizeof(collidedBallPairs));
    game->ammoutOfCollisions = 0;
    game->ballAmout = 0;
    game->lineAmount = 0;
    if(game->balls == NULL || game->lines == NULL){
        throwException(game, NOT_ENOUGHT_MEMORY);
    }
    game->fps = 0;

    game->selectedBall = NULL;
    game->ballToThrow = NULL;
    game->selectedLine = NULL;

    int defaultRadius = 50;
}

void pushCollidedBalls(gameData * game, ball_t * a, ball_t * b){
    static unsigned int sizeOfCollisionVector = 1;
    unsigned int i;
    collidedBallPairs * temp;
    if(game->ammoutOfCollisions >= (BALL_VECTOR_INIT_SIZE * sizeOfCollisionVector)-2){
        temp = (collidedBallPairs*) malloc(BALL_VECTOR_INIT_SIZE * ++sizeOfCollisionVector * sizeof(collidedBallPairs));
        if(temp != NULL){
            memcpy(temp, game->collidedBalls, BALL_VECTOR_INIT_SIZE * (sizeOfCollisionVector-1) * sizeof(collidedBallPairs));
            free(game->collidedBalls);
            game->collidedBalls = temp;
        } else {
            throwException(game, NOT_ENOUGHT_MEMORY);
        }
    }
    for(i = 0; i < game->ammoutOfCollisions; i++){
        if((a == game->collidedBalls[i].a && b == game->collidedBalls[i].b) || (a == game->collidedBalls[i].b && b == game->collidedBalls[i].a))
            return;
    }
    game->collidedBalls[game->ammoutOfCollisions].a = a;
    game->collidedBalls[game->ammoutOfCollisions++].b = b;
}

void newLine(gameData * game, float x0, float y0, float x1, float y1, float radius, color_t col){
    if(game->lineAmount < LINE_VECTOR_INIT_SIZE){
        line_t Line = { .start.x = x0,
                        .start.y = y0,
                        .ending.x = x1,
                        .ending.y = y1,
                        .col = col,
                        .radius = radius
        };
        game->lines[game->lineAmount++] = Line;
    }
}



void newBall(gameData * game, float x, float y, float rad, float mass, color_t color){
    if(game->ballAmout < BALL_VECTOR_INIT_SIZE){
        ball_t Ball = { .pos.x = x,
                        .pos.y = y,
                        .radius = rad,
                        .mass = rad,
                        .col = color
        };
        game->balls[game->ballAmout++] = Ball;
    }
}

void removeBall(gameData * game, unsigned int index){
    for(index; index < game->ballAmout; index++){
        game->balls[index] = game->balls[index+1];
    }
}

