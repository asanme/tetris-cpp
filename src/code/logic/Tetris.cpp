#include "headers/Tetris.h"
#include "headers/InfoJoc.h"
#include "headers/Partida.h"
#include "../util/headers/Utilities.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <limits>

const std::string GAME_DATA = "../data/partida.txt";
const std::string SHAPE_DATA = "../data/figures.txt";
const std::string MOVEMENT_DATA = "../data/moviments.txt";

void Tetris::play()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	int selection;

	do
	{
		selection = selectModeMenu();

		if (selection == 1 || selection == 2)
		{
			GameMode gameMode = static_cast<GameMode>(selection - 1);
			Partida game;

			// SDL Setup
			pantalla.show();
			Uint64 NOW = SDL_GetPerformanceCounter();
			Uint64 LAST = 0;
			double deltaTime = 0;
			game.inicialitza(gameMode, GAME_DATA, SHAPE_DATA, MOVEMENT_DATA);

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

			// Once the game has finished, add the score to the list of scores
			addNewScore(game.getGameScore());
		}
		else if (selection == 3)
		{
			showHighScores();
		}
		else
		{
			SDL_Quit();
			return;
		}
	} while (true);
}

void Tetris::showHighScores()
{
	cout << "-------------------------------" << "\n";
	cout << "----- Showing Best Scores -----" << "\n";
	cout << "-------------------------------" << "\n\n";

	loadHighScores();
	for (int i = 0; i < 10; ++i)
	{
		cout << i + 1 << ". ";
		if (i < m_scores.size())
			cout << m_scores[i].name << " " << m_scores[i].score << " points";
		else
			cout << " - ";

		cout << "\n";
	}

	cout << "\n";
}

int Tetris::selectModeMenu()
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

	cout << "\n";

	return chosenMode;
}

void Tetris::loadHighScores()
{
	deserializeHighScores(m_scores);
}

// This prevents conflicts with SDL after the game finishes
void clearCinBuffer()
{
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Tetris::addNewScore(int score)
{
	string name;
	cout << "Introduce your name:\n";
	clearCinBuffer();
	getline(cin, name);
	HighScore newScore = HighScore({ name, score });

	loadHighScores();

	m_scores.push_back(newScore);
	bubbleSort(m_scores);
	serializeHighScore(m_scores);
}
