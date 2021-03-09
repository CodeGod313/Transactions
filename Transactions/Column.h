#pragma once
#include <string>
class Column
{
private:
	std::string text;
	int priority;
public:
	Column(std::string text, int priority);
	std::string getText();
	int getPriority();
	void setPriority(int priority);
	void app(std::string str);
	void setNewText(std::string text);
};

