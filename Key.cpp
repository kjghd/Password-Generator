#include "Key.h"

#include <iostream>
#include <random>
#include <ctime>


bool Key::IsUpper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}
bool Key::IsLower(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}
bool Key::IsNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
bool Key::IsSymbol(char c)
{
	return true;
}
bool Key::ContainsAll()
{
	bool upper{ false };
	bool lower{ false };
	bool number{ false };
	bool symbol{ false };

	for (const char& c : password)
	{
		if		(IsUpper(c)) upper = true;
		else if (IsLower(c)) lower = true;
		else if (IsNumber(c)) number = true;
		else if (IsSymbol(c)) symbol = true;
	}

	return upper && lower && number && symbol;
}

void Key::CreatePassword()
{
	password.clear();

	for (size_t i{ 0 }; i < length; ++i)
	{
		password.push_back(std::rand() % ('~' - ' ') + ' ');
	}
}

void Key::Generate()
{
	ClearConsole();

	for (size_t i = 0; i < amount; i++)
	{
		password.clear();

		while (!ContainsAll()) CreatePassword();
		
		std::cout << password << std::endl;
	}
}

Key::Key()
	:
	Generator(8, 1)
{
}
Key::~Key()
{
}
