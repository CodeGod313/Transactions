#include "Date.h"

Date::Date()
{

}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
	switch (month)
	{
	case 1:
		monthStr = "January";
		break;
	case 2:
		monthStr = "February";
		break;
	case 3:
		monthStr = "March";
		break;
	case 4:
		monthStr = "April";
		break;
	case 5:
		monthStr = "May";
		break;
	case 6:
		monthStr = "June";
		break;
	case 7:
		monthStr = "July";
		break;
	case 8:
		monthStr = "August";
		break;
	case 9:
		monthStr = "September";
		break;
	case 10:
		monthStr = "October";
		break;
	case 11:
		monthStr = "November";
		break;
	case 12:
		monthStr = "December";
		break;
	default:
		monthStr = "unknown";
		break;
	}
}

void Date::inf()
{
	std::cout << day << " ";
	if (monthStr != "unknown") {
		std::cout << monthStr << " " << year << std::endl;
	}
	else std::cout << month << " " << year << std::endl;
}

int Date::getDay()
{
	return day;
}

std::string Date::getMonth()
{
	return monthStr;
}

int Date::getYear()
{
	return year;
}
