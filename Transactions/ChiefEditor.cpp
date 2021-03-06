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
	while (!(std::cin >> choice1) || choice1 < 1 || choice1 > transactions.size())
	{
		std::cout << "Wrong" << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
	std::cout << "1 - Commit\n 2 - Revoke\n";
	int choice2;
	while (!(std::cin >> choice2) || (choice2 != 1 && choice2 != 2))
	{
		std::cout << "Wrong " << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
	switch (choice2)
	{
	case 1:
		transactions[choice1 - 1].commit();
		transactions.erase(transactions.begin() + choice1 - 1, transactions.begin() + choice1);
		break;
	case 2:
		transactions[choice1 - 1].revoke();
		transactions.erase(transactions.begin() + choice1 - 1, transactions.begin() + choice1);
		break;
	default:
		break;
	}
}

void ChiefEditor::publish(std::vector<std::shared_ptr<Product>> &products, std::vector<std::shared_ptr<Employe>>& employes, std::vector<Transaction<Product>> &transactions)
{
	if (products.size() == 0)
	{
		std::cout << "No products" << std::endl;
		system("pause");
		return;
	}
	for (int i = 0; i < products.size(); i++)
	{
		std::cout << "Product #" << i + 1 << std::endl;
		products[i]->inf();
	}
	int choice;
	std::cout << "Select:";
	while (!(std::cin >> choice) || choice < 1 || choice > products.size())
	{
		std::cout << "Wrong choice" << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
	for (int i = 0; i < employes.size(); i++)
	{
		if (employes[i]->getCurrenProduct() == products[choice - 1])
		{
			std::cout << "Someone is working on this" << std::endl;
			system("pause");
			return;
		}
	}
	for (int i = 0; i < transactions.size(); i++)
	{
		if (transactions[i].isUsed(products[choice - 1]))
		{
			std::cout << "Check transactions" << std::endl;
			system("pause");
			return;
		}
	}
	std::ofstream fout("Publications.txt", std::ios_base::app);
	if (!fout.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		system("pause");
		return;
	}
	switch (products[choice - 1]->getType())
	{
	case 0://book
		((Book *)products[choice - 1].get())->printToFile(fout);
		break;
	case 1: //newspaper
		((NewsPaper *)products[choice - 1].get())->printToFile(fout);
		break;
	case 2: //magazine
		((Magazine *)products[choice - 1].get())->printToFile(fout);
		break;
	}
	fout.close();
	products.erase(products.begin() + choice - 1, products.begin() + choice);
}

void ChiefEditor::employ(std::vector<std::shared_ptr<Employe>>& employes)
{
	std::cout << "1 - Lead editor\n 2 - Corrector" << std::endl;
	int choice;
	while (!(std::cin >> choice))
	{
		std::cout << "Wrong value" << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
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
	while (!(std::cin >> choice))
	{
		std::cout << "Wrong value" << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
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
		while (!(std::cin >> pages))
		{
			std::cout << "Wrong value" << std::endl;
			std::cin.clear();
			rewind(stdin);
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
			std::cin.clear();
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
		while (!(std::cin >> number) || number < 0)
		{
			std::cout << "Enter good number" << std::endl;
			std::cin.clear();
			rewind(stdin);
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
