#include <math.h>
#include "graphics.h"
#include "game.h"
#include "sound.h"
#include "objects.h"
#include "handleInputs.h"
#include "doUpdate.h"
#include "drawScreen.h"
#include "drawUtilities.h"
#include "exceptions.h"

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicacao
    gameData game;

    initScreen(&game);

    setupGame(&game);

    game.lastTime = SDL_GetPerformanceCounter();
	while(1)
    {

        // Gerencia entradas do usu�rio pelo teclado
        //printf("travou no handle inputs\n");
        handleInputs(&game);

        //printf("travou no doUpdate\n");
        // Gerencia logica da aplicacao
        doUpdate(&game);

        //printf("travou no drawScreen\n");
        // Atualiza a tela
        drawScreen(&game);
        game.ammoutOfCollisions = 0;
    }

    endGame(&game);

	return 0;
}
