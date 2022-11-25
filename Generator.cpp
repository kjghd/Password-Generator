#include "Generator.h"

#include <iostream>
#include <random>
#include <ctime>


void Generator::CreatePassword()
{

}

void Generator::ClearPassword()
{
	for (auto& c : password)
		c = rand() % 0xFF;

	password.clear();
}

bool Generator::SetLength(size_t uLength)
{
	if (uLength < lengthMin)
	{
		std::cout << "Length must be at least " << lengthMin << std::endl;
		return false;
	}
	else
	{
		length = uLength;
		return true;
	}
}
bool Generator::SetAmount(size_t uAmount)
{
	if (uAmount < amountMin)
	{
		std::cout << "Amount must be at least " << amountMin << std::endl;
		return false;
	}
	else
	{
		amount = uAmount;
		return true;
	}
}

void Generator::Reset()
{
	ClearPassword();
	length = 0;
	amount = 0;
}

void Generator::Generate()
{

}

void Generator::ClearConsole()
{
	system("cls");
}

Generator::Generator(size_t min_length, size_t min_amount)
	:
	length(0),
	lengthMin(min_length),
	amount(0),
	amountMin(min_amount),
	password()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}
Generator::~Generator()
{
	ClearPassword();
}
