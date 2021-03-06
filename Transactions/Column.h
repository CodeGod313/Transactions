#pragma once
#include <string>
class Column
{
private:
	std::string text;
	int query;
public:
	Column(std::string text, int query);
	std::string getText();
	int getQuery();
	void setQuery(int query);
	void app(std::string str);
	void setNewText(std::string text);
};

