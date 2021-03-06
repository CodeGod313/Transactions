#pragma once
#include <string>
class Column
{
private:
	std::string text;
public:
	Column(std::string text);
	std::string getText();
	void app(std::string str);
	void setNewText(std::string text);

};

