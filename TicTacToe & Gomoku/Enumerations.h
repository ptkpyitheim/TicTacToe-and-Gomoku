#pragma once

/*** ALL ENUMS DECLARATIONS BELOW *** */


enum program {			//argv[] and argc values for command line inputs
	program_name,
	game_name,
	expected_num_arg,
};


enum failure_for_main {			//failure values just for the command line prompts
	main_success,
	invalid_num_arg,
	invalid_command_line_input,
	incorrect_argument = 89,
	bad_memory_alloc
};


enum ascii_values {				//For converting a string to lower case
	lower_case_a = 97,
	difference_between_upper_lower = 32
};


enum Game_Errors {		//all errors corresponding to the tictactoe and gomuku cpp files
	tic_tac_toe_success,
	invalid_coordinates = 21,
	user_input_out_of_range,
	extraction_error,
	turn_method_failure,
	turn_method_quit,
	draw_failure,
	invalid_user_input,
};


enum user_interactions {		//values corresponding to what user inputs
	user_success,
	user_quit,
	user_quit_from_play_method,
	TTT_expected_argc,
	Gomuku_least_expected_argc = 3,
	Gomuku_most_expected_argc = 5,
	invalid_game_type
};


enum user_command_arguments {		//For user coordinate inputs.
	row_coordinate,
	second_character,
	col_coordinate
};


enum board_dimensions {			//Game Board only
	TTT_width = 5,
	TTT_height = 5,
	Gomuku_width = 21,
	Gomuku_height = 21,
	TTT_total_moves_available = 9,
	TTT_winning_moves = 3,
	Gomuku_total_moves_available = 200,
	Gomuku_winning_moves = 5,
	Sudoku_width = 9,
	Sudoku_height = 9
};


enum loop_iterators {			//Local variables for for-loop iterations
	starter_zero,
	starter_one,
};


enum printDimensions {			//All the valid dimensions of the board
	zero,
	one,
	two,
	three,
	four
};


enum savingGame {
	save_game_success,
	save_game_error = 55,
	invalid_save_user_response = 33,
	unable_to_open_file = 57,
	game_not_saved = 58,
	invalid_saved_file = 25,
	invalid_row_read = 24
};


enum placeholderForSudoku {
	is_placeholder,
	is_not_placeholder
};
