#include "drawScreen.h"
#include "drawUtilities.h"

void drawScreen(gameData * game)
{

    SDL_LockTexture(game->texture, NULL, &game->buffer, &game->pitch);

    UpdateTexture(game);

    SDL_UnlockTexture(game->texture);

    SDL_RenderClear(game->renderer);
    SDL_RenderCopy(game->renderer, game->texture, NULL, NULL);
    SDL_RenderPresent(game->renderer);
}

void UpdateTexture(gameData * game){
    unsigned int i;

    ClearTexture(game, colorize(64,140,54,255));

    drawBall(game, vectorize(0,0), 100, colorize(0, 0, 0, 255));
    drawBall(game, vectorize(0,WINDOWSIZE_Y), 100, colorize(0, 0, 0, 255));
    drawBall(game, vectorize(WINDOWSIZE_X / 2,WINDOWSIZE_Y), 100, colorize(0, 0, 0, 255));
    drawBall(game, vectorize(WINDOWSIZE_X,WINDOWSIZE_Y), 100, colorize(0, 0, 0, 255));
    drawBall(game, vectorize(WINDOWSIZE_X,0), 100, colorize(0, 0, 0, 255));
    drawBall(game, vectorize(WINDOWSIZE_X / 2,0), 100, colorize(0, 0, 0, 255));

    //printf("travou no desenho das bolas\n");
    for(i = 0; i < game->ballAmout; i++){
        drawBall(game, game->balls[i].pos, game->balls[i].radius, game->balls[i].col);
    }
    //printf("travou no desenho das linhas de colisao\n");
    for(i = 0; i < game->ammoutOfCollisions ; i++){
        drawLine(game, game->collidedBalls[i].a->pos, game->collidedBalls[i].b->pos, colorize(255, 0, 0, 255));
    }
    //printf("travou no desenho das linhas \n");
    for(i = 0; i < game->lineAmount; i++){
        drawLine(game, game->lines[i].start, game->lines[i].ending, game->lines[i].col);
        drawBall(game, game->lines[i].start, game->lines[i].radius, game->lines[i].col);
        drawBall(game, game->lines[i].ending, game->lines[i].radius, game->lines[i].col);
    }
    //printf("travou no desenho das linhas de jogada\n");
    if(game->ballToThrow != NULL){
        drawLine(game, game->ballToThrow->pos, game->mousePos, colorize(0, 255, 0, 255));
        drawBall(game, game->mousePos, 20, colorize(125, 125, 0, 255));
    }





}
