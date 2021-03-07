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

void NewsPaper::setNumber(int number)
{
	this->number = number;
}

void NewsPaper::addColumn(std::shared_ptr<Column> &column)
{
	Columns.resize(Columns.size() + 1);
	Columns[Columns.size() - 1].swap(column);
}

bool NewsPaper::remColumn(int query)
{
	for (int i = 0; i < Columns.size(); i++) {
		if (Columns[i]->getQuery() == query) {
			Columns.erase(Columns.begin() + i, Columns.begin() + i + 1);
			return true;
		}
	}
	return false;
}
