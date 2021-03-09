#pragma once
#include <vector>
#include "Star.h"
#include <memory>
#include "Product.h"
#include <iostream>

class Magazine : public Product
{
private:
	int number;
	std::vector<std::shared_ptr<Star>> stars;
public:
	Magazine(int number, std::string name);
	Magazine(const Magazine &other);
	int getNumber();
	void setNumber(int number);
	void addStar(std::shared_ptr<Star> u);
	bool remStar(std::string name, std::string surName);
	void inf() override;
};

