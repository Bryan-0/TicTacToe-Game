#include <iostream>
#include <string>
#include "TicTacToe.h"

using namespace std;

void Intro() {
	cout << "Welcome to TicTacToe! in C++" << endl;
	cout << "Player 1: X and Player 2: O" << endl;
	cout << "GameBoard is going to be like numpad: " << endl;
	cout << "7  --  8  --  9" << endl;
	cout << "4  --  5  --  6" << endl;
	cout << "1  --  2  --  3" << endl;
	cout << " " << endl;
	cout << "Input the position you want to place! (numpad positions example above)" << endl;
	cout << " " << endl;
}

int main() {
	Intro();
	char gameBoard[9]= {
	' ', ' ', ' ',
	' ', ' ', ' ',
	' ', ' ', ' '
	};
	
	TicTacToe gameManager;
	gameManager.showBoard(gameBoard);
	
	// Game vars
	
	int firstPlayer, secondPlayer, xWins = 0, oWins = 0;
	
	// Turns Logic:
	// Every even number, Player 1 will move.
	// Every odd number, Player 2 will move.
	int turnCounter = 0;
	
	// Main Game Loop:
	while (true) {
		
		if (turnCounter % 2 == 0) {
			cout << "X Player Turn!" << endl;
			cout << "Choose position to place X: " << endl;
			cout << "Pos: " << endl;
			cin >> firstPlayer;
			
			// Check if there is a free spot to place your marker
			if (gameManager.isNotFree(firstPlayer, gameBoard)) {
				cout << "That position is already taken!" << endl;
				continue;
			}
			
			// Update board for 'X'
			gameBoard[gameManager.placeMarker(firstPlayer) - 1] = 'X';
			gameManager.showBoard(gameBoard);
			
			// Check if there is a winner
			if (gameManager.checkXWin(gameBoard)) {
				cout << "X WINS!" << endl;
				xWins += 1;
				
				int playAgain;
				cout << "Do you want to play again? (1 for yes) (0 for no)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					turnCounter = 0;
					
					// Each Game Board index = ' '
					gameManager.resetBoard(gameBoard);
					gameManager.showBoard(gameBoard);
					cout << "X Wins: " << xWins  <<  " ||| " << " O Wins: " << oWins << endl;
					continue;
				} else {
					cout << "Thanks for playing!" << endl;
					cout << "Developed by Brayan Ayala in C++" << endl;
					break;
				}
			}
			
		} else if (turnCounter % 2 != 0) {
			cout << "O Player Turn!" << endl;
			cout << "Choose position to place O: " << endl;
			cout << "Pos: " << endl;
			cin >> secondPlayer;
			
			// Check if there is a free spot to place your marker
			if (gameManager.isNotFree(secondPlayer, gameBoard)) {
				cout << "That position is already taken!" << endl;
				continue;
			}
			
			// Update board for 'O'
			gameBoard[gameManager.placeMarker(secondPlayer) - 1] = 'O';
			gameManager.showBoard(gameBoard);
			
			// Check if there is a winner
			if (gameManager.checkOWin(gameBoard)) {
				cout << "O WINS!" << endl;
				oWins += 1;
				
				int playAgain;
				cout << "Do you want to play again? (1 for yes) (0 for no)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					turnCounter = 0;
					// Each game Board index = ' '
					gameManager.resetBoard(gameBoard);
					gameManager.showBoard(gameBoard);
					cout << "X Wins: " << xWins << " ||| " << " O Wins: " << oWins << endl;
					continue;
				} else {
					cout << "X Wins: " << xWins << " ||| " << " O Wins: " << oWins << endl;
					cout << "Thanks for playing!" << endl;
					cout << "Developed by Brayan Ayala in C++" << endl;
					break;
				}
				
			}
		}
		
		turnCounter += 1;
		
	}
}
