#include "Column.h"

Column::Column(std::string text, int query)
{
	this->text = text;
	this->query = query;
}

std::string Column::getText()
{
	return text;
}

int Column::getQuery()
{
	return query;
}

void Column::setQuery(int query)
{
	this->query = query;
}

void Column::app(std::string str)
{
	text += str;
}

void Column::setNewText(std::string text)
{
	this->text = text;
}
