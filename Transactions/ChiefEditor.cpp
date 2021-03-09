#include "ChiefEditor.h"

ChiefEditor::ChiefEditor(std::string name, std::string surName, std::string middleName) : Employe(name, surName, middleName, CHIEF)
{
	commitedTransactions = 0;
	publishedProducts = 0;
}

void ChiefEditor::commitTransaction(std::vector<Transaction<Product>>& transactions)
{
	if (transactions.size() == 0)
	{
		std::cout << "No transactions" << std::endl;
		return;
	}
	for (int i = 0; i < transactions.size(); i++)
	{
		std::cout << "Transaction #" << i + 1 << std::endl;
		transactions[i].inf();
	}
	std::cout << "Select:" << std::endl;
	int choice1;
	do
	{
		std::cin >> choice1;
	} while (choice1 < 1 || choice1 > transactions.size());
	std::cin >> choice1;
	std::cout << "1 - Commit\n 2 - Revoke\n";
	int choice2;
	do
	{
		std::cin >> choice2;
	} while (choice2 != 1 || choice2 != 2);
	switch (choice2)
	{
	case 1:
		transactions[choice1 - 1].commit();
		break;
	case 2:
		transactions[choice1 - 1].revoke();
		transactions.erase(transactions.begin() + choice1 - 1, transactions.begin() + choice1);
		break;
	default:
		break;
	}
}

void ChiefEditor::publish()
{
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

void ChiefEditor::createProduct(std::vector<std::shared_ptr<Product>>& products)
{
	int choice;
	std::cout << "1 - Book" << std::endl << "2 - NewsPaper" << std::endl << "3 - Magazine" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		std::string name, author;
		int pages;
		std::cout << "Enter the title" << std::endl;
		rewind(stdin);
		std::getline(std::cin, name);
		std::cout << "Enter author" << std::endl;
		rewind(stdin);
		std::getline(std::cin, author);
		std::cout << "Enter the quantity of pages" << std::endl;
		std::cin >> pages;
		while (pages<0)
		{
			rewind(stdin);
			std::cout << "Wrong value" << std::endl;
			std::cin >> pages;
		}
		std::shared_ptr<Book> book(new Book(name, author, pages));
		products.resize(products.size() + 1);
		products[products.size() - 1] = book;
		std::cout << "Added" << std::endl;
	}
	break;
	case 2:
	{
		std::cout << "Enter date" << std::endl;
		int year, month, day;
		std::cin >> day >> month >> year;
		while (day < 0 || day > 31 || month < 1 || month > 12 || year < 0 || year > 2020)
		{
			std::cout << "Wrong data" << std::endl;
			rewind(stdin);
			std::cin >> day >> month >> year;
		}
		Date date(day, month, year);
		std::cout << "Enter the number" << std::endl;
		int number;
		std::cin >> number;
		while (number < 0)
		{
			std::cout << "Enter dood number" << std::endl;
			rewind(stdin);
			std::cin >> number;
		}
		std::string name;
		std::cout << "Enter the title" << std::endl;
		rewind(stdin);
		std::getline(std::cin, name);
		std::shared_ptr<NewsPaper> newsPaper(new NewsPaper(date, number, name));
		products.resize(products.size() + 1);
		products[products.size() - 1] = newsPaper;
		std::cout << "Added" << std::endl;
	}
	break;
	case 3:
	{
		std::string name;
		int number;
		std::cout << "Enter the title" << std::endl;
		rewind(stdin);
		std::getline(std::cin, name);
		std::cout << "Enter the number" << std::endl;
		std::cin >> number;
		while (number < 0)
		{
			std::cout << "Enter dood number" << std::endl;
			rewind(stdin);
			std::cin >> number;
		}
		std::shared_ptr<Magazine> magazine(new Magazine(number, name));
		products.resize(products.size() + 1);
		products[products.size() - 1] = magazine;
		std::cout << "Added" << std::endl;
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
