#pragma once
#include "Product.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Book : public Product
{
private:
	std::string author;
	std::vector<std::string> coAutors;
	int pages;
public:
	Book(std::string name, std::string author, int pages);
	std::string getAuthor();
	int getPages();
};
