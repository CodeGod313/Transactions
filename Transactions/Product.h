#pragma once
#include <string>
#include <memory>
class Product
{
private:
	int id;
	static int idSeed;
	std::string name;
public:
	Product(std::string name);
	std::string  getName();
	int getId();
	virtual void modify(std::shared_ptr<Product> obj, std::string args);
};

