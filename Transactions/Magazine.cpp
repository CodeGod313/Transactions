#include "Magazine.h"

Magazine::Magazine(int number, std::string name) : Product(name)
{
	this->number = number;
}

int Magazine::getNumber()
{
	return number;
}

void Magazine::addStar(std::unique_ptr<Star> u)
{
	stars.resize(stars.size() + 1);
	stars[stars.size() - 1] = std::move(u);
}
