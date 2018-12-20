
/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Date: 11/06/18
This TicTacToeGame.cpp implements all the methods from the TicTacToeGame.h header file.
*/


#include "stdafx.h"
#include "TicTacToeGame.h"
#include <string>



//Constructor
TicTacToeGame::TicTacToeGame() {

	boardWidth = TTT_width;
	boardHeight = TTT_height;
	longest = 2;

	playerOne = "Player X: ";
	playerTwo = "Player O: ";

	cout << "Welcome to the Ultimate Tic Tac Toe Game!" << endl;
	cout << endl;

	for (int i = starter_zero; i < TTT_width; i++) {			//initializing an empty game board
		for (int j = starter_zero; j < TTT_height; j++) {
			board[i][j] = ' ';
		}
	}


	ifstream TTTFile("TicTacToe.txt");
	string l;
	if (TTTFile.is_open()) {
		getline(TTTFile, l);
	}
	else {
		cout << "Unable to open TTTFile" << endl;
		throw unable_to_open_file;
	}

	if (l == "NO DATA for TicTacToe" || l == "") {
		firstPlayer = 'X';
		secondPlayer = 'O';
		playerTurn = firstPlayer;
		numMoves = 0;
	}
	else {
		string pieces;char c; string moves;string turn;
	
		if (!getline(TTTFile, moves)) { throw unable_to_open_file; }

		while (getline(TTTFile, pieces)) {
			c = pieces[0];
			int y = int(pieces[1]);
			int x = int(pieces[2]);
			board[x][y] = c;
		}

		playerTurn = l.at(0);
		numMoves = int(moves.at(0));
	}

}



//Destructor
TicTacToeGame::~TicTacToeGame() { }



//Insertion operatpr
ostream & operator<<(ostream & o, const TicTacToeGame &p) {

	for (int i = TTT_width; i > starter_zero; --i) {
		cout << setw(p.longest) << i - 1;
		for (int j = starter_zero; j < TTT_width; ++j) {
			cout << setw(p.longest) << p.board[i - 1][j];
		}
		cout << endl;
	}

	cout << setw(p.longest + 2);

	for (int i = starter_zero; i < TTT_width; ++i) {
		cout << i << setw(p.longest);
	}

	cout << setw(p.longest) << endl;

	return o;
}



//Modifying print function
void TicTacToeGame::print() {
	cout << *this << endl;
}



/* DONE() - returns true if 3 - Xs or Os are in a vertical, horizontal or diagonal line;
otherwise the method should return false. */

bool TicTacToeGame::done() {

	for (u_int i = one; i < four; ++i) {
		bool rows = board[i][one] == board[i][two] && board[i][two] == board[i][three] && board[i][one] != ' ';
		bool cols = board[one][i] == board[two][i] && board[three][i] == board[two][i] && board[one][i] != ' ';
		if (rows || cols) {
			return true;
		}
	}

	bool diagonal1 = board[one][one] == board[two][two] && board[two][two] == board[three][three] && board[one][one] != ' ';
	bool diagonal2 = board[one][three] == board[two][two] && board[two][two] == board[three][one] && board[one][three] != ' ';

	if (diagonal1 || diagonal2) {
		return true;
	}

	return false;
}




/* DRAW() - returns true if the game is draw (i.e. no move valid moves or if the game is done);
otherwise, returns false. */

bool TicTacToeGame::draw() {

	if (done() || numMoves == TTT_total_moves_available) {
		return true;
	}

	return false;
}




// PROMPT() - Prompts user input and check if it's valid. If not, specific error valuse are returned.

int TicTacToeGame::prompt(u_int & a, u_int & b) {

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

	if (user_input.size() == TTT_expected_argc) {

		if (isWellFormedCoordinate(user_input)) {

			istringstream extract(user_input);

			if (extract >> a, extract >> b) {
				if (isValidInput(a, b) && board[b][a] == ' ') {
					board[b][a] = playerTurn;
				}
				else {
					cout << "Your input is either out of range (or) somebody has already played the coordinate." << endl;
					cout << "Your x-coordinate and y-coordinate should be in-between 1 to 3 inclusive." << endl;
					return invalid_coordinates;
				}

			}
			else {
				return extraction_error;
			}
		}
		else {
			cout << "Please re-type. Your input should look something like '2,2'." << endl;
			return invalid_user_input;
		}
	}

	else {		//If user input is not equal to 3

		cout << endl;
		cout << "Please re-type. Your input should look something like '1,1'." << endl;
		return 	user_input_out_of_range;

	}

	return user_success;
}


int TicTacToeGame::save() {
	string user_input;

	cout << "Do you want to save this game? Type 'y' for yes and 'n' for no: " << endl;
	cin >> user_input;
	ofstream gFile;

	if (user_input == "y") {
		gFile.open("TicTacToe.txt");
		if (!gFile.is_open()) {
			return unable_to_open_file;
		}
		gFile << playerTurn << endl;
		gFile << numMoves << endl;

		for (int i = starter_zero; i < TTT_width; i++) {
			for (int j = starter_zero; j < TTT_height; j++) {
				if (board[j][i] == 'X' || board[j][i] == 'O') {
					gFile << board[j][i] << i <<  j << endl;
				}
			}
		}
		
		gFile.close();
		return save_game_success;
	}
	else if (user_input == "n") {
		gFile.open("TicTacToe.txt");
		gFile << "NO DATA for TicTacToe" << endl;
		gFile.close();
		return game_not_saved;
	}
	else {
		return invalid_save_user_response;
	}
}



/* **************************** END OF FILE ********************************* */