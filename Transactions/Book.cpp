#include "Book.h"

Book::Book(std::string name, std::string author, int pages) : Product(name)
{
	this->author = author;
	this->pages = pages;
}

std::string Book::getAuthor()
{
	return author;
}

int Book::getPages()
{
	return pages;
}
