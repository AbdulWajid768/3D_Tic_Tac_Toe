#include<iostream>
using namespace std;
enum PlayerTrun { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
enum GameStatus { DRAW, WIN, IN_PROGRESS };
class GameBoard
{
private:
	char data[3][3][3];
	GameStatus gameStatus = IN_PROGRESS;
	int validMovesCount = 0;
	bool rowWise();
	bool colWise();
	bool diagonalWise();
	bool widthWise();
	bool squareDiagonal();
public:
	GameBoard();
	void displayBoard();
	void markBoard(int pos, char playerSymbol);
	bool isValidPosition(int pos);
	bool isAlreadyMarked(int pos);
	bool isWin();
	int getValidMovesCount();
	void setGameStatus(GameStatus currentStatus);
	GameStatus getGameStatus();
};