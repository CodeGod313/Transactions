#pragma once
#include <vector>
#include "Star.h"
#include <memory>
#include "Product.h"

class Magazine : public Product
{
private:
	int number;
	std::vector<std::unique_ptr<Star>> stars;
public:
	Magazine(int number, std::string name);
	int getNumber();
	void setNumber(int number);
	void addStar(std::unique_ptr<Star> &u);
	bool remStar(std::string name, std::string surName);//nnn
};

