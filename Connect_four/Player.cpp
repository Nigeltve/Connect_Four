#include "Player.h"

Player::Player(std::string name, char icon)
{
	playerName = name;
	playerIcon = icon;
}

char Player::getIcon() const
{
	return playerIcon;
}

std::string Player::getName() const
{
	return playerName;
}

int Player::getMove()
{
	int move;
	std::cout << playerName << ", it is your turn. Where do you place your " << playerIcon << ": ";
	std::cin >> move;
	return move;
}

void Player::printInfo() {
	std::cout << playerName << " " << playerIcon;
	std::cout << std::endl << std::endl;
}