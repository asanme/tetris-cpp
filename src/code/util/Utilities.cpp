#include "headers/Utilities.h"
#include <random>

const double MAX_TIME_MULTIPLIER = 0.0000000000000000000000000000000000000000000000000000000000001;

void invertRows(int** matrix, int rows, int columns)
{
	for (int j = 0; j < columns; ++j)
	{
		for (int i = 0; i < rows / 2; ++i)
		{
			int tmp = matrix[i][j];
			int rowIndex = rows - 1 - i;
			matrix[i][j] = matrix[rowIndex][j];
			matrix[rowIndex][j] = tmp;
		}
	}
}

Figura readShapeData(const int* shapeData)
{
	Figura currentShape;
	TipusFigura tipusFigura = static_cast<TipusFigura>(shapeData[0]);
	int yPos = shapeData[1] - 1;
	int xPos = shapeData[2] - 1;
	int rotationIndex = shapeData[3];

	currentShape.setShape(tipusFigura);
	currentShape.setYBoardPosition(yPos);
	currentShape.setXBoardPosition(xPos);

	for (int i = 0; i < rotationIndex; i++)
		currentShape.rotateShape(GIR_HORARI);

	return currentShape;
}

ShapeQueue deserializeShapes(const string& shapeFile)
{
	ShapeQueue shapeQueue;
	ifstream shapesFile;

	shapesFile.open(shapeFile);
	if (shapesFile.is_open())
	{
		string currentLine;

		while (getline(shapesFile, currentLine))
		{
			int shapeData[4];
			deserializeShapeData(shapeData, currentLine);
			Figura currentShape = readShapeData(shapeData);
			shapeQueue.push(currentShape);
		}
	}

	shapesFile.close();
	return shapeQueue;
}

MovementQueue deserializeMoves(const string& movementFile)
{
	ifstream movesFile;
	MovementQueue movementQueue;

	movesFile.open(movementFile);
	if (movesFile.is_open())
	{
		char movement;
		while (movesFile >> movement)
		{
			if (isdigit(movement))
			{
				int movementValue = movement - '0';
				movementQueue.push(static_cast<TipusMoviment>(movementValue ));
			}
		}
	}

	movesFile.close();
	return movementQueue;
}

void invertColumns(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns / 2; ++j)
		{
			int tmp = matrix[i][j];
			int columnIndex = columns - 1 - j;
			matrix[i][j] = matrix[i][columnIndex];
			matrix[i][columnIndex] = tmp;
		}
	}
}

void transposeMatrix(int** matrix, int rows, int columns)
{
	int matrixCopy[rows][columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixCopy[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = matrixCopy[j][i];
		}
	}
}

int** initNewMatrix(int columns, int rows)
{
	int** newMatrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		newMatrix[i] = new int[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			newMatrix[i][j] = 0;

	return newMatrix;
}

void deserializeShapeData(int* shapeData, string& currentLine)
{
	int dataIndex = 0;

	for (char c : currentLine)
	{
		if (isdigit(c))
		{
			int currentValue = c - '0';
			shapeData[dataIndex] = currentValue;
			++dataIndex;
		}
	}
}

void deserializeMatrixData(int** tmpBoardMatrix, int& rowIndex, const string& currentLine)
{
	int matrixColumnIndex = 0;

	for (char c : currentLine)
	{
		if (isdigit(c))
		{
			int currentMatrixValue = c - '0';
			tmpBoardMatrix[rowIndex][matrixColumnIndex] = currentMatrixValue;
			++matrixColumnIndex;
		}
	}

	++rowIndex;
}

static bool isValidPlacement(int nColumns, int xPosition)
{
	return ((nColumns + xPosition) - 1) < N_COL_TAULER;
}

Figura generateRandomShape()
{
	Figura randomizedShape;
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> rotationDistribution(0, 3);
	std::uniform_int_distribution<> shapeDistribution(1, N_TIPUS_FIGURES);
	std::uniform_int_distribution<> columnDistribution(0, N_COL_TAULER - 1);

	int randomColumn;
	int randomShape = shapeDistribution(gen);
	int randomRotation = rotationDistribution(gen);

	randomizedShape.setShape(static_cast<TipusFigura>(randomShape));
	int nColumns = randomizedShape.getColumns();

	for (int i = 0; i < randomRotation; i++)
		randomizedShape.rotateShape(GIR_HORARI);

	do
	{
		randomColumn = columnDistribution(gen);
	} while (!isValidPlacement(nColumns, randomColumn));

	randomizedShape.setXBoardPosition(randomColumn);

	// Debug
	/*
	std::cout << "----  Generated Shape ----" << "\n";
	std::cout << "columnIndex: " << randomColumn << "\n";
	std::cout << "shapeIndex: " << randomShape << "\n";
	std::cout << "nColumns: " << randomizedShape.getColumns() << "\n";
	std::cout << "--------------------------" << "\n";
	*/

	return randomizedShape;
}

double calculateTimeMultiplier(double currentMultiplier)
{
	currentMultiplier = currentMultiplier - (currentMultiplier / 4);
	if (currentMultiplier < MAX_TIME_MULTIPLIER)
		currentMultiplier = MAX_TIME_MULTIPLIER;

	return currentMultiplier;
}

void serializeHighScore(const vector<HighScore>& scores)
{
	ofstream highScores;
	highScores.open("../highscores/highscores.txt");

	if (highScores.is_open())
	{
		for (int i = 0; i < scores.size(); i++)
		{
			HighScore currentScore = scores[i];
			string output = currentScore.name + ";" + to_string(currentScore.score) + "\n";
			highScores << output;
		}
	}

	highScores.close();
}

HighScore deserializeHighScore(const string& line)
{
	HighScore currentHighScore;
	bool hasReachedSeparator = false;
	string scoreText;
	string name;
	int score;

	for (char c : line)
	{
		if (c != ';')
		{
			if (!hasReachedSeparator)
			{
				name += c;
			}
			else
			{
				if (isdigit(c))
					scoreText += c;
			}
		}
		else
			hasReachedSeparator = true;
	}

	score = stoi(scoreText);
	currentHighScore.name = name;
	currentHighScore.score = score;
	return currentHighScore;
}

void deserializeHighScores(vector<HighScore>& scores)
{
	scores.clear();
	ifstream highScores;
	highScores.open("../highscores/highscores.txt");

	if (highScores.is_open())
	{
		string currentLine;
		while (getline(highScores, currentLine))
		{
			HighScore currentScore = deserializeHighScore(currentLine);
			scores.push_back(currentScore);
		}
	}

	highScores.close();
}

void bubbleSort(vector<HighScore>& vectorToSort)
{
	int positionsToSort = vectorToSort.size();

	while (positionsToSort != 0)
	{
		for (int i = 1; i < positionsToSort; ++i)
		{
			int j = i - 1;
			if (vectorToSort[j].score < vectorToSort[i].score)
			{
				// Swap elements
				HighScore tmpScore = vectorToSort[i];
				vectorToSort[i] = vectorToSort[j];
				vectorToSort[j] = tmpScore;
			}
		}
		--positionsToSort;
	}
}

void clearCinBuffer()
{
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool wasBoxClicked(BoxBounds bounds, int clickedX, int clickedY)
{
	bool wasBoxClicked = false;

	if (clickedX >= bounds.minX && clickedX <= bounds.maxX && clickedY >= bounds.minY && clickedY <= bounds.maxY)
		wasBoxClicked = true;

	return wasBoxClicked;
}
