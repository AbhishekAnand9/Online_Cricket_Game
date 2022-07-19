#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;

// Here creating the  class Team and make it public

class Team {

	public:
		string name;
		string players[3];
		int runs;
};

void welcomeUsers();
void startInning(int, string, string);
void displayPlayers(string[], string[]);
void selectBatsmanAndBowler(Team, Team);
string selectPlayer(string[]);
int playInning();
void displayScore(Team);
void decideWinner(int, int);

// now there are some Globbal variables
string currentBatsman, currentBowler;

//the main function
int main() {

	welcomeUsers();

	Team INDIA;
	INDIA.players[0] = "Virat Kohli";
	INDIA.players[1] = "MS Dhoni";
	INDIA.players[2] = "Suresh Raina";
	INDIA.name = "INDIA";

	Team Pakistan;
	Pakistan.players[0] =  "Babar Azam";
	Pakistan.players[1] =  "Shadab Khan";
	Pakistan.players[2] =  "Mohammad Rizwan";
	Pakistan.name = "PAKISTAN";

    displayPlayers(INDIA.players, Pakistan.players);

    startInning(1, INDIA.name, Pakistan.name);
    selectBatsmanAndBowler(INDIA, Pakistan);
    INDIA.runs = playInning();
    displayScore(INDIA);

    cout << "\n :-:-:-:-:- PAKISTAN needs " << INDIA.runs + 1 << " Runs to win the Game -:-:-:-:-:-:" << endl << endl;

    startInning(2, Pakistan.name, INDIA.name);
    selectBatsmanAndBowler(Pakistan, INDIA);
    Pakistan.runs = playInning();
    displayScore(Pakistan);

    decideWinner(INDIA.runs, Pakistan.runs);

    return 0;
}

/* Function for Greet users with a welcome message */
void welcomeUsers() {

    cout << "::::::=====================================::::::                " << endl;
    cout << "|-|-|-|-|-|-|-|-|-|-| ONLINE CRICKET GAME |-|-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "                                                                 " << endl;
    cout << "                    Welcome Players                              " << endl;
    cout << "       ------------------------------------------                " << endl;
}

/* Display all the players in both team A and team B */
void displayPlayers(string playersA[3], string playersB[3]) {

	cout << "\nPress Enter to display players: ";
	cin.get();

    cout << "Displaying players...\n";
    usleep(1000 * 1000);

    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "|\t";
        cout << "[" << i << "] " << playersA[i] << "\t |";
        cout << "\t\t\t";
        cout << "["<< i << "] " << playersB[i] << "\t |";
        cout << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}

/* Select current batsman and bowler from batting team and bowling team respectively */

void selectBatsmanAndBowler(Team batTeam, Team bowlTeam) {

    cout << "Press Enter to select batsman and bowler: ";
    cin.get();

    cout << "Selecting batsman and bowler...\n";
    usleep(1000 * 1000);

    currentBatsman = selectPlayer(batTeam.players);
    currentBowler = selectPlayer(bowlTeam.players);

    cout << "----------------------------------------------------" << endl;
    cout << "\t\t " << batTeam.name << ": Batsman - " << currentBatsman <<endl;
    cout << "\t\t " << bowlTeam.name << ": Bowler - " << currentBowler <<endl;
    cout << "----------------------------------------------------" << endl << endl;
}

/* Select a player among the given players randomly */
string selectPlayer(string players[3]) {

    int randomValue;

    srand(time(NULL));
    randomValue = rand() % 3; // Generates either 0, 1, or 2

    string selectedPlayerName = players[randomValue];
    return selectedPlayerName;
}

/* Start inning by displaying initial inning details */
void startInning(int inning, string batTeam, string bowlTeam) {

	cout << "Press Enter to start inning " << inning;
    cin.get();
    usleep(1000 * 1000);

    cout << "|------------ Inning " << inning << " Starts ------------|" << endl;
    cout << "|----- " << batTeam << " is batting and " << bowlTeam << " is bowling -----|" << endl << endl;
}

/* Play one inning (6 balls) */
int playInning() {

    int runs = 0;
    const int MAX_BALLS = 6;

    for (int i = 0; i < MAX_BALLS; i++) {

        cout << "Press Enter to bowl...";
        cin.get();

        cout << "Bowling..." << endl << endl;
        usleep(1000 * 1000);

        int randomValue;
        srand(time(NULL));
        randomValue = rand() % 7;   // 0, 1, 2, 3, 4, 5, or 6 
        runs = runs + randomValue;

        cout << "----------------------------------------------------" << endl;
        cout << "|\t\t" << currentBowler << " to " << currentBatsman << " " << randomValue << " runs" << endl;
        cout << "----------------------------------------------------" << endl << endl;
    }

    return runs;
}

/* Display runs scored by batting team in the inning */
void displayScore(Team team) {

    cout << "----------------------------------------------------" << endl;
    cout << "\t\t " << team.name << " scored " << team.runs << " runs." << endl;
    cout << "----------------------------------------------------" << endl << endl;
}

/* Decide winner by comparing final scores of both the teams */
void decideWinner(int teamAScore, int teamBScore) {

	cout << "----------------------------------------------------" << endl;

    if (teamAScore > teamBScore) {
        cout << "\t\t INDIA WON THE MATCH" << endl;
    } else if (teamAScore < teamBScore) {
        cout<< "\t\t PAKISTAN WON THE MATCH" << endl;
    } else {
        cout << "\t\t Match Draw" << endl;
    }

    cout << "----------------------------------------------------" << endl << endl;
}
