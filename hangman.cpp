#include "hangman.hpp"
#include<iostream>


void Game::initialize()
{
	std::cout << "Gra Wisielec." << std::endl;
	std::cout << "Masz 5 prob by zgadanc haslo. " << std::endl;
	Round round;
	round.start("kon");

	while (round.checkStatus() == Result::ON)
	{
		char letter;

		std::cout << "Podaj literke: " << std::endl;
		std::cin >> letter;

		if (round.guessLetter(letter))
		{
			std::cout << "Zgadles!" << std::endl;
		}
		else
		{
			std::cout << "Literka nie znajduje sie w hasle." << std::endl;
		}
	}

	if (round.checkStatus() == Result::WIN)
	{
		std::cout << "Wygrales" << std::endl;
	}
	else if (round.checkStatus() == Result::LOSE)
	{
		std::cout << "Przegrales" << std::endl;
	}
}
void Round::start(std::string password)
{
	this->tryCount = 0;
	this->password = password;
	this->currentPassword = password;
	for (int i = 0; i < this->password.length(); i++)
	{
		this->currentPassword[i] = '_';
	}
}

bool Round::guessLetter(char letter)
{
	bool matched = false;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == letter)
		{
			currentPassword[i] = letter;
			matched = true;
		}
	}
	if (matched == false) 
	{
		tryCount++;
	}
	return matched;
}
