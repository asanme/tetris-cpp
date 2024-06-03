#pragma once

#include "../../logic/headers/Figura.h"
#include "ShapeQueue.h"
#include "MovementQueue.h"
#include <fstream>

// Matrix transformations
void invertRows(int** matrix, int rows, int columns);
void invertColumns(int** matrix, int rows, int columns);
void transposeMatrix(int** matrix, int rows, int columns);

// Serialization-Deserialization
Figura readShapeData(const int* shapeData);
ShapeQueue deserializeShapes(const string& fitxerFigures);
MovementQueue deserializeMoves(const string& fitxerMoviments);

void deserializeShapeData(int* shapeData, string& currentLine);
void deserializeMatrixData(int** tmpBoardMatrix, int& rowIndex, const string& currentLine);

// Other operations
int** initNewMatrix(int columns, int rows);
Figura generateRandomShape();
double calculateTimeMultiplier(double currentMultiplier);
