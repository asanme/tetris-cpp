#pragma once

#include <string>
#include <vector>

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
	void showHighScores();
	void loadHighScores();
	void addNewScore(int score);

	// UI
	static int selectModeMenu();
	static int showGUIMenu();
};

