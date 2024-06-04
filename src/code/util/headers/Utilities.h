#pragma once

#include "../../logic/headers/Figura.h"
#include "../../logic/headers/Tetris.h"
#include "ShapeQueue.h"
#include "MovementQueue.h"
#include <fstream>

typedef struct
{
	int minX;
	int minY;
	int maxX;
	int maxY;
} BoxBounds;

// Matrix transformations
void invertRows(int** matrix, int rows, int columns);
void invertColumns(int** matrix, int rows, int columns);
void transposeMatrix(int** matrix, int rows, int columns);

// Serialization-Deserialization
Figura readShapeData(const int* shapeData);
void serializeHighScore(const vector<HighScore>& scores);

ShapeQueue deserializeShapes(const string& shapeFile);
MovementQueue deserializeMoves(const string& movementFile);
HighScore deserializeHighScore(const string& line);
void deserializeHighScores(vector<HighScore>& scores);

void deserializeShapeData(int* shapeData, string& currentLine);
void deserializeMatrixData(int** tmpBoardMatrix, int& rowIndex, const string& currentLine);

// Other operations
int** initNewMatrix(int columns, int rows);
Figura generateRandomShape();
double calculateTimeMultiplier(double currentMultiplier);
void bubbleSort(vector<HighScore>& vectorToSort);

void clearCinBuffer();
bool wasBoxClicked(BoxBounds bounds, int clickedX, int clickedY);
