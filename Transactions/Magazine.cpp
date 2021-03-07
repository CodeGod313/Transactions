#include "Magazine.h"

Magazine::Magazine(int number, std::string name) : Product(name)
{
	this->number = number;
}

Magazine::Magazine(const Magazine & other)
{
	this->number = other.number;
	this->id = other.id;
	this->stars.resize(other.stars.size());
	for (int i = 0; i < other.stars.size(); i++)
	{
		this->stars[i] = other.stars[i];
	}
}

int Magazine::getNumber()
{
	return number;
}

void Magazine::setNumber(int number)
{
	this->number = number;
}

void Magazine::addStar(std::shared_ptr<Star> &u)
{
	stars.resize(stars.size() + 1);
	stars[stars.size() - 1].swap(u);
}

bool Magazine::remStar(std::string name, std::string surName)
{
	for (int i = 0; i < stars.size(); i++) {
		if (stars[i]->getName() == name && stars[i]->getSurName() == surName) {
			stars.erase(stars.begin() + i, stars.begin() + i + 1);
			return true;
		}
	}
	return false;
}
