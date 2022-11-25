#pragma once
#include "Command.h"
#include "Key.h"
#include "Phrase.h"

class PwCommand
{
	Command command;
	Key key;
	Phrase phrase;

public:
	PwCommand(std::string dictionaryPath);
	void GetCommand();
	void TryCommand();
};

