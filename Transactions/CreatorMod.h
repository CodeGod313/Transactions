#pragma once
#include <memory>
#include "Product.h"
#include "Book.h"
#include "Magazine.h"
#include "NewsPaper.h"
#include <iostream>

class CreatorMod
{
private:
	std::shared_ptr<Product> prod;
	int role;
	std::shared_ptr<Product> createAsChief(std::shared_ptr<Product> prod);
	std::shared_ptr<Product> createAsLead(std::shared_ptr<Product> prod);
	std::shared_ptr<Product> createAsCorr(std::shared_ptr<Product> prod);
public:
	CreatorMod(std::shared_ptr<Product> prod, int role);
	std::shared_ptr<Product> start();
};

