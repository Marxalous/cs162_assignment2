/******************************************************
** Program: catalog.cpp
** Author: Matthew McMahon
** Date: 10/29/2023
** Description: Contains the functions for CS162 assignment 2
** Input: file names, ints, names, etc.
** Output: to file or terminal (team information, highest scorers, players by naitonality)
******************************************************/

#include "catalog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

//function definitions go here
Team* create_teams(int team_num) {
    // Creates a dynamic array for the number of teams
    Team* teams = new Team[team_num];

    // Assigns the number of players in each team to be nullptr; will be added with the population of team data
    for (int i = 0; i < team_num; ++i) {
        teams[i].p = nullptr;
    }

    // Returns the teams array
    return teams;
}

void populate_team_data(Team* teams, int team_num, ifstream &input_file) {
    string word;

    // Team Name
    input_file >> word;
    teams[team_num].name = word;

    // Team Owner
    input_file >> word;
    teams[team_num].owner = word;

    // Team Market Value
    input_file >> word;
    int team_market_value = stoi(word);
    teams[team_num].market_value = team_market_value;

    // Team Player Count
    input_file >> word;
    int team_player_count = stoi(word);
    teams[team_num].num_player = team_player_count;
}

Player* create_players(int player_num) {
    // Creates a player for the number of players within each team
    Player* players = new Player[player_num];

    // Return the players array
    return players;
}

void populate_player_data(Player* players, int player_num, ifstream &input_file) {
    string word;
    
    // Player Name
    input_file >> word;
    players[player_num].name = word;

    // Player Age
    input_file >> word;
    int player_age = stoi(word);
    players[player_num].age = player_age;

    // Player Nationality
    input_file >> word;
    players[player_num].nation = word;

    // Player Points Per Game
    input_file >> word;
    float player_ppg = stof(word);
    players[player_num].ppg = player_ppg;

    // Player Field Goal Percentage
    input_file >> word;
    float player_fg = stof(word);
    players[player_num].fg = player_fg;
}

void delete_info(Team* teams, int team_num) {
    // Deallocates the memory in the teams array
    for (int i = 0; i < team_num; ++i) {
        delete[] teams[i].p;
    }
    
    delete[] teams;
}

ifstream make_input_file() {
    // Take user input for the file being read
	string file;
	cout << "Which file would you like to read from? (include .txt)\nFile name: ";
	cin >> file;

    //file = "teams.txt"; //  TESTING PLACEHOLDER

	// Assign the input to be the file being read
    ifstream input_file(file);

    // Return the input file
    return input_file;
}

ofstream make_output_file() {
    string file;
    cout << "Which file would you like to output to? (include .txt):\nFile Name: ";
    cin >> file;
    cout << endl;

    //file = "output.txt";    // TESTING PLACEHOLDER

    // Appends to the file if it exists, otherwise it creates a new file
    ofstream output_file(file, ios::app);

    // If there is an error with opening the file, the error message will appear
    if (!output_file.is_open()) {
        cerr << "Error opening the file." << endl;
    }

    // Return the output file
    return output_file;
}

int selection() {
    int selection;
    
    // Runs until proper input is entered
    do {
        cout << "What would you like to do?\n 1) Search by team name\n 2) Search for top scorers\n 3) Search by nationality\n 4) Quit\nOption: ";
        cin >> selection;
        cout << endl;

        // If there is an improper input
        if (selection < 1 ||  selection > 4) {
            cerr << "Invalid input. Please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (selection < 1 || selection > 4);

    // Returns the user inputted selection
    return selection;
}

int to_file_or_terminal() {
    int to_file_or_terminal;

    // Runs until proper input is entered
    do {
        cout << "How would you like to recieve the data?\n  1) Print to file\n  2) Print to terminal\n  3) Go back\nOption: ";
        cin >> to_file_or_terminal;
        cout << endl;

        // If there is an improper input
        if (to_file_or_terminal < 1 || to_file_or_terminal > 3) {
            cerr << "Invalid input. Please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (to_file_or_terminal < 1 || to_file_or_terminal > 3);

    // Returns the user inputted selection
    return to_file_or_terminal;
}

void team_output_by_file(Team* teams, int team_num) {
    string team;
    bool match = false;
    ofstream output_file = make_output_file();
    
    // Runs until proper unput is entered
    while (!match) {

        // Asks for user input for team name
        cout << "Choose a team to output: ";
        cin >> team;

        // Searches for a team that matches the user input
        for (int i = 0; i < team_num; ++i) {
            if (team == teams[i].name) {
                // Appends to file the information of matching team
                output_file <<  "Team Name:    " << teams[i].name << endl <<
                                "Owner:        " << teams[i].owner << endl <<
                                "Market Value: $" << teams[i].market_value << endl <<
                                "Player Count: " << teams[i].num_player << "\nPlayers;\n";
            
                // Appends to file the player names in the matching team
                for (int j = 0; j < teams[i].num_player; ++j) {
                    output_file <<  " Player: " << teams[i].p[j].name << endl;
                }
                
                // If valid team name is entered, it will break the loop allowing for the code to finish
                match = true;
                break;
            }
        }

        // If there is no matching team, there will be an error output, and will prompt the user to try again
        if (!match) {
            cerr << "Team not found. Please try again..." << endl;
        }
        // If there is a matching team, there will be a success output, and will continue
        else {
            cout << "Print Successful" << endl << endl;
        }
    }

    output_file << endl;
}

void team_output_by_terminal(Team* teams, int team_num) {
    string team;
    bool match = false;

    // Runs until proper unput is entered
    while (!match) {

        // Asks for user input for team name
        cout << "Choose a team to output: ";
        cin >> team;

        // Searches for a team that matches the user input
        for (int i = 0; i < team_num; ++i) {
            if (team == teams[i].name) {
                // Outputs the information of matching team
                cout << "Team Name:    " << teams[i].name << endl <<
                        "Owner:        " << teams[i].owner << endl <<
                        "Market Value: $" << teams[i].market_value << endl <<
                        "Player Count: " << teams[i].num_player << "\n\n";

                // Outputs the player names in the matching team
                for (int j = 0; j < teams[i].num_player; ++j) {
                    cout << " Player: " << teams[i].p[j].name << endl;
                }
                
                // If valid team name is entered, it will break the loop allowing for the code to finish
                match = true;
                break;
            }
        }

        // If there is no matching team, there will be an error output, and will prompt the user to try again
        if (!match) {
            cerr << "Team not found. Please try again..." << endl;
        }
        // If there is a matching team, there will be a success output, and will continue
        else {
            cout << "Print Successful" << endl << endl;
        }
    }
}

void top_scorers_by_file(Team* teams, int team_num) {
    ofstream output_file = make_output_file();

    // Searches throughout all teams
    for (int i = 0; i < team_num; ++i) {
        float highest_ppg = 0;
        int highest_scorer_index = -1;

        // Registers the highest PPG for each team
        for (int j = 0; j < teams[i].num_player; ++j) {
            if (teams[i].p[j].ppg > highest_ppg) {
                highest_ppg = teams[i].p[j].ppg;
                highest_scorer_index = j;
            }
        }

        // If it finds a highest scorer in a team, it will append the information to the output file
        if (highest_scorer_index != -1) {
            output_file <<  "Team:        " << teams[i].name << endl <<
                            " Top Scorer: " << teams[i].p[highest_scorer_index].name << endl <<
                            " PPG:        " << highest_ppg << endl;
        }
    }

    // Outputs a success message when complete
    output_file << endl;
    cout << "Print Successful" << endl << endl;
}

void top_scorers_by_terminal(Team* teams, int team_num) {
    // Searches throughout all teams
    for (int i = 0; i < team_num; ++i) {
        float highest_ppg = 0;
        int highest_scorer_index = -1;

        // Registers the highest PPG for each team
        for (int j = 0; j < teams[i].num_player; ++j) {
            if (teams[i].p[j].ppg > highest_ppg) {
                highest_ppg = teams[i].p[j].ppg;
                highest_scorer_index = j;
            }
        }

        // If it finds a highest scorer in a team, it will output the information to the terminal
        if (highest_scorer_index != -1) {
            cout << "Team:        " << teams[i].name << endl <<
                    " Top Scorer: " << teams[i].p[highest_scorer_index].name << endl <<
                    " PPG:        " << highest_ppg << endl;
        }
    }

    // Outputs a success message when complete
    cout << "Print Successful" << endl << endl;
}

void nationality_output_by_file(Team* teams, int team_num) {
    string nation;
    bool match = false;
    ofstream output_file = make_output_file();

    // Runs until valid country with a match is inputted
    while (!match) { 
        // Prompts user input for country name
        cout << "Choose a nationality to search by: ";
        cin >> nation;
        output_file << "Players from " << nation << endl;

        // Searches through all teams and outputs any player that matches the user inputted country
        for (int i = 0; i < team_num; ++i) {
            for (int j = 0; j < teams[i].num_player; ++j) {
                if (nation == teams[i].p[j].nation) {
                    output_file << "  " << teams[i].p[j].name << endl;
                    match = true;
                }
            }
        }

        // If no match is found, error message will display and will loop again
        if (!match) {
            cerr << "No players from inputted country. Please try again..." << endl;
            output_file << "None" << endl << endl;
        }
        // If a match is found, success message will display and code will continue
        else {
            cout << "Print Successful" << endl << endl;
        }
    }

    output_file << endl;
}

void nationality_output_by_terminal(Team* teams, int team_num) {
    string nation;
    bool match = false;

    // Runs until valid country with a match is inputted
    while (!match) {
        // Prompts user input for country name
        cout << "Choose a nationality to search by: ";
        cin >> nation;
        cout << "Players from " << nation << endl;
        
        // Searches through all teams and outputs any player that matches the user inputted country
        for (int i = 0; i < team_num; ++i) {
            for (int j = 0; j < teams[i].num_player; ++j) {
                if (nation == teams[i].p[j].nation) {
                    cout << "  " << teams[i].p[j].name << endl;
                    match = true;
                }
            }
        }

        // If no match is found, error message will display and will loop again
        if (!match) {
            cerr << "No players from inputted country. Please try again..." << endl;
        }
        // If a match is found, success message will display and code will continue
        else {
            cout << "Print Successful" << endl << endl;
        }
    }
}

void team_output(Team* teams, int team_num) {
    int select = to_file_or_terminal();
    
    // Takes the user input and either prints to file
    if (select == 1) {
        team_output_by_file(teams, team_num);
    }
    // Prints to terminal
    else if (select == 2) {
        team_output_by_terminal(teams, team_num);
    }
    // Or goes back to prior selection
    else;
}

void top_scorers(Team* teams, int team_num) {
    int select = to_file_or_terminal();

    // Takes the user input and either prints to file
    if (select == 1) {
        top_scorers_by_file(teams, team_num);
    }
    // Prints to terminal
    else if (select == 2) {
        top_scorers_by_terminal(teams, team_num);
    }
    // Or goes back to prior selection
    else;
}

void nationality_output(Team* teams, int team_num) {
    int select = to_file_or_terminal();

    // Takes the user input and either prints to file
    if (select == 1) {
        nationality_output_by_file(teams, team_num);
    }
    // Prints to terminal
    else if (select == 2) {
        nationality_output_by_terminal(teams, team_num);
    }
    // Or goes back to prior selection
    else;
}

void search_and_print(Team* teams, int team_num) {
    // Loops until user inputs 4 in selection()
    while (true) {
        int option = selection();

        // Based on user inputs, it will continue to run based on the inputs
        if (option == 1) team_output(teams, team_num);
        else if (option == 2) top_scorers(teams, team_num);
        else if (option == 3) nationality_output(teams, team_num);
        else if (option == 4) return;
    }
}