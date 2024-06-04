#pragma once

#include <string>
#include <vector>
#include "../../graphic-lib/libreria.h"
#include "Partida.h"

typedef struct
{
	std::string name;
	int score;
} HighScore;

class Tetris
{
 public:
	Tetris() = default;
	void play();

 private:
	std::vector<HighScore> m_scores;

	// Score
	void loadHighScores();
	void addNewScore(int score);

	// Sound
	void playMusic();

	// UI
	void showTerminalHighScores();
	void showGuiHighScores(Screen& pantalla);

	static int terminalSelectionMenu();
	int guiSelectionMenu(Screen& pantalla);

	// Others
	void startGame(Screen& pantalla, GameMode& gameMode);
};

