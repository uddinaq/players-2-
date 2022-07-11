#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;

//Size of Array containing players and Players Scores
const int PLAYERS_COUNT = 10;
const int SCORES = 4;

struct Player {
	string name;
	int scores[SCORES];
	int averageScores;
};


//Reads data from file and stores in provided arrays.
bool GetBowlingData(string fileName, Player players[]) {
	//open the file for reading
	ifstream fin(fileName);

	//if file not opened, return false
	if (fin.is_open() == false) {
		return false;
	}

	//if file opened read players data.
	for (int i = 0; i < PLAYERS_COUNT; i++) {
		fin >> players[i].name;
		for (int j = 0; j < SCORES; j++) {
			fin >> players[i].scores[j];
		}
	}

	//Close the file
	fin.close();
	return true;

}

//Calculates and returns average scores
//Allocates the memory for array dynamically.
void GetAverageScores(Player* players) {
	
	for (int i = 0; i < PLAYERS_COUNT; i++) {
		//Calculate scores sum of each player
		int scoresSum = 0;
		for (int j = 0; j < SCORES; j++)
			scoresSum += players[i].scores[j];

		//Average of that player
		players[i].averageScores = scoresSum / SCORES;
	}

	
}

//Prints Player details and their scores 
void PrettyPrintScores(Player* players) {
	//Print data for each player
	for (int i = 0; i < PLAYERS_COUNT; i++) {
		cout << setw(25) << left << "Player Name: " << players[i].name << endl;
		cout << setw(25) << left << "Player Scores: ";

		//print players scores
		for (int j = 0; j < SCORES; j++)
			cout << players[i].scores[j] << "\t";
		cout << endl;
		cout << setw(25) << "Player Average Scores: " << players[i].averageScores << endl << endl;
	}
}

int main() {

	//File name containing input data
	const string fileName = "BowlingScores.txt";

	//Players array
	Player players[PLAYERS_COUNT];
	
	bool readSuccessfully = false;
	//Read data from file
	readSuccessfully = GetBowlingData(fileName, players);
	if (readSuccessfully == false)
		cout << "Error! Can't read data from file\n";
	else {
		GetAverageScores(players);
		PrettyPrintScores(players);
	}
	return 0;
}