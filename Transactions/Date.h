#pragma once
#include <string>
#include <iostream>

class Date
{
private:
	int day;
	int month;
	std::string monthStr;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	void inf();
	int getDay();
	std::string getMonth();
	int getYear();
};

