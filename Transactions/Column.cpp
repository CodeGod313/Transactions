#include "Column.h"

Column::Column(std::string text)
{
	this->text = text;
}

std::string Column::getText()
{
	return text;
}

void Column::app(std::string str)
{
	text += str;
}

void Column::setNewText(std::string text)
{
	this->text = text;
}
