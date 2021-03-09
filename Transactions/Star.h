#pragma once
#include <string>
#include <iostream>
class Star
{
private:
	enum Domain
	{
		MUSIC,
		CINEMA,
		ART,
		FASHION
	}domain;
	std::string name;
	std::string surName;
	std::string middleName;
public:
	Star(std::string name, std::string surName, std::string middleName, int domain);
	std::string getName();
	std::string getSurName();
	std::string getMiddleName();
	void inf();
};

