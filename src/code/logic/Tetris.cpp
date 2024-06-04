#include "headers/Tetris.h"
#include "headers/InfoJoc.h"
#include "headers/Partida.h"
#include <iostream>
#include <SDL2/SDL.h>

void Tetris::play()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

	// Game info
	int gameIndex = 4;

	do
	{
		gameIndex = showTerminalMenu();
		GameMode gameMode = NORMAL;
		Partida game;

		if (gameIndex == 4)
		{
			SDL_Quit();
			return;
		}

		// SDL Setup
		pantalla.show();
		Uint64 NOW = SDL_GetPerformanceCounter();
		Uint64 LAST = 0;
		double deltaTime = 0;

		if (gameIndex == 2)
		{
			gameMode = AUTOMATED;
		}

		game.inicialitza(gameMode, "../data/partida.txt", "../data/figures.txt", "../data/moviments.txt");

		while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
		{
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
			pantalla.processEvents();
			game.actualitza(gameMode, deltaTime);
			pantalla.update();
		}

		pantalla.processEvents();
		pantalla.update();
	} while (true);
}

int Tetris::showTerminalMenu()
{
	bool isInputValid = false;
	char userInput;
	int chosenMode;

	cout << "-------------------------------" << "\n";
	cout << "---- Welcome to tetris-cpp ----" << "\n";
	cout << "-------------------------------" << "\n\n";

	while (!isInputValid)
	{
		cout << "-------------------------------" << "\n";
		cout << "Choose a mode " << "\n";
		cout << "1. Normal Game " << "\n";
		cout << "2. Automated Game " << "\n";
		cout << "3. See Highscores " << "\n";
		cout << "4. Quit " << "\n";
		cout << "-------------------------------" << "\n";

		std::cin >> userInput;

		if (isdigit(userInput))
		{
			chosenMode = userInput - '0';

			if (chosenMode > 0 && chosenMode < 5)
				isInputValid = true;
		}

		if (!isInputValid)
			cout << "Invalid input, select an actual mode." << "\n";
	}

	return chosenMode;
}
