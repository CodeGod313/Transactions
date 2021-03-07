#include "Book.h"

Book::Book(std::string name, std::string author, int pages) : Product(name)
{
	this->author = author;
	this->pages = pages;
}

Book::Book(const Book & book)
{
	this->author = book.author;
	this->pages = book.pages;
	this->coAuthors.resize(book.coAuthors.size());
	for (int i = 0; i < coAuthors.size(); i++)
	{
		this->coAuthors[i] = book.coAuthors[i];
	}
	this->name = book.name;
	this->id = book.id;
}

void Book::addCoAuthor(std::string coAuthor)
{
	coAuthors.push_back(coAuthor);
}

bool Book::remCoAuthor(std::string coAuthor)
{
	bool isDone = false;
	for (int i = 0; i < coAuthors.size(); i++) {
		if (coAuthors[i] == coAuthor) {
			coAuthors.erase(coAuthors.begin() + i, coAuthors.begin() + i + 1);
			isDone = true;
			break;
		}
	}
	return isDone;
}

void Book::setPages(int pages)
{
	this->pages = pages;
}

void Book::setNewAuthor(std::string author)
{
	this->author = author;
}

std::string Book::getAuthor()
{
	return author;
}

int Book::getPages()
{
	return pages;
}
