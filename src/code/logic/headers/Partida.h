#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"

using namespace std;

class Partida 
{
public:
    Partida();
    
    void actualitza(double deltaTime);
private:
    double m_temps;
    // Atributs necessaris nom�s pels exemples d'utilitzaci� de la llibreria. 
    // S'hauran d'eliminar per la implementaci del projecte
    static const int MIDA = 4;
    ColorFigura m_forma[MIDA][MIDA];
    int m_fila, m_columna;
};

#endif 
