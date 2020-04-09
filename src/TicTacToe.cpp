#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe() {}

void TicTacToe::showBoard(char board[9]) {
	cout << "GAME BOARD: " << endl;
	cout << "                    " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "                    " << "--|" << "---" << "|--" << endl;
	cout << "                    " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "                    " << "--|" << "---" << "|--" << endl;
	cout << "                    " << board[0] << " | " << board[1] << " | " << board[2] << endl;
}

void TicTacToe::resetBoard(char board[9]) {
	board[0] = ' ';
	board[1] = ' ';
	board[2] = ' ';
	board[3] = ' ';
	board[4] = ' ';
	board[5] = ' ';
	board[6] = ' ';
	board[7] = ' ';
	board[8] = ' ';
}

int TicTacToe::placeMarker(int pos) {
	return pos;
}

bool TicTacToe::isNotFree(int pos, char board[9]) {
	if (board[pos - 1] == 'X' || board[pos - 1] == 'O') {
		return true;
	} else {
		return false;
	}
}

// Checks if X is aligned in a Horizontal, Vertical or Diagonal way.
bool TicTacToe::checkXWin(char board[9]) {
	return (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
	|| (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
	|| (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[6] == 'X' && board[4] == 'X' && board[2] == 'X');
}

// Checks if O is aligned in a Horizontal, Vertical or Diagonal way.
bool TicTacToe::checkOWin(char board[9]) {
	return (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
	|| (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
	|| (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') || (board[6] == 'O' && board[4] == 'O' && board[2] == 'O');
}
