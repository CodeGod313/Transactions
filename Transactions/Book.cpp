#include "Book.h"

Book::Book(std::string name, std::string author, int pages) : Product(name, BOOK)
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
	this->type = BOOK;
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

int Book::getAuthorQ()
{
	return coAuthors.size();
}

std::vector<std::string> Book::getCoauthors()
{
	return coAuthors;
}

void Book::inf()
{
	std::cout << "Title: " << name << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Co-authors" << std::endl;
	for (int i = 0; i < coAuthors.size(); i++)
	{
		std::cout << coAuthors[i] << std::endl;
	}
}

void Book::modify(std::shared_ptr<Product> book)
{

	//std::shared_ptr<Book> book1((Book *)book.get());
	this->author = ((Book *)book.get())->getAuthor();
	this->pages = ((Book *)book.get())->getPages();
	this->coAuthors.resize(((Book *)book.get())->getAuthorQ());
	for (int i = 0; i < coAuthors.size(); i++)
	{
		this->coAuthors[i] = ((Book *)book.get())->getCoauthors()[i];
	}
	this->name = ((Book *)book.get())->getName();
	this->id = ((Book *)book.get())->getId();
	this->type = BOOK;
}

void Book::printToFile(std::ofstream & fout)
{
	fout << "Title: " << name << std::endl;
	fout << "Author: " << author << std::endl;
	fout << "Co-authors" << std::endl;
	for (int i = 0; i < coAuthors.size(); i++)
	{
		fout << coAuthors[i] << std::endl;
	}
}
