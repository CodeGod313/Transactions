#pragma once
#include <string>
#include <memory>
#include "Product.h"

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
	}
	std::string getName();
	std::string getSurname();
	std::string getMiddleName();
	int getRole();
	virtual void showInfo();
};

