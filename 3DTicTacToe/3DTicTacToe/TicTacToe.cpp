#include<iostream>
#include "GameBoard.h"
#include"TicTacToe.h"
using namespace std;
void TicTacToe::playGame()
{
	PlayerTrun currentPlayer = FIRST_PLAYER;
	GameBoard game;
	int position;
	char player1Character, player2Character;
	cout << "Enter Player 1 Symbol: ";
	cin >> player1Character;
	do
	{
		cout << "Enter Player 2 Symbol: ";
		cin >> player2Character;
	} while (player2Character == player1Character);
	while (game.getGameStatus() == IN_PROGRESS)
	{
		for (int i = 1; i <= 2; i = i + 1)
		{
			game.displayBoard();
			cout << "Player " << i << " Turn: Enter Cell #: ";
			cin >> position;
			while (game.isValidPosition(position) == false || game.isAlreadyMarked(position) == true)
			{
				cout << "Invalid Position\n";
				game.displayBoard();
				cout << "Player " << i << " Turn: Enter Cell #: ";
				cin >> position;
			}
			if (i == 1)
			{
				game.markBoard(position, player1Character);
				currentPlayer = FIRST_PLAYER;
			}
			if (i == 2)
			{
				game.markBoard(position, player2Character);
				currentPlayer = SECOND_PLAYER;
			}
			if (game.isWin() == true)
			{
				game.displayBoard();
				game.setGameStatus(WIN);
				break;
			}
			if (game.getValidMovesCount() == 27)
			{
				game.displayBoard();
				game.setGameStatus(DRAW);
				break;
			}
		}
	}
	if (game.getGameStatus() == WIN)
	{
		cout << "Game Won by Player: " << currentPlayer << endl;
	}
	if (game.getGameStatus() == DRAW)
	{
		cout << "Game Is Drawn." << endl;
	}
}