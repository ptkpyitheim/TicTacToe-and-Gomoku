
	Lab 5 - Sudoku
	Author: Pyi Theim "PTK" Kyaw
	Date: 12/15/2018

	Errors I ran into:

		Cannot instantiate an abstract class of SudokuGame.

		Because of this error I couldn't build a new Sudoku class. I can't figure out why.



	Running the program:
		
	Input: Lab5_Sudoku.exe

	Output: Incorrect run of the program. Please re-type Lab5_Sudoku.exe followed by TicTacToe (or) Gomuku (or) Sudoku

	Input: Lab5_Sudoku.exe tictactoe

	Output:			NOTE: I will not be giving trials for TicTacToe Game since I had those working exactly like in this lab
							from 4. There's one exception for saving the file and I showed that trial below.

							Welcome to the Ultimate Tic Tac Toe Game!

						 4
						 3
						 2
						 1
						 0
						   0 1 2 3 4

						Player X:

						Player O:

						Type in a valid coordinate to play. (E.g. 2,2)
						   Type 'quit' to end the game.

						This is player X turn.

						Please enter a command:


	Input: quit

	Output:
						   *********************************************
					Do you want to save this game? Type 'y' for yes and 'n' for no:

	Input: n

	Output:
						Game was not saved.

					You have successfully quit the game. Please come again!


	Input: y

	Output:
						File Saved Successfully.

					You played 2 times.
					You have successfully quit the game. Please come again!

	
	**How it looks like in TicTacToe.txt file after saving an unfinished game.
	X
	2
	X12
	O32

	X represents the player turn.
	2 represents the number of turns played so we can continue counting the number of moves.
	X12 represents the gamepiece and its corresponding coordinates

	*** NOTE: After a player wins the game, the initial saved file will be overwrited with "NO DATA for TicTacToe"


	Input: Lab5_Sudoku.exe gomuku

	Output:

					Welcome to the Ultimate Gomuku Game!


				20
				19
				18
				17
				16
				15
				14
				13
				12
				11
				10
				 9
				 8
				 7
				 6
				 5
				 4
				 3
				 2
				 1
				 0
				 X  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

				Player B:

				Player W:

				Type in a valid coordinate to play. (E.g. 2,2)
				   Type 'quit' to end the game.

				This is player B turn.

				Please enter a command:

		**How it looks like in TicTacToe.txt file after saving an unfinished game.
			B
			4
			B11
			W32


			B represents the player turn.
			4 represents the number of turns played so we can continue counting the number of moves.
			B11 represents the gamepiece and its corresponding coordinates

		*** NOTE: After a player wins the game, the initial saved file will be overwrited with "NO DATA for Gomuku"


	Input: Lab5_Sudoku.exe asdf

	Output:
				Incorrect run of the program. Please re-type Lab5_Sudoku.exe followed by TicTacToe (or) Gomuku (or) Sudoku


	Input: Lab5_Sudoku.exe Sudoku

	Output:

--||---|---|---||---|---|---||---|---|---||
8 ||   |   |   ||   |   |   ||   |   |   ||
--||---|---|---||---|---|---||---|---|---||
7 ||   |   |   ||   |   |   ||   |   |   ||
--||---|---|---||---|---|---||---|---|---||
6 ||   |   |   ||   |   |   ||   |   |   ||
==||===|===|===||===|===|===||===|===|===||
5 ||   |   |   ||   |   |   ||   |   |   ||
--||---|---|---||---|---|---||---|---|---||
4 ||   |   |   ||   |   |   ||   |   |   ||
--||---|---|---||---|---|---||---|---|---||
3 ||   |   |   ||   |   |   ||   |   |   ||
==||===|===|===||===|===|===||===|===|===||
2 ||   |   |   ||   |   |   ||   |   |   ||
--||---|---|---||---|---|---||---|---|---||
1 ||   |   |   ||   |   |   ||   |   |   ||
--||---|---|---||---|---|---||---|---|---||
0 ||   |   |   ||   |   |   ||   |   |   ||
==||===|===|===||===|===|===||===|===|===||
  || 0 | 1 | 2 || 3 | 4 | 5 || 6 | 7 | 8 ||



  ************ END OF THE LAB **************



========================================================================
    CONSOLE APPLICATION : Lab5_Sudoku Project Overview
========================================================================

AppWizard has created this Lab5_Sudoku application for you.

This file contains a summary of what you will find in each of the files that
make up your Lab5_Sudoku application.


Lab5_Sudoku.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Lab5_Sudoku.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Lab5_Sudoku.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Lab5_Sudoku.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
