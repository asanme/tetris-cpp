#include <SDL2/SDL.h>
#include "./code/graphic-lib/libreria.h"
#include "code/logic/headers/InfoJoc.h"
#include "code/logic/headers/Partida.h"

int main(int argc, const char* argv[])
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	pantalla.show();

	Partida game;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	game.inicialitza(1, "../data/partida.txt", "../data/figures.txt", "../data/moviments.txt");

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		pantalla.processEvents();

		game.actualitza(NORMAL, deltaTime);

		pantalla.update();
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

	SDL_Quit();
	return 0;
}

