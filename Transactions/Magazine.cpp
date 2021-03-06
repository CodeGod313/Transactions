#include "Magazine.h"

Magazine::Magazine(int number, std::string name) : Product(name)
{
	this->number = number;
}

int Magazine::getNumber()
{
	return number;
}

void Magazine::setNumber(int number)
{
	this->number = number;
}

void Magazine::addStar(std::unique_ptr<Star> &u)
{
	stars.resize(stars.size() + 1);
	stars[stars.size() - 1] = std::move(u);
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
