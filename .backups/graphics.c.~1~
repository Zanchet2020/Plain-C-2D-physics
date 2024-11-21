#include "graphics.h"



void initScreen(gameData * game)
{
    SDL_Init( SDL_INIT_VIDEO );

    game->window = SDL_CreateWindow("Teste", 0, 0, WINDOWSIZE_X, WINDOWSIZE_Y, SDL_WINDOW_SHOWN );

    //handle de erro
    if(game->window == NULL)
        throwException(game, FAIL_TO_CREATE_WINDOW);

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    //handle de erro
    if(game->renderer == NULL)
        throwException(game, FAIL_TO_CREATE_RENDERER);

    game->texture = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOWSIZE_X, WINDOWSIZE_Y);
    //handle de erro
    if(game->texture == NULL)
        throwException(game, FAIL_TO_CREATE_TEXTURE);
    //clear screen
    SDL_SetRenderDrawColor(game->renderer, 255, 0 , 0 , 0);
    SDL_RenderClear(game->renderer);
}

void endScreen(gameData * game)
{
    //libera memoria e encerra a aplicacao grafica


    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
