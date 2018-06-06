#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#ifndef BOARDS_H
#define BOARDS_H


class Boards
{
private:
	std::vector<char> boardSpace;

public:
	Boards();
	int getBoardSize() const;
	void printBoard();
	bool checkPosition(int position);
	void setPosition(int position, char icon);
	char testRow();
	char testCol();
	char testDiag();
	char winnerIs();
	void printLegalMoves();
	std::vector<char> getBoardState();

};

#endif