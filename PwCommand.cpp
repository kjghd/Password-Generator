#include "PwCommand.h"

PwCommand::PwCommand(std::string dictionaryPath)
	:
	command(),
	key(),
	phrase(dictionaryPath)
{
}

void PwCommand::GetCommand()
{
	command.Clear();
	command.ResetPosition();

	command.GetCommand();
}

void PwCommand::TryCommand()
{
	if (command.GetNextWord() == "Key")
	{
		
	}
}