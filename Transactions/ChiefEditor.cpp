#include "ChiefEditor.h"

ChiefEditor::ChiefEditor(std::string name, std::string surName, std::string middleName) : Employe(name, surName, middleName, CHIEF)
{
	commitedTransactions = 0;
	publishedProducts = 0;
}

void ChiefEditor::employ(std::vector<std::shared_ptr<Employe>>& employes)
{
	std::cout << "1 - Lead editor\n 2 - Corrector" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		employes.resize(employes.size() + 1);
		std::string name, surName, middleName;
		std::cout << "Enter name, surname and middlename" << std::endl;
		std::cin >> name >> surName >> middleName;
		std::shared_ptr<LeadEditor> lead(new LeadEditor(name, surName, middleName));
		employes[employes.size() - 1] = lead;
	}
	break;
	case 2:
	{
		employes.resize(employes.size() + 1);
		std::string name, surName, middleName;
		std::cout << "Enter name, surname and middlename" << std::endl;
		std::cin >> name >> surName >> middleName;
		std::shared_ptr<Corrector> corr(new Corrector(name, surName, middleName));
		employes[employes.size() - 1] = corr;
	}
	break;
	default:
		std::cout << "Wrong choice" << std::endl;
		break;
	}
}

int ChiefEditor::getCommitedTransactions()
{
	return commitedTransactions;
}

int ChiefEditor::getPublishedProducts()
{
	return publishedProducts;
}
