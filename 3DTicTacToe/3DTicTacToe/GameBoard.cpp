#include "GameBoard.h"
GameBoard::GameBoard()
{
	char ch;

	for (int i = 0; i < 3; i++)
	{
		ch = '1';
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				data[i][j][k] = ch;
				ch++;
			}
		}
	}
}
void GameBoard::displayBoard()
{
	cout << "\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << data[k][i][j] << " ";
			}
			cout << "\t";
		}
		cout << endl;
	}
	cout << "\n\n";
}
void GameBoard::markBoard(int pos, char playerSymbol)
{
	int p = pos % 10;
	data[(pos / 10) - 1][(p - 1) / 3][(p - 1) % 3] = playerSymbol;
	validMovesCount = validMovesCount + 1;
}
bool GameBoard::isValidPosition(int pos)
{
	if (pos >= 11 && pos <= 39 && pos % 10 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GameBoard::isAlreadyMarked(int pos)
{
	int p = pos % 10;
	if (data[(pos / 10) - 1][(p - 1) / 3][(p - 1) % 3] != (p + 48))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GameBoard::rowWise()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (data[i][j][0] == data[i][j][1] && data[i][j][1] == data[i][j][2])
			{
				return true;
			}
		}
	}
	return false;
}
bool GameBoard::colWise()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (data[i][0][j] == data[i][1][j] && data[i][1][j] == data[i][2][j])
			{
				return true;
			}
		}
	}
	return false;
}
bool GameBoard::diagonalWise()
{
	for (int i = 0; i < 3; i++)
	{
		if (data[i][0][0] == data[i][1][1] && data[i][1][1] == data[i][2][2])
		{
			return true;
		}
		if (data[i][0][2] == data[i][1][1] && data[i][1][1] == data[i][2][0])
		{
			return true;
		}
	}
	return false;
}
bool GameBoard::widthWise()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (data[0][i][j] == data[1][i][j] && data[1][i][j] == data[2][i][j] && data[0][i][j] != ((i * 3) + 1 + j + 48))
			{
				return true;
			}
		}
	}
	return false;
}
bool GameBoard::squareDiagonal()
{
	if (data[0][0][0] == data[1][1][1] && data[1][1][1] == data[2][2][2])
	{
		return true;
	}
	if (data[0][2][0] == data[1][1][1] && data[1][1][1] == data[2][0][2])
	{
		return true;
	}
	if (data[0][0][2] == data[1][1][1] && data[1][1][1] == data[2][2][0])
	{
		return true;
	}
	if (data[0][2][2] == data[1][1][1] && data[1][1][1] == data[2][0][0])
	{
		return true;
	}
	return false;
}
bool GameBoard::isWin()
{
	if (diagonalWise() || rowWise() || colWise() || widthWise() || squareDiagonal())
	{
		return true;
	}
	return false;
}
int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}
void GameBoard::setGameStatus(GameStatus currentStatus)
{
	gameStatus = currentStatus;
}
GameStatus GameBoard::getGameStatus()
{
	return gameStatus;
}