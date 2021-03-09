#include "Column.h"

Column::Column(std::string text, int priority)
{
	this->text = text;
	this->priority = priority;
}

std::string Column::getText()
{
	return text;
}

int Column::getPriority()
{
	return priority;
}

void Column::setPriority(int priority)
{
	this->priority = priority;
}

void Column::app(std::string str)
{
	text += str;
}

void Column::setNewText(std::string text)
{
	this->text = text;
}
