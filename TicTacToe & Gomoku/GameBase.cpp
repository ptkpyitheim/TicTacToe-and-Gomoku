
/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Date: 11/06/18
This GameBase.cpp implements all the methods from the GameBsae.h header file.
*/

#include "stdafx.h"
#include "GameBase.h"
#include "GomukuGame.h"
#include "TicTacToeGame.h"
#include "Sudoku.h"


GameBase::GameBase() {  }

GameBase::~GameBase() { }

shared_ptr<GameBase> GameBase::instance() {
	try {
		if (gb != nullptr) {
			return gb;
		}
	}
	catch (exception &e) {
		cout << "Exception caught: " << e.what() << endl;
		throw "Nullpointer exception for static instance variable.";
	}

}

ostream & operator<<(ostream & o, const GameBase & p) { return o; }


shared_ptr<GameBase> GameBase::gb = nullptr;


//gameStartMessage() - A helper method to call in prompt to print out common messages when game starts. 

int GameBase::gameStartMessage(string &user_input) {

	cout << "Type in a valid coordinate to play. (E.g. 2,2)" << endl;
	cout << "   Type 'quit' to end the game." << endl;
	cout << endl;
	cout << "This is player " << playerTurn << " turn." << endl;
	cout << endl;
	cout << "Please enter a command: ";

	getline(cin, user_input);

	cout << "   ********************************************* " << endl;

	if (user_input == "quit") {
		return user_quit;
	}

	return user_success;
}



//Takes in a string as a parameter to change the characters to lower case.

string changeToLowerCase(string &s) {

	for (u_int i = starter_zero; i < s.length(); i++) {
		if (s[i] < lower_case_a) {
			s[i] = s[i] + difference_between_upper_lower;
		}
	}
	return s;

}



/* ISVALIDINPUT() - Helper method that checks if user input is valid. Takes in two parameter of x and y coordinates.
Returns true if it's valid. Otherwise, false.  */

bool GameBase::isValidInput(u_int x, u_int y) {


	string TTT = "TicTacToe";
	string Go = "Gomuku";

	if (game_type == TTT || game_type == changeToLowerCase(TTT)) {
		if (x < one || x > three || y < one || y > three) {
			return false;
		}
	}
	else if (game_type == Go || game_type == changeToLowerCase(Go)) {
		if (x < one || x > 19 || y < one || y > 19) {
			return false;
		}
	}
	else {
		cout << "Incorrect game type" << endl;
		return false;
	}
	return true;
}



/*isWellFormedCoordinate() - Checks if user inputs correct and well formed cooridnates for both games. Replaces ',' with ' '.
Method returns false otherwise.	  */

bool GameBase::isWellFormedCoordinate(string &str) {
	int non_digits = 0;
	for (u_int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			non_digits++;
			if (non_digits > 1) {
				return false;
			}
		}
		if (str[i] == ',') {
			str[i] = ' ';
		}
	}

	return true;
}



// arguments() - takes in two arguments for the command line prompt and allocates new objects for specified games.

void GameBase::arguments(int no_of_args, char* c[]) {

	try {
		if (gb == nullptr) {
			shared_ptr<GameBase> current_game;

			string game(c[game_name]);

			string TTT = "TicTacToe";
			string Go = "Gomuku";
			string Su = "Sudoku";

			if (game == TTT || game == changeToLowerCase(TTT)) {
				try {
					current_game = make_shared<TicTacToeGame>();
					gb = current_game;
					gb->game_type = game;
				}
				catch (bad_alloc ba) {
					throw ba;
				}
				
			}
			else if (game == Go || game == changeToLowerCase(Go)) {
				try {
					current_game = make_shared<GomukuGame>();
					gb = current_game;
					gb->game_type = game;
				}
				catch (bad_alloc ba) {
					throw ba;
				}
				
			}
			
			else if (game == Su || game == changeToLowerCase(Su)) {
				try {
					current_game = make_shared<SudokuGame>();
					gb = current_game;
					gb->game_type = Su;
				}
				catch (bad_alloc ba) {
					throw ba;
				}

			}
			else {
				throw "Invalid name given.";
			}
		}
	}
	catch (exception &e) {
		cout << "Exception caught in arguments() method with: " << e.what() << endl;
		throw "Your static pointer is not pointing to null";
	}


}



/* TURN() -  If the number of game moves are odd, it's player X's turn. Otherwise, player Y's turn.
Number of game moves increments by 1 everytime turn() executes.
Calls the prompt method and checks to see if user quits the game already.  */

int GameBase::turn() {

	u_int xCord; u_int yCord;
	int prompt_result = prompt(xCord, yCord);

	if (prompt_result != user_success) {

		if (prompt_result == user_quit) {
			return turn_method_quit;
		}

		return turn_method_failure;
	}

	if (numMoves % 2 == 1 && !done()) {
		this->playerTurn = firstPlayer;
		playerTwo += to_string(xCord) + ", " + to_string(yCord) + "; ";
	}

	else if (numMoves % 2 == 0 && !done()) {
		this->playerTurn = secondPlayer;
		playerOne += to_string(xCord) + ", " + to_string(yCord) + "; ";
	}

	numMoves += 1;

	cout << " " << endl;		// The intervening line
	return tic_tac_toe_success;
}



/* PLAY() - User calls this method in main function. Starts off the game by calling the turn method repeatedly
until a player wins, the game is draw, or the user quits.  */

int GameBase::play() {

	while (true) {

		if (gb->game_type == "Sudoku") {    //Manually breaks the loop since I implemented only to print out the SudokuBoard
			gb->print();
			break;
		}
		
		print();

		cout << playerOne << endl;
		cout << endl;
		cout << playerTwo << endl;
		cout << endl;

		int turn_result = turn();

		if (turn_result == turn_method_quit) {
			cout << endl;
			cout << "You played " << numMoves << " times. " << endl;
			cout << "You have successfully quit the game. Please come again! " << endl;
			return user_quit_from_play_method;
		}

		if (done() == true) {
			print();

			cout << playerOne << endl;
			cout << endl;
			cout << playerTwo << endl;
			cout << endl;

			cout << "Player " << playerTurn << " wins the game." << endl;

			//When the game is complete, overwrite the game's file to indicate that
			//the next time the game is played it should start at the beginning
			string TTT = "TicTacToe"; string G = "Gomuku";

			if (this->game_type == TTT || this->game_type == changeToLowerCase(TTT)) {
				ofstream TTTFile;
				TTTFile.open("TicTacToe.txt");
				TTTFile << "NO DATA for TicTacToe" << endl;
				TTTFile.close();
			}
			else if (this->game_type == G || this->game_type == changeToLowerCase(G)) {
				ofstream TTTFile;
				TTTFile.open("Gomuku.txt");
				TTTFile << "NO DATA for Gomuku" << endl;
				TTTFile.close();
			}
			else {
				cout << "Error in game type" << endl;
				return invalid_game_type;
			}


			return user_success;
		}

		if (draw() == true) {
			cout << "You played " << numMoves << " times. " << endl;
			cout << "There are no winning moves remaining. The game is a draw." << endl;
			return draw_failure;
		}

	}

}



/* **************************** END OF FILE ********************************* */
