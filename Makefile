main_rl:
	cc *.c -o bin/main_rl -Wall -lm -lraylib

main_sdl:
	cc *.c -o bin/main_sdl -Wall `sdl2-config --cflags --libs` -lm
	#cc *.c -o bin/main  -Wall -ISDL2/include/SDL2 -Dmain=SDL_main -LSDL2/lib -lm -lSDL2main -lSDL2 
