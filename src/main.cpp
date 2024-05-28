#include "./code/graphic-lib/libreria.h"
#include "./code/graphic-lib/NFont/NFont.h"
#include "code/logic/headers/Partida.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

int main(int argc, const char* argv[])
{
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	//Mostrem la finestra grafica
	pantalla.show();

	Partida game;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();

		game.actualitza(deltaTime);

		// Actualitza la pantalla
		pantalla.update();

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
	// Sortim del bucle si pressionem ESC

	//Instruccio necesaria per alliberar els recursos de la llibreria
	SDL_Quit();
	return 0;
}

