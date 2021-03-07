#pragma once
#include <string>
#include <memory>
class Product
{
private:
	static int idSeed;
protected:
	int id;
	std::string name;
public:
	Product();
	Product(std::string name);
	std::string  getName();
	void setName(std::string name);
	int getId();
	virtual void modify(std::shared_ptr<Product> obj, std::string args);
};

