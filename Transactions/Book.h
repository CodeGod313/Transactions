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
	std::vector<std::string> coAuthors;
	int pages;
public:
	Book(std::string name, std::string author, int pages);
	void addCoAuthor(std::string coAuthor);
	bool remCoAuthor(std::string coAuthor);
	void setPages(int pages);
	void setNewAuthor(std::string author);
	std::string getAuthor();
	int getPages();
};
