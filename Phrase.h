#pragma once

#include "Generator.h"

#include <vector>


class Phrase : public Generator
{
public:
	Phrase(std::string dictionaryPath);
	~Phrase();

	void Generate() override;

protected:
	void CreatePassword() override;

protected:
	std::vector<std::string> dictionary;
	std::string dictionaryPath;
};


