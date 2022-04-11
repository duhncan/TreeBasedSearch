#pragma once

#include <iostream>
void messageActionPrompt() {
	std::cout << "\nPlease enter your command:"
		<< "\nInput:\t";
}

void messageWelcome() {
	std::cout << "Welcome to Assignment 1 - Tree Search"
		<< "\nBy Duhncan Guy - 102093756"
		<< std::endl;
}

void messageLeave() {
	std::cout << "\nThanks for using Duhncan's Tree Search!\nHope to see you again soon!" << std::endl;
}

void messageHelp() {
	std::cout << "This program takes 3 arguments in the format of (action) (filename) (method)"
		<< "\n\taction:\t\t can either take one of three parameters"
		<< "\n\t\t\t - search:this will allow you to specify a filename and method to use for searching."
		<< "\n\t\t\t - exit:exits the program."
		<< "\n\t\t\t - help:shows the user how to use the program."
		<< "\n\tfilename:\ttakes the name of a '.txt' file that is in the root directory of this program to use for the search."
		<< "\n\tmethod:\t\tspecifies the search method to use for your search request."
		<< std::endl;
}

void messageError(std::string msg) {
	std::cout << "Illegal action: " << msg << std::endl;
}

void messageInputArgumentsError() {
	std::cout << "Incorrect arguments given! Please try again." << std::endl;
	std::cout << "Type 'help' for a detailed explanation on the format of this program!" << std::endl;
}

void messageActionError() {
	std::cout << "First argument given is not 'search', 'exit', or 'help'.\nPlease try again!" << std::endl;
}

void messageFileError() {
	std::cout << "File failed to open.\nPlease try again!" << std::endl;
}

void messageInputFileError() {
	std::cout << "Invalid input file format!"
		<< "\nEnsure the first three lines of the file depict : "
		<< "\n\t - The Grid Size"
		<< "\n\t - The Initial State of the Agent"
		<< "\n\t - The Goal State of the Agent"
		<< std::endl;
	std::cout << "Type 'help' for a detailed explanation on the format of this program!" << std::endl;
}

//static void messageInputFormat() {
//	std::cout << "Input Format: \tsearch (filename) (method)"
//		"\n\t\tfilename - \tthe name of a '.txt' file in the root directory of the program."
//		"\n\t\tmethod - \tThe usable methods are BFS, DFS, GBFS, AS, CUS1, CUS2."
//		<< std::endl;
//}