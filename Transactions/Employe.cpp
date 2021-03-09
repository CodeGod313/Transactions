#include "Employe.h"

void Employe::selectProject(std::vector<std::shared_ptr<Product>> &products)
{
	for (int i = 0; i < products.size(); i++)
	{
		std::cout << "Project #" << i+1 << std::endl;
		switch (products[i]->getType())
		{
		case 0: // book
			((Book *)(products[i].get()))->inf();
			break;
		case 1: // newspaper
			((NewsPaper *)(products[i].get()))->inf();
			break;
		case 2: // magazine
			((Magazine *)(products[i].get()))->inf();
			break;
		}
	}
	std::cout << "Selected:" << std::endl;
	int choice;
	std::cin >> choice;
	currentProduct = products[choice - 1];
}

std::string Employe::getName()
{
	return name;
}

std::string Employe::getSurname()
{
	return surName;
}

std::string Employe::getMiddleName()
{
	return middleName;
}

std::shared_ptr<Product> Employe::getCurrenProduct()
{
	return currentProduct;
}

int Employe::getRole()
{
	return role;
}

void Employe::showInfo()
{
	std::cout << name << " " << surName << " " << middleName << std::endl;
	std::cout << "Role: ";
	switch (role)
	{
	case Employe::CHIEF:
		std::cout << "Chief editor" << std::endl;
		break;
	case Employe::CORR:
		std::cout << "Corrector" << std::endl;
		break;
	case Employe::LEAD:
		std::cout << "Lead editor" << std::endl;
		break;
	default:
		break;
	}
}

void Employe::quitProject()
{
	currentProduct.reset();
}
