#pragma once

#include <string>

class Command
{
	size_t position;
	std::string command;

public:
	void SetCommand();
	void ResetPosition();
	std::string GetNextWord();
	std::string GetCommand();
	void Clear();

	bool Try(std::string word);
};

