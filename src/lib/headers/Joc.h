#pragma once

#include <iostream>
#include "Tauler.h"

using namespace std;

class Joc
{
 public:
	Joc() = default;

	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
 private:
	Tauler m_board;
	Figura m_shape;
};
