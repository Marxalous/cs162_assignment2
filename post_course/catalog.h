/******************************************************
** Program: catalog.h
** Author: Matthew McMahon
** Date: 10/29/2023
** Description: Header file for CS162 assignment 2
** Input: Function calls in int main()
** Output: Function and Struct information
******************************************************/

#include <fstream>

using namespace std;

//a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player *p;   //an array that holds all players
  float total_ppg;    //total points per game
};

//a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};


/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int);


/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct 
                with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
                int - index of the Team in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team*, int, ifstream &); 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int);


/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct 
                with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
                int - index of the Player in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team*, int);

/**************************************************
 * Name: make_input_file()
 * Description: This function prompts the user to enter a filename and opens an input file with the given name.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns an ifstream object associated with the specified file.
************************************************/
ifstream make_input_file();

/**************************************************
 * Name: make_output_file()
 * Description: This function prompts the user to enter a filename and opens an output file with the given name.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns an ofstream object associated with the specified file.
************************************************/
ofstream make_output_file();

/**************************************************
 * Name: selection()
 * Description: This function interacts with the user to select an option from a menu.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns the user's selection (1, 2, 3, or 4) based on the menu options.
************************************************/
int selection();

/**************************************************
 * Name: to_file_or_terminal()
 * Description: This function interacts with the user to select the output destination (file or terminal) for data printing.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns the user's selection: 1 for printing to a file, 2 for printing to the terminal, or 3 to go back.
************************************************/
int to_file_or_terminal();

/**************************************************
 * Name: team_output_by_file()
 * Description: This function allows the user to choose a team by name and appends information about the selected team,
 *              including its name, owner, market value, number of players, and the names of the players, to an output file.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter should
 *                 be the total number of teams in the array.
 * Post-conditions: The function interacts with the user to select and append information about a specific team to an output file,
 *                  and it outputs a success message after completing the operation.
************************************************/
void team_output_by_file(Team*, int);

/**************************************************
 * Name: team_output_by_terminal()
 * Description: This function allows the user to choose a team by name and outputs information about the selected team,
 *              including its name, owner, market value, number of players, and the names of the players, to the terminal.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter should
 *                 be the total number of teams in the array.
 * Post-conditions: The function interacts with the user to select and display information about a specific team,
 *                  and it outputs a success message after completing the operation.
************************************************/
void team_output_by_terminal(Team*, int);

/**************************************************
 * Name: top_scorers_by_file()
 * Description: This function searches through all teams and their players to find the top scorer in each team.
 *              It then appends information about the top scorers, including their team, name, and points per game (PPG),
 *              to an output file.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter should
 *                 be the total number of teams in the array.
 * Post-conditions: The function identifies and appends information about the top scorers in each team to an output file,
 *                  and it outputs a success message.
************************************************/
void top_scorers_by_file(Team*, int);

/**************************************************
 * Name: top_scorers_by_terminal()
 * Description: This function searches through all teams and their players to find the top scorer in each team.
 *              It then displays information about the top scorers, including their team, name, and points per game (PPG),
 *              to the terminal.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter should
 *                 be the total number of teams in the array.
 * Post-conditions: The function identifies and displays information about the top scorers in each team, then
 *                  outputs a success message.
************************************************/
void top_scorers_by_terminal(Team*, int);

/**************************************************
 * Name: nationality_output_by_file()
 * Description: This function allows the user to input a nationality, and then it searches through all teams
 *              and players to find and output the names of players who belong to the inputted nationality to an output file.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter
 *                 should be the total number of teams in the array.
 * Post-conditions: The function runs until a valid nationality is inputted. It outputs player names who match
 *                  the inputted nationality to a file, and displays success or error messages.
************************************************/
void nationality_output_by_file(Team*, int);

/**************************************************
 * Name: nationality_output_by_terminal()
 * Description: This function allows the user to input a nationality, and then it searches through all teams
 * and players to find and display the names of players who belong to the inputted nationality.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter
 *                 should be the total number of teams in the array.
 * Post-conditions: The function runs until a valid nationality is inputted. It outputs player names who match
 *                  the inputted nationality to the terminal and displays success or error messages.
************************************************/
void nationality_output_by_terminal(Team*, int);

/**************************************************
 * Name: team_output()
 * Description: This function allows the user to select a team and either print its details to a file
 *              or to the terminal based on user input.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter
 *                 should be the total number of teams in the array.
 * Post-conditions: The function interacts with the 'to_file_or_terminal' function to determine whether
 *                  the user wants to print to a file or the terminal. It then prints the details of
 *                  the selected team based on the user's choice.
************************************************/
void team_output(Team*, int);

/**************************************************
 * Name: top_scorers()
 * Description: This function allows the user to select the top scorer for each team and then either
 *              prints this information to a file or to the terminal based on user input.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter
 *                 should be the total number of teams in the array.
 * Post-conditions: The function interacts with the 'to_file_or_terminal' function to determine whether
 *                  the user wants to print to a file or the terminal. It then prints the top scorer
 *                  for each team based on the user's choice.
************************************************/
void top_scorers(Team*, int);

/**************************************************
 * Name: nationality_output()
 * Description: This function allows the user to select a nationality and then either prints the players
 *              from that nationality to a file or to the terminal based on user input.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter
 *                 should be the total number of teams in the array.
 * Post-conditions: The function interacts with the 'to_file_or_terminal' function to determine whether
 *                  the user wants to print to a file or the terminal. It then prints players from the
 *                  selected nationality based on the user's choice.
************************************************/
void nationality_output(Team*, int);

/**************************************************
 * Name: search_and_print()
 * Description: This function allows the user to repeatedly select various search and print options, 
 *              such as searching for teams by name, finding top scorers, or searching by nationality, and then 
 *              prints the results based on the user's selections.
 * Parameters: Team* teams - an array of Team structures, int team_num - the number of teams in the array
 * Pre-conditions: The 'teams' array should be properly populated with data. The 'team_num' parameter
 *                 should be the total number of teams in the array.
 * Post-conditions: The function provides a user interface for selecting different search and print options.
 *                  It continues running until the user selects the option to quit, and it interacts
 *                  with other functions to fulfill the user's requests.
************************************************/
void search_and_print(Team*, int);