#include "NewsPaper.h"

NewsPaper::NewsPaper(Date date, int number, std::string name) : Product(name, MAGAZINE)
{
	this->date = date;
	this->number = number;
}

NewsPaper::NewsPaper(const NewsPaper & other)
{
	this->date = other.date;
	this->number = other.number;
	this->Columns.resize(other.Columns.size());
	for (int i = 0; i < other.Columns.size(); i++)
	{
		this->Columns[i] = other.Columns[i];
	}
	this->id = other.id;
	this->name = other.name;
	this->type = NEWSPAPER;
}

Date NewsPaper::getDate()
{
	return date;
}

int NewsPaper::getNumber()
{
	return number;
}

void NewsPaper::setDate(Date date)
{
	this->date = date;
}

void NewsPaper::setNumber(int number)
{
	this->number = number;
}

void NewsPaper::addColumn(std::shared_ptr<Column> column)
{
	Columns.resize(Columns.size() + 1);
	Columns[Columns.size() - 1].swap(column);
}

std::vector<std::shared_ptr<Column>> NewsPaper::getColumns()
{
	return Columns;
}

bool NewsPaper::remColumn(int priority)
{
	for (int i = 0; i < Columns.size(); i++) {
		if (Columns[i]->getPriority() == priority) {
			Columns.erase(Columns.begin() + i, Columns.begin() + i + 1);
			return true;
		}
	}
	return false;
}

void NewsPaper::inf()
{
	std::cout << "Title: " << name << std::endl << "Number: " << number << std::endl << "Date: ";
	date.inf();
	std::cout << std::endl;
}

void NewsPaper::modify(std::shared_ptr<Product> newsPaper1)
{
	//std::shared_ptr<NewsPaper> other((NewsPaper *)(newsPaper1.get()));
	this->date = ((NewsPaper *)(newsPaper1.get()))->getDate();
	this->number = ((NewsPaper *)(newsPaper1.get()))->getNumber();
	this->Columns.resize(((NewsPaper *)(newsPaper1.get()))->getColumns().size());
	for (int i = 0; i < ((NewsPaper *)(newsPaper1.get()))->getColumns().size(); i++)
	{
		this->Columns[i] = ((NewsPaper *)(newsPaper1.get()))->getColumns()[i];
	}
	this->id = ((NewsPaper *)(newsPaper1.get()))->getId();
	this->name = ((NewsPaper *)(newsPaper1.get()))->getId();
	this->type = NEWSPAPER;
}

void NewsPaper::printToFile(std::ofstream & fout)
{
	fout << "Title: " << name << std::endl << "Number: " << number << std::endl << "Date: ";
	fout << date.getDay() << " " << date.getMonth() << " " << date.getYear() << std::endl;
	fout << std::endl;
}
