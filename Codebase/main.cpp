#include "common.h"

#include "messages.h"
#include "puzzle.h"
#include "states.h"
#include "searchMethod.h"
#include <regex>

using namespace std;


//// Reads file into list given in parameter and writes to the given list
//// If file doesn't exists, returns 0
//// Will return nonzero value file verification passes
//int readFile(string& filepath, vector<string>& lines) {
//	ifstream myfile(filepath);
//	string s;
//
//	if (!myfile)
//	{
//		cout << "Cannot open the File:\t" << filepath << endl;
//		return 0;
//	}
//
//	int i = 0;
//	while (getline(myfile, s)) {
//		lines.insert(lines.end(), s);
//	}
//
//	myfile.close();
//	return 1;
//}

// Reads file into vector
 vector<string> inputFromFile(string& filepath){
	ifstream myfile(filepath);
	vector<string> vec;
	string s;

	if (!myfile)
	{
		return vec;
	}

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

//vector<int> state(int x, int y) {
//	return 
//}


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
					std::cout << "say: " << "0" << std::endl;
					puzzleSize.push_back(states);
				} 
				else if (incr == 1) {
					std::cout << "say: " << "1" << std::endl;
					initialState.push_back(states);
				}
				else if (incr == 2) {
					std::cout << "say: " << "2" << std::endl;;
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

	//cout << "Original" << endl;
	//for (auto i : fileDataZ) {
	//	for (auto j : i) {
	//		cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << endl;
	//	}
	//}

	//cout << "Puzzle Size" << endl;
	//for (auto i : puzzleSize) {
	//	for (auto j : i) {
	//		cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << endl;
	//	}
	//}

	//cout << "Initial State" << endl;
	//for (auto i : initialState) {
	//	for (auto j : i) {
	//		cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << endl;
	//	}
	//}

	//cout << "Goal States" << endl;
	//for (auto i : goalStates) {
	//	for (auto j : i) {
	//		cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << endl;
	//	}
	//}

	//cout << "llegal States" << endl;
	//for (auto i : illegalStates) {
	//	for (auto j : i) {
	//		cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << endl;
	//	}
	//}


	// Setup Puzzle
	Puzzle map(puzzleSize[0][0].x, puzzleSize[0][0].y, initialState[0], goalStates[0], illegalStates[0]);	


	// Search Method
	searchMethod smptr = nullptr;

	// Main L
	if (method == "dfs") {
		cout << "You have chosen Depth-First Search (DFS).\nWorking..." << endl;
	}
	else if (method == "bfs") {
		cout << "You have chosen Breadth-First Search(BFS).\nWorking..." << endl;

	}
	else if (method == "gbfs") {
		cout << "You have chosen Greedy Best First Search (GBFS).\nWorking..." << endl;

	}
	else if (method == "as") {
		cout << "You have chosen A* ('A Star' or AS).\nWorking..." << endl;

	}
	else if (method == "cus1") {
		cout << "You have chosen (CUS1).\nWorking..." << endl;

	}
	else if (method == "cus2") {
		cout << "You have chosen (CUS2).\nWorking..." << endl;

	}
	else {
		cout << "Not a valid method type!" << endl;
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

