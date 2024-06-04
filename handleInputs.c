#include "handleInputs.h"
#include <stdlib.h>

void mousePress(gameData * game, SDL_MouseButtonEvent b){
    unsigned int i;
    if(b.button == SDL_BUTTON_RIGHT){
        for(i = 0; i < game->ballAmout; i++){
            if(distance(game->balls[i].pos, game->mousePos) < game->balls[i].radius && game->selectedBall == NULL){
                game->selectedBall = &game->balls[i];
            }
        }
    } else if(b.button == SDL_BUTTON_MIDDLE){
        newBall(game, game->mousePos.x, game->mousePos.y, (rand()%50)+10, 10, colorize(0, 0, 255, 255));
    } else if(b.button == SDL_BUTTON_LEFT){
        for(i = 0; i < game->ballAmout; i++){
            if(distance(game->balls[i].pos, game->mousePos) < game->balls[i].radius && game->selectedBall == NULL){
                game->ballToThrow = &game->balls[i];
            }
        }
    }
}

void mouseRelease(gameData * game, SDL_MouseButtonEvent b){
    if(b.button == SDL_BUTTON_RIGHT && game->selectedBall != NULL){
        //game->selectedBall->vel = vectorize(0,0);
        game->selectedBall = NULL;
    } else if (b.button == SDL_BUTTON_LEFT && game->ballToThrow != NULL){
        game->ballToThrow->vel.x = 5 * (game->ballToThrow->pos.x - game->mousePos.x);
        game->ballToThrow->vel.y = 5 * (game->ballToThrow->pos.y - game->mousePos.y);
        game->ballToThrow = NULL;
    }

}

void keyPress(gameData * game, SDL_KeyboardEvent k){
    unsigned int i;
    if(k.keysym.scancode == SDL_SCANCODE_Q){
        newBall(game, game->mousePos.x, game->mousePos.y, (rand()%50)+10, 10, colorize(rand()%255, rand()%255, rand()%255, 255));
    } else if (k.keysym.scancode == SDL_SCANCODE_ESCAPE){
        endGame(game);
        printf("Jogo fechado\n");
        exit(0);
    } else if (k.keysym.scancode == SDL_SCANCODE_R){
        for(i = 0; i < game->ballAmout; i++){
            if(distance(game->balls[i].pos, game->mousePos) < game->balls[i].radius ){
                removeBall(game, i);
            }
        }
    }
}

void handleInputs(gameData * game)
{

    static SDL_Event event;
    int entrada = -1;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
            {
                endGame(game);
                printf("Jogo fechado\n");
                exit(0);
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                mousePress(game, event.button);
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                mouseRelease(game, event.button);
            }
            case SDL_MOUSEMOTION:
            {
                game->mousePos = vectorize(event.motion.x, event.motion.y);
            }
            case SDL_KEYDOWN:
            {
                keyPress(game, event.key);
            }
            default:{
                break;
            }
        }
    }
}

