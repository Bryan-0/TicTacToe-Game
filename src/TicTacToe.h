#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <string>

class TicTacToe
{
	public:
		TicTacToe();
		
		void showBoard(char board[9]);
		void resetBoard(char board[9]);
				
		int placeMarker(int pos);
		
		bool isNotFree(int pos, char board[9]);
		bool checkXWin(char board[9]);
		bool checkOWin(char board[9]);
};

#endif
