#pragma once

#include <string>
#include <vector>
#include "../../graphic-lib/libreria.h"

typedef struct
{
	std::string name;
	int score;
} HighScore;

class Tetris
{
 public:
	Tetris() : m_tetrisMusic(nullptr)
	{
	}
	void play();

 private:
	std::vector<HighScore> m_scores;
	T_SOUND* m_tetrisMusic;

	// Score
	void showHighScores();
	void loadHighScores();
	void addNewScore(int score);

	// Sound
	void playMusic();
	void stopMusic();

	// UI
	static int selectModeMenu();
	static int showGUIMenu();
};

