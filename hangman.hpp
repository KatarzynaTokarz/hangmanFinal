#pragma once
#include<string>
#include <iostream>

enum class Result { ON, WIN, LOSE };

class Game
{
public:
	void initialize();
};

class Round
{
	int tryCount = 0;
	int allowedTries = 5;
	std::string password;
	std::string currentPassword;
public:
	void start(std::string password);
	bool guessLetter(char letter);

	Result checkStatus()
	{
		if (password.compare(currentPassword) == 0)
		{
			return Result::WIN;
		}
		else if (tryCount >= allowedTries)
		{
			return Result::LOSE;
		}
		else
		{
			return Result::ON;
		}
	}
};

