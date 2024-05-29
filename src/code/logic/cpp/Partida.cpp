#include "../headers/Partida.h"
#include "../headers/InfoJoc.h"
#include "../headers/GraphicManager.h"

Partida::Partida()
{
	m_temps = 0;
	for (int i = 0; i < MIDA; i++)
		for (int j = 0; j < MIDA; j++)
			m_forma[i][j] = NO_COLOR;
	m_forma[0][0] = COLOR_BLAUFOSC;
	m_forma[1][0] = COLOR_BLAUFOSC;
	m_forma[1][1] = COLOR_BLAUFOSC;
	m_forma[1][2] = COLOR_BLAUFOSC;
	m_fila = 1;
	m_columna = 5;
}

void Partida::actualitza(double deltaTime)
{
	// Draws the background and the board
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

	m_temps += deltaTime;
	if (m_temps > 0.5)
	{
		if (m_fila < N_FILES_TAULER)
			m_fila++;
		m_temps = 0.0;
	}

	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		if (m_columna < N_COL_TAULER)
			m_columna++;

	if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		if (m_columna > 1)
			m_columna--;

	for (int i = 0; i < MIDA; i++)
	{
		for (int j = 0; j < MIDA; j++)
		{
			if (m_forma[i][j] != NO_COLOR)
			{
				int posY = i + m_fila;
				int posX = j + m_columna;

				GraphicManager::getInstance()->drawSprite(
					GRAFIC_QUADRAT_BLAUFOSC,
					POS_X_TAULER + (posX * MIDA_QUADRAT),
					POS_Y_TAULER + (posY * MIDA_QUADRAT),
					false
				);
			}
		}
	}

	// TODO 2.2 Dibuixar a pantalla el gr�fic amb el tauler i la figura representada a l�atribut m_forma
	// a la posici� del tauler indicada per m_fila i m_columna.
	// Moure la figura cap a la dreta o l�esquerra si es pressionen les tecles de les fletxes corresponents,
	// comprovant que no ens passem dels limits del tauler.



	//TODO 3: Introduir un temps d'espera
	//-----------------------------------
	// TODO 3.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i
	// m_columna. Fer que cada mig segon baixi una fila




	// TODO 3.2: Dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i  m_columna.
	// Moure el quadrat cap a la dreta o l�esquerra si es pressionen les tecles de les fletxes corresponents,
	// comprovant que no ens passem dels limits del tauler.
	// Fer que cada segon baixi una fila, comprovant que no ens passem del limit inferior del tauler.



	// TODO 4: Imprimir text per pantalla
	//------------------------------------------
	// TODO 4.1: Mostrar la posici� actual del quadrat a dalt del tauler





	//TODO 5: Mostrar l�estat inicial del joc amb el tauler i la figura inicialitzats del fitxer
	//-----------------------------------------




}

