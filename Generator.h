#pragma once
#include <string>

class Generator
{
public:
	Generator(size_t min_length, size_t min_amount);
	~Generator();

	bool SetLength(size_t uLength);
	bool SetAmount(size_t uAmount);

	void Reset();

	virtual void Generate();

protected:
	virtual void CreatePassword();

	void ClearPassword();

	void ClearConsole();

protected:
	size_t length;
	const size_t lengthMin;
	size_t amount;
	const size_t amountMin;
	std::string password;
};
