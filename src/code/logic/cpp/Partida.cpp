#include "../headers/Partida.h"
#include "../headers/InfoJoc.h"
#include "../headers/GraphicManager.h"


//void Partida::actualitza(double deltaTime)
//{
//	// Draws the background and the board
//	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
//	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
//
//	// Drops the shape every .5 seconds
//	m_temps += deltaTime;
//	if (m_temps > 0.5)
//	{
//		if (m_fila < N_FILES_TAULER - 1)
//			m_fila++;
//		m_temps = 0.0;
//	}
//
//	// Checks for input
//	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
//		if (m_columna < N_COL_TAULER)
//			m_columna++;
//
//	if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
//		if (m_columna > 1)
//			m_columna--;
//
//	int posX;
//	int posY;
//
//	GraphicManager::getInstance()->drawSprite(
//		GRAFIC_QUADRAT_GROC,
//		POS_X_TAULER + (1 * MIDA_QUADRAT),
//		POS_Y_TAULER,
//		false
//	);
//
//	// Renders the sprite
//	for (int i = 0; i < MIDA; i++)
//	{
//		for (int j = 0; j < MIDA; j++)
//		{
//			if (m_forma[i][j] != NO_COLOR)
//			{
//				posY = i + m_fila;
//				posX = j + m_columna;
//
//				GraphicManager::getInstance()->drawSprite(
//					GRAFIC_QUADRAT_BLAUFOSC,
//					POS_X_TAULER + (posX * MIDA_QUADRAT),
//					POS_Y_TAULER + (posY * MIDA_QUADRAT),
//					false
//				);
//			}
//		}
//	}
//
//
//	// TODO 4: Imprimir text per pantalla
//	//------------------------------------------
//	// TODO 4.1: Mostrar la posici� actual del quadrat a dalt del tauler
//	string coords = "X: " + to_string(m_columna) + " Y: " + to_string(m_fila);
//
//	GraphicManager::getInstance()->drawFont(
//		FONT_WHITE_30,
//		POS_X_TAULER + (MIDA_QUADRAT),
//		POS_Y_TAULER,
//		1,
//		coords
//	);
//}
