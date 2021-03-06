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
