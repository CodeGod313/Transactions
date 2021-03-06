#pragma once
#include "Product.h"
#include "Date.h"
#include "Column.h"
#include <string>
#include <vector>
#include <memory>


class NewsPaper : public Product 
{
private:
	Date date;
	int number;
	std::vector<std::unique_ptr<Column>> Columns;
public:
	NewsPaper(Date date, int number, std::string name);
	Date getDate();
	int getNumber();
	void setNumber(int number);
	void addColumn(std::unique_ptr<Column> column);
};

