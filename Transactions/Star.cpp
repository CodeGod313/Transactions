#include "Star.h"
Star::Star(std::string name, std::string surName, std::string middleName, int domain)
{
	this->name = name;
	this->surName = surName;
	this->middleName = middleName;
	switch (domain)
	{
	case 1:
		this->domain = MUSIC;
		break;
	case 2:
		this->domain = CINEMA;
		break;
	case 3:
		this->domain = ART;
		break;
	case 4:
		this->domain = FASHION;
		break;
	default:
		break;
	}
}

std::string Star::getName()
{
	return name;
}

std::string Star::getSurName()
{
	return surName;
}

std::string Star::getMiddleName()
{
	return middleName;
}

void Star::inf()
{
	std::cout << name << " " << surName << " " << middleName << std::endl;
	std::cout << "Domain: ";
	switch (domain)
	{
	case Star::MUSIC:
		std::cout << "Music" << std::endl;
		break;
	case Star::CINEMA:
		std::cout << "Cinema" << std::endl;
		break;
	case Star::ART:
		std::cout << "Art" << std::endl;
		break;
	case Star::FASHION:
		std::cout << "Fashion" << std::endl;
		break;
	default:
		break;
	}
}
