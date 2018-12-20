#include "stdafx.h"
#include "Sudoku.h"

SudokuGame::SudokuGame() {
	boardWidth = Sudoku_width;
	boardHeight = Sudoku_height;

	for (u_int i = 0; i < Sudoku_width*Sudoku_height; ++i) {    //initialize an empty game board.
		sudokuBoard.push_back(' ');
	}

	//Try to load the potential saved file first.
	//int isSaved = readFile("Sudoku.txt");
	//if (isSaved == game_not_saved) {
	//	cout << "Game was not saved before. Here's a new game for you." << endl;
	//	readFile("sudoku0.txt");
	//}

}


ostream & operator<<(ostream & o, const SudokuGame & s) {

	vector<char> sudokuBoard = s.sudokuBoard;

	for (int r = Sudoku_width - 1; r >= -1; --r) {
		if ((r == -1) || (r == 2) || (r == 5)) {
			o << "==||===|===|===||===|===|===||===|===|===||" << endl;
		}
		else {
			o << "--||---|---|---||---|---|---||---|---|---||" << endl;
		}
		for (int c = -1; c < Sudoku_height; ++c) {

			// if in the -1 row or column, print markers
			if ((r == -1) && (c == -1)) {
				o << "  ";
			}
			else if (r == -1) {
				o << c << " ";
			}
			else if (c == -1) {
				o << r << " ";
			}
			else {
				// print each character plus needed white space
				char display = sudokuBoard[Sudoku_height*r + c];
				o << display << " ";
			}
			if ((c == -1) || (c == 2) || (c == 5) || (c == 8)) {
				o << "|| ";
			}
			else {
				o << "| ";
			}
		}
		o << endl; // print a new line at the end of every row
	}
	return o;
}

//Destructor

SudokuGame::~SudokuGame() {  }

void SudokuGame::print() {
	cout << *this << endl;
}

bool SudokuGame::done() {
	return false;
}


int SudokuGame::prompt(u_int & a, u_int & b)
{
	return 0;
}

bool SudokuGame::draw() {
	return false;
}


int SudokuGame::save() {
	string user_input;

	cout << "Do you want to save this game? Type 'y' for yes and 'n' for no: " << endl;
	cin >> user_input;
	ofstream sFile;

	if (user_input == "y") {
		string eachLine; char pieces; int w = Sudoku_width - 1; int h = 0;

		sFile.open("Sudoku.txt");
		while (w != -1) {
			//h = 0;
			while (h != Sudoku_height) {
				pieces = sudokuBoard[Sudoku_width*w + h];
				if (isPlaceholder(Sudoku_width*w + h)) {
					sFile << "/" << pieces << " ";
				}
				else if (pieces == ' ') {
					sFile << "0 ";
				}
				else {
					sFile << pieces << " ";
				}
				h += 1;
			}
		}
		if (w >= 0) {
			sFile << endl;
		}
		w -= 1;

		sFile.close();
		return save_game_success;
	}
	else if (user_input == "n") {
		sFile.open("Sudoku.txt");
		sFile << "NO DATA for Sudoku" << endl;
		sFile.close();
		return game_not_saved;
	}
	else {
		return invalid_save_user_response;
	}

}

int SudokuGame::readFile(string file) {  //Reading saved file method for code flexibility
	ifstream sudokuFile(file);

	if (!sudokuFile.is_open()) {
		return unable_to_open_file;
	}
	string eachLine; int pieces; int w = Sudoku_width - 1; int h = 0;

	while (getline(sudokuFile, eachLine)) {
		h = 0;
		if (eachLine == "NO DATA for Sudoku") {
			return game_not_saved;
		}
		istringstream stream(eachLine);
		while (stream >> pieces) {
			if (h > Sudoku_height) {
				return invalid_saved_file;
			}

			if (pieces > 0) {
				sudokuBoard[Sudoku_width * w + h] = char(pieces * -1);
				//place pieces into placeholder if found
				placeholder.push_back(Sudoku_width* w + h);
			}
			else if (pieces < 0) {
				sudokuBoard[Sudoku_width * w + h] = char(pieces);
			}
			else if (pieces < 0 && file == "sudoku0.txt") {
				sudokuBoard[Sudoku_width * w + h] = ' ';
			}
			h += 1;
		}
		w -= 1;
	}
	if (w != -1) {
		cout << "Invalid rows from Sudoku File." << endl;
		return invalid_row_read;
	}
	

}

int SudokuGame::isPlaceholder(u_int i) {
	for (u_int j = 0; j < placeholder.size(); ++j) {
		if (i == placeholder[j]) {
			return is_placeholder;
		}
	}
	return is_not_placeholder;
}


