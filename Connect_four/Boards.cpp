#include "Boards.h"


std::vector<char> replace(int loc, char replace, std::vector<char> vec);

Boards::Boards()
{	
	// initializes the board with empty spaces
	for (int i = 0; i < 16; i++) {
		boardSpace.push_back('_');
	}
}

void Boards::setPosition(int position, char icon) 
{
	boardSpace = replace(position, icon, boardSpace);
}

int Boards::getBoardSize() const
{
	return 16;
}

std::vector<char> Boards::getBoardState() {
	return boardSpace;
}



bool Boards::checkPosition(int position) {
	//see if given position is free or not.
	std::vector<char>::iterator iter;
	iter = boardSpace.begin() + position;
	if (*iter != '_') {
		return false;
	}
	return true;
}

void Boards::printBoard() {
	//prints the board.
	std::vector<char>::iterator iter;
	int i = 1;
	for (iter = boardSpace.begin(); iter != boardSpace.end(); ++iter) {
		std::cout << ' ' << '|' << std::setw(3) << *iter;
		if (i % 4 == 0) {
			std::cout << ' ' << '|' << std::endl;
		}
		i++;
	}
	std::cout << std::endl;
}

void Boards::printLegalMoves() {
	/* prints all legal moves like if it was a board.
	   spaces that are not taken are numbers. 
	   taken spaces are represented as '-'
	*/
	std::vector<int> legalMoves;
	std::vector<int>::iterator iterInt;
	std::vector<char>::iterator iter;

	std::cout << "All legal moves that you can make." << std::endl;
	int i = 0;
	for (iter = boardSpace.begin(); iter != boardSpace.end(); ++iter) {
		if (*iter == '_') {
			legalMoves.push_back(i);
		}
		else {
			legalMoves.push_back(-1);
		}
		i++;
	}

	i = 1;
	for (iterInt = legalMoves.begin(); iterInt != legalMoves.end(); ++iterInt) {
		if (*iterInt != -1) {
			std::cout << ' ' << '|' << std::setw(3) << *iterInt;
		}
		else {
			std::cout << ' ' << '|' << std::setw(3) << '-';
		}
		
		if (i % 4 == 0) {
			std::cout << ' ' << '|' << std::endl;
		}
		
		i++;
	}
	std::cout << std::endl << std::endl;
}

char Boards::testRow()
{
	//checks rows for winners

	int fourRowX = 0;
	int fourRowO = 0;

	for (int row = 0; row < 16; row += 4) {
		for (int i = 0; i < 4; i++) {
			if (boardSpace[i + row] == 'X') {
				fourRowX++;
			}
			if (boardSpace[i + row] == 'O') {
				fourRowO++;
			}
		}
		if (fourRowX == 4) {
			return 'X';
		}
		else if (fourRowO == 4) {
			return 'O';
		}
		fourRowX = 0;
		fourRowO = 0;

	}
	return 'z';
}

char Boards::testCol()
{
	//checks columns for winners
	int fourColX = 0;
	int fourColO = 0;
	for (int col = 0; col < 4; col++) {
		for (int i = 0; i < 16; i += 4) {
			if (boardSpace[i + col] == 'X') {
				fourColX++;
			}
			if (boardSpace[i + col] == 'O') {
				fourColO++;
			}
		}
		if (fourColX == 4) {
			return 'X';
		}
		if (fourColO == 4) {
			return 'O';
		}
		fourColX = 0;
		fourColO = 0;
	}
	return 'z';
}

char Boards::testDiag()
{
	//checks diagalas for winners.

	int diagX = 0;
	int diagO = 0;
	for (int i = 0; i < 16; i += 5) {
		if (boardSpace[i] == 'X') {
			diagX++;
		}
		if (boardSpace[i] == 'O') {
			diagO++;
		}
	}
	if (diagX == 4) {
		return 'X';
	}
	if (diagO == 4) {
		return 'O';
	}
	diagX = 0;
	diagO = 0;

	for (int i = 3; i < 13; i += 3) {
		if (boardSpace[i] == 'X') {
			diagX++;
		}
		if (boardSpace[i] == 'O') {
			diagO++;
		}
	}
	if (diagX == 4) {
		return 'X';
	}
	if (diagO == 4) {
		return 'O';
	}
	diagX = 0;
	diagO = 0;

	return 'z';
}

char Boards::winnerIs()
{
	//checks to see who is the winner. if no one is the winner returns z

	char winner = 'z';
	winner = testRow();
	
	if (winner == 'z') {
		winner = testCol();
	}
	if (winner == 'z') {
		winner = testDiag();
	}
	
	return winner;
}

//helper function
std::vector<char> replace(int loc, char replace, std::vector<char> vec) {
	// just replaces a element in given char vector, at givin location, with given character.
	std::vector<char>::iterator iter_loc;
	iter_loc = vec.begin() + loc;
	vec.erase(iter_loc);

	vec.emplace(vec.begin() + loc, replace);

	return vec;
}