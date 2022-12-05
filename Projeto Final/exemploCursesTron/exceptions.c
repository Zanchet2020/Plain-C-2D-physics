#include "exceptions.h"

void throwException(gameData * game, unsigned int type){
    printf("\nErro! ");
    switch(type){
        case NOT_ENOUGHT_MEMORY:
        {
            printf("Nao ha memoria suficiente!\n");// Codigo de erro %x\n", NOT_ENOUGHT_MEMORY);
            endGame(game);
            break;
        }
        case FAIL_TO_CREATE_RENDERER:
        {
            printf("Falha ao criar renderizador!\n");// Codigo de erro %x\n", FAIL_TO_CREATE_RENDERER);
            endGame(game);
            break;
        }
        case FAIL_TO_CREATE_WINDOW:
        {
            printf("Falha ao criar janela!\n");// Codigo de erro %x\n", FAIL_TO_CREATE_WINDOW);
            endGame(game);
            break;
        }
        case FAIL_TO_CREATE_TEXTURE:
        {
            printf("Falha ao criar textura!\n");// Codigo de erro %x\n", FAIL_TO_CREATE_TEXTURE);
            endGame(game);
            break;
        }
        case _HEAPBADBEGIN:
        {
            printf("Erro: _HEAPBADBEGIN");
            endGame(game);
            break;
        }
        case _HEAPBADNODE:
        {
            printf("Erro: _HEAPBADNODE");
            endGame(game);
            break;
        }
        case _HEAPBADPTR:
        {
            printf("Erro: _HEAPBADPTR");
            endGame(game);
            break;
        }
        case _HEAPEMPTY:
        {
            printf("Erro: _HEAPEMPTY");
            endGame(game);
            break;
        }
    }
    exit(type);
}
