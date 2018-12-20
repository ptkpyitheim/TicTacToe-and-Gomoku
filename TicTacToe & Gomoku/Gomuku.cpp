/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Date: 11/06/18
This Gomuku.cpp files implements definitions from Gomuku.h
*/

#include "stdafx.h"
#include "GomukuGame.h"
#include <iomanip>


//Constructor

GomukuGame::GomukuGame() {
	cout << "Welcome to the Ultimate Gomuku Game!" << endl;
	cout << endl;

	boardWidth = Gomuku_width;
	boardHeight = Gomuku_height;
	longest = 3;

	firstPlayer = 'B';
	secondPlayer = 'W';
	playerTurn = firstPlayer;
	playerOne = "Player B: ";
	playerTwo = "Player W: ";

	for (u_int i = starter_zero; i < Gomuku_width; i++) {			//initializing an empty game board
		for (int j = starter_zero; j < Gomuku_height; j++) {
			gomukuBoard[i][j] = ' ';
		}
	}

	ifstream TTTFile("Gomuku.txt");
	string l;
	if (TTTFile.is_open()) {
		getline(TTTFile, l);
	}
	else {
		cout << "Unable to open TTTFile" << endl;
		throw unable_to_open_file;
	}

	if (l == "NO DATA for Gomuku" || l == "") {
		numMoves = 0;
	}
	else {
		string pieces;char c; string moves;string turn;

		if (!getline(TTTFile, moves)) { throw unable_to_open_file; }

		while (getline(TTTFile, pieces)) {
			c = pieces[0];
			int y = int(pieces[1]);
			int x = int(pieces[2]);
			gomukuBoard[x][y] = c;
		}

		playerTurn = l.at(0);
		numMoves = int(moves.at(0));
	}


}


//Destructor

GomukuGame::~GomukuGame() {  }



//Insertion operator

ostream & operator<<(ostream & o, const GomukuGame & p)
{
	cout << " " << endl;

	for (u_int i = Gomuku_width; i > starter_zero; --i) {
		if (i - 1 < 10) {
			cout << " " << i - 1;
		}
		else {
			cout << i - 1;
		}

		for (int j = starter_zero; j < Gomuku_height; ++j) {
			cout << setw(p.longest) << p.gomukuBoard[i - 1][j];
		}
		cout << " " << endl;
	}

	cout << " X" << setw(p.longest - 1);
	for (u_int k = 0; k < Gomuku_width; k++) {
		cout << setw(p.longest) << k;

	}

	cout << endl;

	return o;
}



//Modifying the print function
void GomukuGame::print() {
	cout << *this << endl;
}



/* Helper methods below to check for the done() method */

//Checks left and right

bool GomukuGame::checkHorizonal(int i, int j) {
	int ct = 0;

	for (u_int a = i; a > zero; --a) {
		if (gomukuBoard[a][j] == gomukuBoard[a - 1][j]) {
			ct++;
		}
		else {
			break;
		}
	}

	if (ct == Gomuku_winning_moves - 1) {
		return true;
	}

	return false;
}



//Checks up and down

bool GomukuGame::checkVertical(int i, int j) {
	int ct = 0;

	for (u_int a = j; a > zero; --a) {
		if (gomukuBoard[i][a] == gomukuBoard[i][a - 1]) {
			ct++;
		}
		else {
			break;
		}
	}

	if (ct == Gomuku_winning_moves - 1) {
		return true;
	}

	return false;
}



//Checks down and left and Checks up and right

bool GomukuGame::checkDiagonal(int i, int j) {
	int ct = 0;

	while (i > starter_zero && i < Gomuku_width && j > starter_zero && j < Gomuku_height) {
		if (gomukuBoard[i][j] == gomukuBoard[i - 1][j - 1]) {
			i--;
			j--;
			ct++;
		}
		else {
			break;
		}
	}

	if (ct == Gomuku_winning_moves - 1) {
		cout << ct << endl;
		return true;
	}

	return false;
}



//Checks up and left and Checks down and right

bool GomukuGame::checkAntiDiagonal(int i, int j) {
	int ct = 0;

	while (i > starter_zero && i < Gomuku_width && j > starter_zero && j < Gomuku_height) {
		if (gomukuBoard[i][j] == gomukuBoard[i - 1][j + 1]) {
			i--;
			j++;
			ct++;
		}
		else {
			break;
		}
	}

	if (ct == Gomuku_winning_moves - 1) {
		cout << ct << endl;
		return true;
	}

	return false;
}



/* DONE() - returns true if 5 - Bs or Ws are in a vertical, horizontal or diagonal line; Uses helper methods above.
otherwise the method should return false. */

bool GomukuGame::done() {

	for (u_int i = starter_one; i < Gomuku_width - 1; ++i) {
		for (u_int j = starter_one; j < Gomuku_height - 1; ++j) {
			if (gomukuBoard[i][j] != ' ' && (checkHorizonal(i, j) || checkVertical(i, j) || checkDiagonal(i, j) || checkAntiDiagonal(i, j))) {
				return true;
			}
		}
	}
	return false;
}




//Helper method that is useful for draw method for cleaner code.

void GomukuGame::helperSetGamePiece(char c) {
	for (int i = starter_zero; i < Gomuku_width; i++) {
		for (int j = starter_zero; j < Gomuku_height; j++) {
			if (gomukuBoard[i][j] == ' ') {
				gomukuBoard[i][j] = c;
			}
		}
	}

}




/* DRAW() - Copy the current board and fill everything with B or W. Call done() method. If it's done() then you know there
are still more moves. If it's not done() then it's draw. */

bool GomukuGame::draw() {

	char copy_Gomuku_board[Gomuku_width][Gomuku_height];

	for (int i = starter_zero; i < Gomuku_width; i++) {
		for (int j = starter_zero; j < Gomuku_height; j++) {
			copy_Gomuku_board[i][j] = gomukuBoard[i][j];
		}
	}

	helperSetGamePiece('B');

	if (done()) {
		for (int i = starter_zero; i < Gomuku_width; i++) {
			for (int j = starter_zero; j < Gomuku_height; j++) {
				gomukuBoard[i][j] = copy_Gomuku_board[i][j];
			}
		}
		return false;
	}

	for (int i = starter_zero; i < Gomuku_width; i++) {
		for (int j = starter_zero; j < Gomuku_height; j++) {
			gomukuBoard[i][j] = copy_Gomuku_board[i][j];
		}
	}

	helperSetGamePiece('W');

	if (done()) {
		for (int i = starter_zero; i < Gomuku_width; i++) {
			for (int j = starter_zero; j < Gomuku_height; j++) {
				gomukuBoard[i][j] = copy_Gomuku_board[i][j];
			}
		}
		return false;
	}

	for (int i = starter_zero; i < Gomuku_width; i++) {
		for (int j = starter_zero; j < Gomuku_height; j++) {
			gomukuBoard[i][j] = copy_Gomuku_board[i][j];
		}
	}

	return true;
}




// PROMPT() - Prompts user input and check if it's valid. If not, specific error valuse are returned.

int GomukuGame::prompt(u_int & a, u_int & b) {

	string user_input;

	int message = gameStartMessage(user_input);
	if (message == user_quit) {
		int savedOrNot = save();
		if (savedOrNot == save_game_success) {
			cout << "File Saved Successfully.\n" << endl;
		}
		else if (savedOrNot == game_not_saved) {
			cout << "Game was not saved.\n" << endl;
		}
		return user_quit;
	}

	if (user_input.size() >= Gomuku_least_expected_argc && user_input.size() <= Gomuku_most_expected_argc) {

		if (isWellFormedCoordinate(user_input)) {

			istringstream extract(user_input);

			if (extract >> a, extract >> b) {
				if (isValidInput(a, b) && gomukuBoard[b][a] == ' ') {
					gomukuBoard[b][a] = playerTurn;
				}
				else {
					cout << "Your input is either out of range (or) somebody has already played the coordinate." << endl;
					cout << "Your x-coordinate and y-coordinate should be in-between 1 to 19 inclusive." << endl;
					return invalid_coordinates;
				}

			}
			else {
				cout << "Extraction error" << endl;
				return extraction_error;
			}
		}
		else {
			cout << "Please re-type. Your input should look something like '10,18'" << endl;
			return invalid_user_input;
		}
	}

	else {		//If user input size is not equal to 3-5

		cout << endl;
		cout << "Please re-type. Your input should look something like '10,5'" << endl;
		return 	user_input_out_of_range;

	}

	return user_success;
}



int GomukuGame::save() {
	string user_input;
	
	cout << "Do you want to save this game? Type 'y' for yes and 'n' for no: " << endl;
	cin >> user_input;
	ofstream gFile;

	if (user_input == "y") {
		gFile.open("Gomuku.txt");
		if (!gFile.is_open()) {
			return unable_to_open_file;
		}
		gFile << playerTurn << endl;
		gFile << numMoves << endl;

		for (int i = starter_zero; i < TTT_width; i++) {
			for (int j = starter_zero; j < TTT_height; j++) {
				if (gomukuBoard[j][i] == 'B' || gomukuBoard[j][i] == 'W') {
					gFile << gomukuBoard[j][i] << i << j << endl;
				}
			}
		}

		gFile.close();
		return save_game_success;
		gFile.close();
	}
	else if (user_input == "n") {
		gFile.open("Gomuku.txt");
		gFile << "NO DATA for Gomuku" << endl;
		gFile.close();
	}
	else {
		return invalid_save_user_response;
	}
}




/* **************************** END OF FILE ********************************* */