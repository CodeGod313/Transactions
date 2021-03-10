#include "CreatorMod.h"

std::shared_ptr<Product> CreatorMod::createAsChief(std::shared_ptr<Product> prod)
{

	return std::shared_ptr<Product>();
}

std::shared_ptr<Product> CreatorMod::createAsLead(std::shared_ptr<Product> prod)
{
	switch (prod->getType())
	{
	case 0: // BOOK
	{
		std::shared_ptr<Book> book(new Book(*((Book *)prod.get())));
		int choice;
		do
		{
			std::cout << "1. Add co-author\n 2. Set new author\n 3. Set quantity of pages\n 4. Start transaction\n 5. Cancel" << std::endl;
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
				std::string coAuthor;
				std::cout << "Enter co-autor's name" << std::endl;
				rewind(stdin);
				std::getline(std::cin, coAuthor);
				book->addCoAuthor(coAuthor);
				std::cout << "Added" << std::endl;
				system("pause");
			}
				break;
			case 2:
			{
				std::string author;
				std::cout << "Enter autor's name" << std::endl;
				rewind(stdin);
				std::getline(std::cin, author);
				book->setNewAuthor(author);
				std::cout << "Added" << std::endl;
				system("pause");
			}
				break;
			case 3:
			{
				int quantity;
				std::cout << "Enter quantity of pages" << std::endl;
				
				while (!(std::cin >> quantity) || quantity < 0)
				{
					std::cout << "Enter dood quantity" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				book->setPages(quantity);
				std::cout << "Seted" << std::endl;
				system("pause");
			}
				break;
			case 4:
			{
				std::cout << "Starting transaction" << std::endl;
				return book;
			}
				break;
			case 5:
			{
				std::cout << "Canceled" << std::endl;
				return NULL;
			}
				break;
			default:
			std::cout << "Wrong choice" << std::endl;
				break;
			}
		} while (choice != 5);
	}	
		break;
	case 1:// NEWSPAPER
	{
		std::shared_ptr<NewsPaper> newsPaper(new NewsPaper(*((NewsPaper *)prod.get())));
		
		int choice;
		do
		{
			std::cout << "1. Add a number\n 2. Add a column\n 3. Set new date\n 4. Start transaction\n 5. Cancel" << std::endl;
			while (!(std::cin >> choice)) {
				std::cout << "Wrong value" << std::endl;
				std::cin.clear();
				rewind(stdin);
			}
			switch (choice)
			{
			case 1:
			{
				int number;
				std::cout << "Enter number" << std::endl;
				
				while (!(std::cin >> number))
				{
					std::cout << "Enter good number" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				newsPaper->setNumber(number);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 2:
			{
				std::string text;
				std::cout << "Enter the text of column" << std::endl;
				rewind(stdin);
				std::getline(std::cin, text);
				int priority;
				std::cout << "Enter the priority" << std::endl;
				
				while (!(std::cin >> priority) || priority < 0)
				{
					std::cout << "Enter dood number" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				std::shared_ptr<Column> c(new Column(text, priority));
				newsPaper->addColumn(c);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 3:
			{
				std::cout << "Enter day, month and year" << std::endl;
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
				newsPaper->setDate(date);
				system("pause");
			}
			break;
			case 4:
			{
				std::cout << "Starting transaction" << std::endl;
				return newsPaper;
			}
			break;
			case 5:
			{
				std::cout << "Canceled" << std::endl;
				return NULL;
			}
			break;
			default:
				std::cout << "Wrong choice" << std::endl;
				break;
			}
		} while (choice != 5);
	}
	break;

	case 2: // MAGAZINE
	{
		std::shared_ptr<Magazine> magazine(new Magazine(*((Magazine *)prod.get())));
		
		int choice;
		do
		{
			std::cout << "1. Add a number\n 2. Add a star\n 3. Start transaction\n 4. Cancel" << std::endl;
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
				int number;
				std::cout << "Enter number" << std::endl;
				while (!(std::cin >> number) || number < 0)
				{
					std::cout << "Enter good number" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				magazine->setNumber(number);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 2:
			{
				std::string name, surName, middleName;
				int domain;
				std::cout << "Enter name, surname and middle name" << std::endl;
				std::cin >> name >> surName >> middleName;
				std::cout << "Enter domain:\n 1 - Music\n 2 - Cinema\n 3 - Art\n 4 - Fashion" << std::endl;
				while (!(std::cin >> domain) || domain < 1 || domain > 4)
				{
					std::cout << "Wrong" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				std::shared_ptr<Star> star(new Star(name, surName, middleName, domain));
				magazine->addStar(star);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 3:
			{
				std::cout << "Starting transaction" << std::endl;
				return magazine;
			}
			break;
			case 4:
			{
				std::cout << "Canceled" << std::endl;
				return NULL;
			}
			break;
			default:
				std::cout << "Wrong choice" << std::endl;
				break;
			}
		} while (choice != 5);

	}
		break;
	}
	return std::shared_ptr<Product>();
}

std::shared_ptr<Product> CreatorMod::createAsCorr(std::shared_ptr<Product> prod)
{
	switch (prod->getType())
	{
	case 0: // BOOK
	{
		std::shared_ptr<Book> book(new Book(*((Book *)prod.get())));
		
		int choice;
		do
		{
			std::cout << "1. Remove coauthor\n 2. Correct the quantity of pages\n  3. Start transaction\n 5. Cancel" << std::endl;
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
				std::string coAuthor;
				std::cout << "Enter co-autor's name" << std::endl;
				rewind(stdin);
				std::getline(std::cin, coAuthor);
				book->remCoAuthor(coAuthor);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 2:
			{
				int quantity;
				std::cout << "Enter quantity of pages" << std::endl;
				
				while (!(std::cin >> quantity) || quantity < 0)
				{
					std::cout << "Enter good quantity" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				book->setPages(quantity);
				std::cout << "Seted" << std::endl;
				system("pause");
			}
			break;
			case 3:
			{
				std::cout << "Starting transaction" << std::endl;
				return book;
			}
			break;
			case 4:
			{
				std::cout << "Canceled" << std::endl;
				return NULL;
			}
			break;
			default:
				std::cout << "Wrong choice" << std::endl;
				break;
			}
		} while (choice != 5);
	}
	break;
	case 1:// NEWSPAPER
	{
		std::shared_ptr<NewsPaper> newsPaper(new NewsPaper(*((NewsPaper *)prod.get())));
		
		int choice;
		do
		{
			std::cout << "1. Correct number\n 2. Remove column\n 3. Correct date\n 4. Start transaction\n 5. Cancel" << std::endl;
			while (!(std::cin >> choice))
			{
				std::cout << "Wrong value" << std::endl;
				std::wcin.clear();
				rewind(stdin);
			}

			switch (choice)
			{
			case 1:
			{
				int number;
				std::cout << "Enter number" << std::endl;
				while (!(std::cin >> number) || number < 0)
				{
					std::cout << "Enter good number" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				newsPaper->setNumber(number);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 2:
			{
				int priority;
				std::cout << "Enter the priority of column, which you wanna remove" << std::endl;
				while (!(std::cin >> priority) || priority < 0)
				{
					std::cout << "Enter dood number" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				if (newsPaper->remColumn(priority)) {
					std::cout << "Column not found" << std::endl;
				}
				else std::cout << "Removed" << std::endl;
				system("pause");
			}
			break;
			case 3:
			{
				int day, month, year;
				std::cout << "Enter day, month and year" << std::endl;
				std::cin >> day >> month >> year;
				while (day < 0 || day > 31 || month < 1 || month > 12 || year < 0 || year > 2020)
				{
					std::cout << "Wrong data" << std::endl;
					std::cin.clear();
					rewind(stdin);
					std::cin >> day >> month >> year;
				}
				Date date(day, month, year);
				newsPaper->setDate(date);
				system("pause");
			}
			break;
			case 4:
			{
				std::cout << "Starting transaction" << std::endl;
				return newsPaper;
			}
			break;
			case 5:
			{
				std::cout << "Canceled" << std::endl;
				return NULL;
			}
			break;
			default:
				std::cout << "Wrong choice" << std::endl;
				break;
			}
		} while (choice != 5);
	}
	break;

	case 2: // MAGAZINE
	{
		std::shared_ptr<Magazine> magazine(new Magazine(*((Magazine *)prod.get())));
		
		int choice;
		do
		{
			std::cout << "1. Correct number\n 2. Remove star\n 3. Start transaction\n 4. Cancel" << std::endl;
			while (!(std::cin >> choice))
			{
				std::cout << "Wrong value" << std::endl;
				std::wcin.clear();
				rewind(stdin);
			}
			switch (choice)
			{
			case 1:
			{
				int number;
				std::cout << "Enter number" << std::endl;
				while (!(std::cin >> number) || number < 0)
				{
					std::cout << "Enter good number" << std::endl;
					std::cin.clear();
					rewind(stdin);
				}
				magazine->setNumber(number);
				std::cout << "Added" << std::endl;
				system("pause");
			}
			break;
			case 2:
			{
				std::string name, surName, middleName;
				int domain;
				std::cout << "Enter name and surname" << std::endl;
				std::cin >> name >> surName >> middleName;
				if (!magazine->remStar(name, surName)) {
					std::cout << "Star not found" << std::endl;
				}
				else std::cout << "Removed" << std::endl;
				system("pause");
			}
			break;
			case 3:
			{
				std::cout << "Starting transaction" << std::endl;
				return magazine;
			}
			break;
			case 4:
			{
				std::cout << "Canceled" << std::endl;
				return NULL;
			}
			break;
			default:
				std::cout << "Wrong choice" << std::endl;
				break;
			}
		} while (choice != 5);

	}
	break;
	}
	return std::shared_ptr<Product>();
}

CreatorMod::CreatorMod(std::shared_ptr<Product> prod, int role)
{
	this->prod = prod;
	this->role = role;
}

std::shared_ptr<Product> CreatorMod::start()
{
	std::shared_ptr<Product> ans;
	switch (role)
	{
	case 0: // CHIEF
		ans = createAsChief(prod);
		break;
	case 1: // CORR
		ans = createAsCorr(prod);
		break;
	case 2: // LEAD
		ans = createAsLead(prod);
		break;
	default:
		break;
	}
	return ans;
}