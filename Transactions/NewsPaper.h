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
	std::vector<std::shared_ptr<Column>> Columns;
public:
	NewsPaper(Date date, int number, std::string name);
	NewsPaper(const NewsPaper &other);
	Date getDate();
	int getNumber();
	void setDate(Date date);
	void setNumber(int number);
	void addColumn(std::shared_ptr<Column> column);
	bool remColumn(int priority);
	void inf() override;
};

