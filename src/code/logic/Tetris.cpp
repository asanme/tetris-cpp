#include "headers/Tetris.h"
#include "headers/InfoJoc.h"
#include "headers/Partida.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "../graphic-lib/libreria.h"

void Tetris::play()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

	// BUG if the player keeps pressing a key and the game ends -> the input gets saved, so the next game it will get immediately executed
	do
	{
		pantalla.show();
		Uint64 NOW = SDL_GetPerformanceCounter();
		Uint64 LAST = 0;
		double deltaTime = 0;
		GameMode gameMode = NORMAL;
		int gameIndex;
		Partida game;

		std::cout << "-------------------------------" << "\n";
		std::cout << "---- Welcome to tetris-cpp ----" << "\n";
		std::cout << "-------------------------------" << "\n";
		std::cout << "Choose a mode " << "\n";
		std::cout << "1. Normal Game " << "\n";
		std::cout << "2. Automated Game " << "\n";
		std::cout << "3. See Highscores " << "\n";
		std::cout << "-------------------------------" << "\n";

		std::cin >> gameIndex;
		if (gameIndex == 2)
		{
			gameMode = AUTOMATED;
		}

		game.inicialitza(gameMode, "../data/partida.txt", "../data/figures.txt", "../data/moviments.txt");

		while (!game.hasGameFinished())
		{
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
			pantalla.processEvents();
			game.actualitza(gameMode, deltaTime);
			pantalla.update();
		}

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

	SDL_Quit();
}
