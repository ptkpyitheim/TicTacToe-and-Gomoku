/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Date: 11/06/18
This TicTacToeGame.h declares all methods for TicTacToeGame.cpp file.
*/

#pragma once

#include "GameBase.h"
#include "Enumerations.h"
#include <iomanip>
#include <vector>


class TicTacToeGame : public GameBase {
	friend ostream& operator<<(ostream & o, const TicTacToeGame & p);

public:
	TicTacToeGame();
	~TicTacToeGame();
	virtual void print() override;
	virtual bool done();
	virtual bool draw();
	virtual int prompt(u_int & a, u_int & b) override;
	virtual int save() override;

private:
	char board[TTT_width][TTT_height];

};

/* **************************** END OF FILE ********************************* */

