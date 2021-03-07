#include "Product.h"

int Product::idSeed = 0;

Product::Product()
{

}

Product::Product(std::string name)
{
	this->name = name;
	this->id = ++idSeed;
}

std::string Product::getName()
{
	return name;
}

void Product::setName(std::string name)
{
	this->name = name;
}

int Product::getId()
{
	return id;
}

void Product::modify(std::shared_ptr<Product> obj, std::string args)
{
	return;
}
