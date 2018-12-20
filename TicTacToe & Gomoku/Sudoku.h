#pragma once

#include "GameBase.h"
#include <vector>

class SudokuGame: public GameBase {
	friend ostream& operator<<(ostream & o, const SudokuGame &s);
public:
	SudokuGame();
	~SudokuGame();
	virtual void print() override;
	virtual bool done();
	virtual int prompt(u_int & a, u_int & b);
	virtual bool draw();
	virtual int save() override;
	int readFile(string file);
	int isPlaceholder(u_int i);

private:
	vector<char> sudokuBoard;
	vector<u_int> placeholder;

};
