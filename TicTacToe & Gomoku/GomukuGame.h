/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Date: 11/06/18
This Gomuku.h defines methods and member variables.
*/

#pragma once

#include <iostream>
#include "GameBase.h"
#include "Enumerations.h"
#include <sstream>
#include <iomanip>
#include <ostream>
#include <fstream>

using namespace std;


class GomukuGame : public GameBase {
	friend ostream& operator<<(ostream & o, const GomukuGame &p);

public:
	GomukuGame();
	~GomukuGame();
	virtual void print() override;
	virtual bool done();
	virtual bool draw();

	virtual int prompt(u_int & a, u_int & b) override;

	bool checkHorizonal(int i, int j);
	bool checkVertical(int i, int j);
	bool checkDiagonal(int i, int j);
	bool checkAntiDiagonal(int i, int j);

	void helperSetGamePiece(char c);
	
	virtual int save() override;

private:
	char gomukuBoard[Gomuku_width][Gomuku_height];

};


/* **************************** END OF FILE ********************************* */
