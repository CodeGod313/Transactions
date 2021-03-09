#pragma once
#include <string>
#include <memory>
#include "Product.h"
#include <iostream>
#include <vector>
#include "Book.h"
#include "Magazine.h"
#include "NewsPaper.h"

class Employe
{
private:
	std::string name, surName, middleName;
protected:
	enum Role
	{
		CHIEF,
		CORR,
		LEAD
	}role;
	std::shared_ptr<Product> currentProduct;
public:
	Employe(std::string name, std::string surname, std::string middleName, Role role) 
	{
		this->middleName = middleName;
		this->name = name;
		this->surName = surname;
		this->role = role;
	}
	void selectProject(std::vector<std::shared_ptr<Product>> &products);
	std::string getName();
	std::string getSurname();
	std::string getMiddleName();
	std::shared_ptr<Product> getCurrenProduct();
	int getRole();
	void showInfo();
	void quitProject();
};

