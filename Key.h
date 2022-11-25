#pragma once

#include "Generator.h"

class Key : public Generator
{
public:
	Key();
	~Key();

	void Generate() override;

protected:
	bool IsUpper(char c);
	bool IsLower(char c);
	bool IsNumber(char c);
	bool IsSymbol(char c);
	bool ContainsAll();

	void CreatePassword() override;
};
