/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Date: 11/06/1
This GameBase.h defines declarations for GameBase.cpp file.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <memory>
#include "Enumerations.h"
#include <ostream>
#include <fstream>

using namespace std;

typedef unsigned int u_int;


/*** Game Base Class DECLARATION BELOW *** */

class GameBase {
	friend ostream& operator<<(ostream & o, const GameBase & p);

public:
	GameBase();
	~GameBase();
	static shared_ptr<GameBase> instance();
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn();
	int play();
	int gameStartMessage(string &user_input);
	virtual int prompt(u_int & a, u_int & b) = 0;
	static void arguments(int no_of_args, char* c[]);
	virtual bool isValidInput(u_int a, u_int b);		//Helper method to check valid moves
	bool isWellFormedCoordinate(string &str);			//Helper method
	virtual int save() = 0;

protected:
	static shared_ptr<GameBase> gb;
	int boardWidth;
	int boardHeight;
	string game_type;				//Will keep track if the game is TicTacToe or Gomuku or Sudoku
	int longest;					//display character length for insertion operators
	char playerTurn;				//Holds 'X' and 'O' or 'B' or 'W' Will alternate in turn() method.
	int numMoves;					//Keeping track of total number of moves both players made

	char firstPlayer;				//X for TicTacToe and B for Gomuku
	char secondPlayer;				//O for TicTacToe and W for Gomuku

	string playerOne;				//Printing out for turn method
	string playerTwo;				//Printing out for turn method
};



/* **************************** END OF FILE ********************************* */
