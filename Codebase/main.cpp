#include "common.h"

#include <regex>
#include <chrono>

#include "messages.h"
#include "puzzle.h"
#include "states.h"
#include "searchMethod.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "AStarSearch.h"
#include "GreedySearch.h"
#include "CUS1.h"
#include "CUS2.h"


using namespace std;

// Reads file into vector
 vector<string> inputFromFile(string& filepath){
	ifstream myfile(filepath);
	vector<string> vec;
	string s;

	if (!myfile) return vec;
	
	int i = 0;
	while (getline(myfile, s)) {
		vec.insert(vec.end(), s);
	}

	myfile.close();
	return vec;
}


// Counts the number of words delimited by a " " within a string
int countWords(string str)
{
	stringstream s(str);
	string word;
	int count = 0;
	while (s >> word)
		count++;
	return count;
}


// This method will return 0 if there is an error.
// If everything is working as per normal, it will return a non zero value.
int functionSearch(string filename, string method) {

	vector<string> tmp1 = inputFromFile(filename);
	if (tmp1.size() <= 3) { // Checks if Puzzle Size, Initial State and Goal States are minimum found in file
		cout << "yucky" << endl;
	}
	
	// Sanitise Text
	vector<vector<states>> puzzleSize;
	vector<vector<states>> initialState;
	vector<vector<states>> goalStates;
	vector<vector<states>> illegalStates;
	int incr=0;


	for (auto i : tmp1 ){
		std::regex regex(R"(\d+)");   // matches a sequence of digits
		std::smatch match;
		vector<int> temp;
		while (std::regex_search(i, match, regex)) { // Sanitise Text to digits only
			temp.push_back(std::stoi(match.str()));
			i = match.suffix();
		}

		states pointTemp;
		vector<states> states;
		if (incr <= 2) { // For Puzzle Size, Initial State and Goal States
			for (int i = 0; i < temp.size(); i += 2) {

				pointTemp.x = temp[i];
				pointTemp.y = temp[i + 1];
				pointTemp.width = -1;
				pointTemp.height = -1;
				states.push_back(pointTemp);

				if (incr == 0) {
					puzzleSize.push_back(states);
				} 
				else if (incr == 1) {
					initialState.push_back(states);
				}
				else if (incr == 2) {
					goalStates.push_back(states);
				}
				states.clear();
			}
		}
		else { // For Illegal States
			for (int i = 0; i < temp.size(); i += 4) {
				pointTemp.x = temp[i];
				pointTemp.y = temp[i + 1];
				pointTemp.width = temp[i + 2];
				pointTemp.height = temp[i + 3];
				states.push_back(pointTemp);
				illegalStates.push_back(states);
			}
		}
		incr++;
	}


	// Setup Puzzle
	Puzzle map(puzzleSize[0][0].x, puzzleSize[0][0].y);	
	map.SetStartState(initialState[0][0].x, initialState[0][0].y);

	// Input all individual Goal States
	for (int i = 0; i < goalStates.size();i++) {
		for (int j = 0; j < goalStates[i].size(); j++) {
			map.AddGoalState(goalStates[i][j].x, goalStates[i][j].y);
		}
	}
	// Input all individual Illegal States
	for (auto i : illegalStates) {
		for (auto j : i) {
			int maxWidth = j.x + j.width;
			int maxHeight = j.y + j.height;
			
			for (int k = j.x; k < maxWidth; k++) {
				for (int l = j.y; l < maxHeight; l++) {
					map.AddIllegalState(k, l);
				}
			}

		}
	}

	map.DrawPuzzle();

	// Search Method
	SearchMethod* smptr = nullptr;

	if (method == BreadthFirstSearch::getSMCode())
		smptr = new BreadthFirstSearch();
	else if (method == DepthFirstSearch::getSMCode())
		smptr = new DepthFirstSearch();
	else if (method == AStarSearch::getSMCode())
		smptr = new AStarSearch();
	else if (method == GreedySearch::getSMCode())
		smptr = new GreedySearch();
	else if (method == CUS1::getSMCode())
		smptr = new CUS1();
	else if (method == CUS2::getSMCode())
		smptr = new CUS2();

	if (smptr == nullptr) {
		messageError("Search Method Error");
		return 1;
	}

	SearchMethod& search = *smptr;

	// Implement a Timer
	float time = 0.0f;
	{
		clock_t start, end;
		start = clock();
		search.Solve(map);
		end = clock();
		time = end - start;
	}

	// Solve Message
	if (search.isSolved()) {
		std::cout << "Done." << std::endl;
		std::cout << "Solution found in ";
		if (time < 2000.0f)
			std::cout << time << "ms";
		else
			std::cout << (time / 1000.0f) << "s";
		std::cout << std::endl;
		std::cout << "\nNumber of Nodes: " << search.getIterations() << std::endl;

		std::cout << "\Path: " << search.getIterations() << std::endl;
		for (auto direction : search.getDirectionalPath())
			std::cout << DirectionToString(direction) << ";";
		std::cout << std::endl;

	}
	else {
		std::cout << "No solution found." << std::endl;
	}




	return 1;
}

int main() {
	bool running = true;
	messageWelcome();
	while (running == true) {

		// Ask user for input
		messageActionPrompt();

		// Retrieve input from terminal and format it correctly
		string userInput = "", inString = "";
		getline(cin, userInput);
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

		//transform(userInput.begin(), userInput.end(), userInput.begin(), tolower);
		stringstream ss(userInput);
		ss << userInput;
		int argsCount = countWords(userInput);

		// Input Arguments validation
		string action, filename, method;
		if (argsCount == 1)			{ ss >> action;}
		else if (argsCount == 3)	{ ss >> action >> filename >> method; }
		else {	messageInputArgumentsError();	continue; }

		// Main Function of Console Interface
		if (action == "exit") {
			running = false;
			messageLeave();
		}
		else if (action == "search") {
			int tmp = functionSearch(filename, method);
			if (tmp == 0) { messageInputFileError(); }
		}
		else if (action == "help") {
			messageHelp();
		}
		else {
			messageActionError();
		}
	}
	return 0;
}

