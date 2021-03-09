#include "Magazine.h"

Magazine::Magazine(int number, std::string name) : Product(name, MAGAZINE)
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
	this->type = MAGAZINE;
}

int Magazine::getNumber()
{
	return number;
}

void Magazine::setNumber(int number)
{
	this->number = number;
}

void Magazine::addStar(std::shared_ptr<Star> u)
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

void Magazine::inf()
{
	std::cout << "Title: " << name << std::endl;
	for (int i = 0; i < stars.size(); i++)
	{
		std::cout << "Star #" << i + 1 << std::endl;
		stars[i]->inf();
	}
}

std::vector<std::shared_ptr<Star>> Magazine::getStars()
{
	return stars;
}

void Magazine::modify(const std::shared_ptr<Product> &prod)
{
	std::shared_ptr<Magazine> other((Magazine *)prod.get());
	this->number = other->getNumber();
	this->id = other->getId();
	this->stars.resize(other->getStars().size());
	for (int i = 0; i < other->getStars().size(); i++)
	{
		this->stars[i] = other->getStars()[i];
	}
	this->type = MAGAZINE;
}
