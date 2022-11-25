#include "Key.h"
#include "Phrase.h"
#include "Command.h"

#include <iostream>

int main()
{
	std::cout << "Loading..." << std::endl;
	
	Phrase phrase("common_words.txt");
	Key key;
	Command command;
	
	system("cls");
	std::cout << "Ready" << std::endl;

	command.SetCommand();

	while (command.GetCommand() != "quit")
	{
		system("cls");

		if (command.GetNextWord() == "key")
		{
			bool l{ key.SetLength(std::stoul(command.GetNextWord())) };
			bool a{ key.SetAmount(std::stoul(command.GetNextWord())) };
			if (l && a)
			{
				if (command.GetNextWord().empty())
					key.Generate();
				else
					std::cout << "Unkown command." << std::endl;
			}

			key.Reset();
		}
		command.ResetPosition();

		if (command.GetNextWord() == "phrase")
		{
			bool l{ phrase.SetLength(std::stoul(command.GetNextWord())) };
			bool a{ phrase.SetAmount(std::stoul(command.GetNextWord())) };
			if (l && a)
			{
				if (command.GetNextWord().empty())
					phrase.Generate();
				else
					std::cout << "Unkown command." << std::endl;
			}

			phrase.Reset();
		}
		command.ResetPosition();

		std::cout << std::endl;
		command.SetCommand();
	}
}
