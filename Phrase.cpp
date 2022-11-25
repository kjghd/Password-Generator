#include "Phrase.h"

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>


void Phrase::CreatePassword()
{
	// Randomly pick words.
	std::vector<unsigned int> words;
	words.reserve(length);
	for (size_t i{ 0 }; i < length; ++i)
	{
		bool used{ true };
		while (used)
		{
			unsigned int position{ rand() % dictionary.size() };

			// Check if word is already in password.
			if (std::find(words.begin(), words.end(), position) == words.end())
			{
				words.push_back(position);
				used = false;
			}
			else
				used = true;
		}
	}

	// Allocate space for password.
	size_t size{ 0 };
	for (const auto& n : words)
		size += dictionary.at(n).length();
	password.clear();
	password.reserve(size);

	// Fill in password.
	for (size_t i{ 0 }; i < words.size(); ++i)
	{
		if (i == 0)
		{
			password += dictionary.at(words.at(i));
		}
		else
		{
			password += ' ';
			password += dictionary.at(words.at(i));
		}
	}

	// Clear Random word indexes
	//for (auto& u : words)
	//	u = rand() % 0xFF;

	password.clear();
}

Phrase::Phrase(std::string dictionaryPath)
	:
	Generator(4,1),
	dictionaryPath(dictionaryPath)
{
	// Load words from file.
	std::ifstream file;
	file.open(dictionaryPath);

	std::string buffer;
	while (std::getline(file, buffer))
		dictionary.push_back(buffer);

	file.close();
}
Phrase::~Phrase()
{
}

void Phrase::Generate()
{
	ClearConsole();

	for (size_t i = 0; i < amount; i++)
	{
		ClearPassword();

		CreatePassword();

		std::cout << password << std::endl;
	}
}