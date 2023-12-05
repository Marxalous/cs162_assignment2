# cs162_assignment2
Oregon State University CS162 Fall 2023 Assignment 2

/* PLEASE VIEW IN CODE MODE */

+----------------+
| Score: ---/100 |
+----------------+------------------+------------+---+----------+---+-------+
| Rubric:        |                  | Full Marks |   | No Marks |   | Pts   |
+-----------------------------------+------------+---+----------+---+-------+
| prompt the user for the file      |            |   |          |   |       |
| name to store team info           | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| display error message and         |            |   |          |   |       |
| terminates gracefully if the      |            |   |          |   |       |
| user failed to provide existing   |            |   |          |   |       |
| file name for team info           | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Program correctly searches and    |            |   |          |   |       |
| displays the team by its name.    | 10pt       |   | 0pt      |   | 10    |
+-----------------------------------+------------+---+----------+---+-------+
| Program correctly searches and    |            |   |          |   |       |
| displays the top scorer of every  |            |   |          |   |       |
| team (ignore the tie condition)   | 10pt       |   | 0pt      |   | 10    |
+-----------------------------------+------------+---+----------+---+-------+
| Program correctly searches and    |            |   |          |   |       |
| displays all players with         |            |   |          |   |       |
| provided nationality              | 10pt       |   | 0pt      |   | 10    |
+-----------------------------------+------------+---+----------+---+-------+
| Use dynamic arrays of structs     |            |   |          |   |       |
| and correctly store information   |            |   |          |   |       |
| of teams.                         | 8pt        |   | 0pt      |   | 8     |
+-----------------------------------+------------+---+----------+---+-------+
| Error handling all inputs         |            |   |          |   |       |
| (including different types), and  |            |   |          |   |       |
| reprompt until a valid one is     |            |   |          |   |       |
| given                             | 5pt        |   | 0pt      |   | 5     |
+-----------------------------------+------------+---+----------+---+-------+
| The user is able to request the   |            |   |          |   |       |
| output be redirected to a         |            |   |          |   |       |
| user-specified filename.          | 6pt        |   | 0pt      |   | 6     |
+-----------------------------------+------------+---+----------+---+-------+
| The correct information is        |            |   |          |   |       |
| appended to that particular file. | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Program repeats until the user    |            |   |          |   |       |
| chooses to exit                   | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Code defines/uses the team, and   |            |   |          |   |       |
| player structs exactly as         |            |   |          |   |       |
| specified. (+5 pts for each       |            |   |          |   |       |
| correct struct)                   | 10pt       |   | 0pt      |   | 10    |
+-----------------------------------+------------+---+----------+---+-------+
| Code uses 5 required function     |            |   |          |   |       |
| prototypes (+3 for each function  |            |   |          |   |       |
| prototype implemented and used)   | 15pt       |   | 0pt      |   | 15    |
+-----------------------------------+------------+---+----------+---+-------+
| Program was submitted as a        |            |   |          |   |       |
| single zip file                   | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Program was separated into a      |            |   |          |   |       |
| working makefile, an application  |            |   |          |   |       |
| .cpp file, a header .h file, and  |            |   |          |   |       |
| an implementation .cpp file       |            |   |          |   |       |
| (-2 for each missing file,        |            |   |          |   |       |
| -6 at max)                        | 6pt        |   | 0pt      |   | 6     |
+-----------------------------------+------------+---+----------+---+-------+
| Program header that contains      |            |   |          |   |       |
| author's name, description, etc   | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Function header for each function |            |   |          |   |       |
| that contains function name,      |            |   |          |   |       |
| description, etc                  | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
| Consistent and proper             |            |   |          |   |       |
| spacing/indentation               | 4pt        |   | 0pt      |   | 4     |
+-----------------------------------+------------+---+----------+---+-------+
| Proper user of in line comments   | 2pt        |   | 0pt      |   | 2     |
+-----------------------------------+------------+---+----------+---+-------+
|                                   |            |   |          | = | 100   |
|                                   |            |   |          | / | 100   |
+-----------------------------------+------------+---+----------+---+-------+
| Extra credit:                     | Full Marks |   | No Marks |   | Pts   |
+-----------------------------------+------------+---+----------+---+-------+
| Program correctly sorts and       |            |   |          |   |       |
| displays teams by total points    |            |   |          |   |       |
| per game in descending order      | 10pt       |   | 0pt      |   | 0     |
+-----------------------------------+------------+---+----------+---+-------+
| Simulate a basketball game        |            |   |          |   |       |
| (from assignment 1)               |            |   |          |   |       |
|   - a. asm1 is separated into 3   |            |   |          |   |       |
|     files: game.h, game.cpp, and  |            |   |          |   |       |
|     main.cpp                      |            |   |          |   |       |
|   - b. prompt for at least two    |            |   |          |   |       |
|     valid player names            |            |   |          |   |       |
|   - c. use player fg% instead of  |            |   |          |   |       |
|     50%                           |            |   |          |   |       |
|   - d. declare the winner         | 10pt       |   | 0pt      |   | 0     |
+-----------------------------------+------------+---+----------+---+-------+
|                                   |            |   |          | = | 0     |
|                                   |            |   |          | / | 20    |
+-----------------------------------+------------+---+----------+---+-------+
|                                   |            |   |          | = | 100   |
|                                   |            |   |          | / | 120   |
+-----------------------------------+------------+---+----------+---+-------+
