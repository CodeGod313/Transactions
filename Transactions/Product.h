#pragma once
#include <string>
#include <memory>
class Product
{
private:
	static int idSeed;
protected:
	enum ProductType
	{
		BOOK,
		NEWSPAPER,
		MAGAZINE
	}type;
	int id;
	std::string name;
public:
	Product();
	Product(std::string name, ProductType type);
	std::string  getName();
	void setName(std::string name);
	int getId();
	int getType();
	virtual void inf();
};

