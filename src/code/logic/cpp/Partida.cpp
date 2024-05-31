#include <fstream>
#include "../headers/Partida.h"
#include "../headers/InfoJoc.h"
#include "../headers/GraphicManager.h"

void Partida::inicialitza(
	int mode,
	const string& fitxerInicial,
	const string& fitxerFigures,
	const string& fitxerMoviments)
{
	m_game.inicialitza(fitxerInicial);
}

void Partida::actualitza(double deltaTime)
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	m_game.showBoard();

	/*
	update(0.5, deltaTime);

	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		m_game.mouFigura(1);

	if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		m_game.mouFigura(0);

	// Sample code for display coordinates
	string coords = "X: " + to_string(0) + " Y: " + to_string(0);

	GraphicManager::getInstance()->drawFont(
		FONT_WHITE_30,
		POS_X_TAULER + (MIDA_QUADRAT),
		POS_Y_TAULER - (MIDA_QUADRAT),
		1,
		coords
	);
	*/
}

// TODO update name
void Partida::update(float waitTime, double deltaTime)
{
	m_time += deltaTime;
	if (m_time > waitTime)
	{
		m_game.baixaFigura();
		m_time = 0.0;
	}
}

