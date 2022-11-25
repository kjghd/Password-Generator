#include "Command.h"

#include <iostream>


std::string Command::GetNextWord()
{
	std::string buffer{};
	
	if (position < command.length())
	{
		size_t startPosition{ position };
		for (size_t i{ startPosition }; i < command.length(); ++i)
		{
			++position;

			if (command.at(i) == ' ')
			{
				//++position; // Step past the space.
				break;
			}
			else
				buffer.push_back(command.at(i));
		}
	}
	
	return buffer;
}

std::string Command::GetCommand()
{
	return command;
}

void Command::SetCommand()
{
	command.clear();
	std::getline(std::cin, command);
	position = 0;
}

void Command::ResetPosition()
{
	position = 0;
}

void Command::Clear()
{
	for (auto& c : command)
		c = rand() % 0xFF;
	command.clear();
}

bool Command::Try(std::string word)
{
	if (GetNextWord() == "key") return true;
}