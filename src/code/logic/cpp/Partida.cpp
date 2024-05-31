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

	update(0.5, deltaTime);
	m_game.showBoard();
	m_game.showCoordinates();

	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		m_game.mouFigura(1);

	if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		m_game.mouFigura(-1);
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

