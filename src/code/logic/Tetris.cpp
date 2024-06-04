#include "headers/Tetris.h"
#include "headers/InfoJoc.h"
#include "../util/headers/Utilities.h"
#include <SDL2/SDL.h>

const std::string GAME_DATA = "../data/partida.txt";
const std::string SHAPE_DATA = "../data/figures.txt";
const std::string MOVEMENT_DATA = "../data/moviments.txt";

void Tetris::play()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	int selection;

	Mouse_Init();
	playMusic();

	do
	{
		selection = guiSelectionMenu(pantalla);
		// NON-GUI Menu
		//selection = terminalSelectionMenu();

		if (selection == 1 || selection == 2)
		{
			GameMode gameMode = static_cast<GameMode>(selection - 1);
			startGame(pantalla, gameMode);
		}
		else if (selection == 3)
		{
			showGuiHighScores(pantalla);
			// NON-GUI HighScores
			//showTerminalHighScores();
		}
		else
		{
			SDL_Quit();
			return;
		}
	} while (true);
}

void Tetris::startGame(Screen& pantalla, GameMode& gameMode)
{
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

	// Only save score in NORMAL mode
	if (gameMode == NORMAL)
	{
		int gameScore = game.getGameScore();
		if (gameScore > 0)
			addNewScore(gameScore);
	}
}

void Tetris::showTerminalHighScores()
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

void Tetris::showGuiHighScores(Screen& pantalla)
{
	pantalla.show();
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	loadHighScores();
	int maxY = 200;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		pantalla.processEvents();

		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 4, 100 - 4, 2, "HIGHSCORES");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 0, 100, 2, "HIGHSCORES");

		for (int i = 0; i < 5; ++i)
		{
			string currentHighScore;

			if (i < m_scores.size())
			{
				currentHighScore = m_scores[i].name + " - " + to_string(m_scores[i].score);
				GraphicManager::getInstance()->drawFont(FONT_RED_30, 4, maxY + (i * 100) - 4, 1, currentHighScore);
				GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 0, maxY + (i * 100), 1, currentHighScore);
			}
			else
			{
				currentHighScore = "- ";
				GraphicManager::getInstance()->drawFont(FONT_RED_30, 4, maxY + (i * 100) - 4, 1, currentHighScore);
				GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 0, maxY + (i * 100), 1, currentHighScore);
			}
		}

		pantalla.update();
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
}

int Tetris::guiSelectionMenu(Screen& pantalla)
{
	BoxBounds normalButtonBounds = { 170, 290, 460, 350 };
	BoxBounds automatedButtonBounds = { 110, 390, 540, 450 };
	BoxBounds highScoreButtonBounds = { 80, 490, 550, 550 };
	BoxBounds exitButtonBounds = { 385, 610, 580, 670 };

	SDL_Rect normalBounds = {
		normalButtonBounds.minX,
		normalButtonBounds.minY,
		normalButtonBounds.maxX - normalButtonBounds.minX,
		normalButtonBounds.maxY - normalButtonBounds.minY
	};

	SDL_Rect autoBounds = {
		automatedButtonBounds.minX,
		automatedButtonBounds.minY,
		automatedButtonBounds.maxX - automatedButtonBounds.minX,
		automatedButtonBounds.maxY - automatedButtonBounds.minY
	};

	SDL_Rect highBounds = {
		highScoreButtonBounds.minX,
		highScoreButtonBounds.minY,
		highScoreButtonBounds.maxX - highScoreButtonBounds.minX,
		highScoreButtonBounds.maxY - highScoreButtonBounds.minY
	};

	SDL_Rect exitBounds = {
		exitButtonBounds.minX,
		exitButtonBounds.minY,
		exitButtonBounds.maxX - exitButtonBounds.minX,
		exitButtonBounds.maxY - exitButtonBounds.minY
	};

	pantalla.show();
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		pantalla.processEvents();

		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 4, 100 - 4, 2, "TETRIS.CPP");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 0, 100, 2, "TETRIS.CPP");

		SDL_SetRenderDrawColor(g_Video.renderer, 25, 83, 95, 255);
		SDL_RenderFillRect(g_Video.renderer, &normalBounds);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 180 + 4, 300 - 4, 1.5, "NORMAL");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 180, 300, 1.5, "NORMAL");

		SDL_SetRenderDrawColor(g_Video.renderer, 25, 83, 95, 255);
		SDL_RenderFillRect(g_Video.renderer, &autoBounds);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 120 + 4, 400 - 4, 1.5, "AUTOMATED");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 120, 400, 1.5, "AUTOMATED");

		SDL_SetRenderDrawColor(g_Video.renderer, 25, 83, 95, 255);
		SDL_RenderFillRect(g_Video.renderer, &highBounds);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 90 + 4, 500 - 4, 1.5, "HIGHSCORES");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 90, 500, 1.5, "HIGHSCORES");

		SDL_SetRenderDrawColor(g_Video.renderer, 25, 83, 95, 255);
		SDL_RenderFillRect(g_Video.renderer, &exitBounds);
		GraphicManager::getInstance()->drawFont(FONT_RED_30, SCREEN_SIZE_X - 204, 700 - 84, 1.5, "QUIT");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X - 200, 700 - 80, 1.5, "QUIT");

		pantalla.update();
		if (Mouse_getButLeft())
		{
			int mouseX = Mouse_getX();
			int mouseY = Mouse_getY();

			bool wasNormalClicked = wasBoxClicked(normalButtonBounds, mouseX, mouseY);
			bool wasAutoClicked = wasBoxClicked(automatedButtonBounds, mouseX, mouseY);
			bool wasHighClicked = wasBoxClicked(highScoreButtonBounds, mouseX, mouseY);
			bool wasExitClicked = wasBoxClicked(exitButtonBounds, mouseX, mouseY);

			if (wasNormalClicked)
				return 1;
			else if (wasAutoClicked)
				return 2;
			else if (wasHighClicked)
				return 3;
			else if (wasExitClicked)
			{
				SDL_Quit();
				return 4;
			}
		}
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

	SDL_Quit();
	return -1;
}

int Tetris::terminalSelectionMenu()
{
	bool isInputValid = false;
	std::string userInput;
	int chosenMode = 0;

	std::cout << "-------------------------------" << "\n";
	std::cout << "---- Welcome to tetris-cpp ----" << "\n";
	std::cout << "-------------------------------" << "\n\n";

	while (!isInputValid)
	{
		std::cout << "-------------------------------" << "\n";
		std::cout << "Choose a mode " << "\n";
		std::cout << "1. Normal Game " << "\n";
		std::cout << "2. Automated Game " << "\n";
		std::cout << "3. See Highscores " << "\n";
		std::cout << "4. Quit " << "\n";
		std::cout << "-------------------------------" << "\n";

		std::getline(std::cin, userInput);

		if (userInput == "1" || userInput == "2" || userInput == "3" || userInput == "4")
		{
			chosenMode = std::stoi(userInput);
			isInputValid = true;
		}
		else
		{
			std::cout << "Invalid input, select an actual mode (1-4)." << "\n";
		}
	}

	std::cout << "\n";
	return chosenMode;
}

void Tetris::loadHighScores()
{
	deserializeHighScores(m_scores);
}

void Tetris::addNewScore(int score)
{
	string name;

	cout << "Introduce your name:\n";
	getline(cin, name);
	HighScore newScore = HighScore({ name, score });

	loadHighScores();

	m_scores.push_back(newScore);
	bubbleSort(m_scores);
	serializeHighScore(m_scores);
}

void Tetris::playMusic()
{
	Sound_Init();
	Sound_LoadMusic("../resources/sounds/tetris-copyright-free.ogg", PLAY_FROM_DISK_STREAM);
}
