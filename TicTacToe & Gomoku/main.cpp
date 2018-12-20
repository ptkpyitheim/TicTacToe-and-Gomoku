// Lab5_Sudoku.cpp : Defines the entry point for the console application.
//


/*	Lab 4 - Mulitple Games
Team name: DPUTakeOver
Authors: Pyi Theim "PTK" Kyaw, Vu Hai Minh
WUSTL Keys :  pyitheim.k, minh
Email: k.pyitheim @ wustl.edu, hvu@wustl.edu
Date: 11/06/18
*/

#include "stdafx.h"
#include "GameBase.h"
#include "TicTacToeGame.h"
#include "Sudoku.h"

using namespace std;


/* Prints out to the output stream how to correctly run the program. Takes the parameter of the program name.
Returns failure value for invalid arguments. */

int usageMsg(char* program_name, string correct_usage) {

	cout << "Incorrect run of the program. Please re-type " << program_name << " followed by " << correct_usage << endl;
	return incorrect_argument;

}


// ********* MAIN PROGRAM **************** //

int main(int argc, char* argv[]) {

	string correct_game_names = "TicTacToe (or) Gomuku (or) Sudoku";

	if (argc == expected_num_arg) {

		try {
			bool isSudoku = false;
			if (argv[1] == "Sudoku") {
				isSudoku = true;
			}
			GameBase::arguments(argc, argv);
			shared_ptr<GameBase> c = GameBase::instance();

			if (isSudoku) {
				c->print();
			}

			else if (c == 0) {
				return usageMsg(argv[program_name], correct_game_names);
			}
			else {
				return c->play();
			}

		}
		catch (bad_alloc ba) {
			cout << "Memory allocation error." << endl;
			return bad_memory_alloc;
		}
		catch (int a){
			return a;
		}
		catch (...) {
			return usageMsg(argv[program_name], correct_game_names);
		}

	}

	else {
		return usageMsg(argv[program_name], correct_game_names);
	}

}



/* **************************** END OF FILE ********************************* */

