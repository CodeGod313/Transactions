#include "NewsPaper.h"

NewsPaper::NewsPaper(Date date, int number, std::string name) : Product(name)
{
	this->date = date;
	this->number = number;
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

void NewsPaper::addColumn(std::unique_ptr<Column> column)
{
	Columns.resize(Columns.size() + 1);
	Columns[Columns.size() - 1] = std::move(column);
}
