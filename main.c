#include "graphics.h"
#include "game.h"
#include "sound.h"
#include "objects.h"
#include "handleInputs.h"
#include "doUpdate.h"
#include "drawScreen.h"
#include "drawUtilities.h"
#include "exceptions.h"

#include <raylib.h>
#include <raymath.h>

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicacao
  gameData game;

  initScreen(&game);

  setupGame(&game);

  //game.lastTime = SDL_GetPerformanceCounter();
    while(!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("My first working window!!", 200, 300, 20, LIGHTGRAY);
      EndDrawing();


      handleInputs(&game);



        //doUpdate(&game);



        //drawScreen(&game);
        //game.ammoutOfCollisions = 0;
    }
    CloseWindow();
	//endGame(&game);

	return 0;
}
