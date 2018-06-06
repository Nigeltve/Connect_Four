#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNames(string &nameX, string &nameO) {
	cout << "Lets Play some TicTacToe" << endl;
	cout << "who will be player X: ";
	cin >> nameX;
	cout << "Ok " << nameX << " Will be playing as X" << endl << endl;

	std::cout << "who will be player O: ";
	std::cin >> nameO;
	std::cout << "Ok " << nameO << " Will be playing as O" << std::endl << std::endl;
}