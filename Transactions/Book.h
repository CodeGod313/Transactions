#pragma once
#include "Product.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <fstream>

class Book : public Product
{
private:
	std::string author;
	std::vector<std::string> coAuthors;
	int pages;
public:
	Book(std::string name, std::string author, int pages);
	Book(const Book &book);
	void addCoAuthor(std::string coAuthor);
	bool remCoAuthor(std::string coAuthor);
	void setPages(int pages);
	void setNewAuthor(std::string author);
	std::string getAuthor();
	int getPages();
	int getAuthorQ();
	std::vector<std::string> getCoauthors();
	void inf() override;
	void modify(std::shared_ptr<Product> book);
	void printToFile(std::ofstream &fout);
};
