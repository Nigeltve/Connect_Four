#pragma once
#include <iostream>
#include <string>

using namespace std;
class Player
{
private:
	std::string playerName;
	char playerIcon;

public:
	Player(std::string name, char icon);
	char getIcon() const;
	std::string getName() const;
	int getMove();
	void printInfo();
};

