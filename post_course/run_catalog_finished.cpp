/******************************************************
** Program: run_catalog.cpp
** Author: Matthew McMahon
** Date: 10/29/2023
** Description: Contains int main() function
** Input: user inputs, function and struct information from header 
** Output: the program, all file and terminal outputs
******************************************************/

#include "catalog.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// Initialize the input file to accept a file to read; and run the make_file() function to get the file to read from
	ifstream input_file;
	input_file = make_input_file();
	
	// Error handling for if the file trying to be read does not exist
	if (!input_file) {
		cerr << "Error opening the file. Shutting down..." << endl;
		return 1;
	}
	// If proper file has been read, it will continue
	else cout << "Opening file..." << endl << endl;

	// File reader; getting first word in file; assigns the value to be the number of teams if read properly
	string word;
	input_file >> word;
	int team_num = stoi(word);
	int player_num;
	
	// Creates a dynamic array with the first number for the number of teams
	Team* teams = create_teams(team_num);
	
	// For the number of teams there are, it will populate the data
	for (int i = 0; i < team_num; ++ i) {
		// Using the populate_team_data() function, it will read from the file to get the information needed
		populate_team_data(teams, i, input_file);

		// Assigns the number of players based on the number of players added in the population of the team data
		player_num = teams[i].num_player;
		// Creates the 2D part of the array for the players within the teams
		teams[i].p = create_players(player_num);

		// Populates the player data for however many players there are in each team, with data from the file
		for (int j = 0; j < player_num; ++j) {
			populate_player_data(&teams[i].p[j], 0, input_file);
		}
	}

	// Searching and Printing; searches for the desired output and prints it based on user input
	search_and_print(teams, team_num);

	// Deallocation of Memory; deletes used memory to prevent memory leak
	delete_info(teams, team_num);

	return 0;
}