// Transactions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>
#include <vector>
#include "Employe.h"
#include "ChiefEditor.h"
#include "Product.h"
#include "Transaction.h"
#include "CreatorMod.h"

using namespace std;

void menu()
{
	cout << "1 - Select chief editor" << endl;
	cout << "2 - Select anoter employe "<< endl;
	cout << "3 - Exit" << endl;
}

void chiefMenu()
{
	cout << "1 - Create project" << endl;
	cout << "2 - Employ someone" << endl;
	cout << "3 - Commit/revoke transaction" << endl;
	cout << "4 - Publish product" << endl;
	cout <<	"5 - Back" << endl;
}

void employeMenu()
{
	cout << "1 - Select project" << endl;
	cout << "2 - Quit project" << endl;
	cout << "3 - Create modification" << endl;
	cout << "4 - Back" << endl;
}

int main()
{
	vector<shared_ptr<Employe>> employes;
	vector<shared_ptr<Product>> products;
	vector<Transaction<Product>> transactions;
	string name, surName, middleName;
	cout << "Enter chief's name, surname and middlename" << endl;
	cin >> name >> surName >> middleName;
	shared_ptr<ChiefEditor> chief(new ChiefEditor(name, surName, middleName));
	int choice;
	do
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			do
			{
				chiefMenu();
				cin >> choice;
				switch (choice)
				{
				case 1:
					chief->createProduct(products);
					break;
				case 2:
					chief->employ(employes);
					break;
				case 3:
					chief->commitTransaction(transactions);
					break;
				case 4:
					chief->publish();
					break;
				case 5:
					system("CLS");
					break;
				default:
					cout << "Wrong choice" << endl;
					break;
				}
			} while (choice != 5);
		}
			break;
		case 2:
		{
			for (int i = 0; i < employes.size(); i++)
			{
				cout << "Employe #" << i + 1 << endl;
				employes[i]->showInfo();
			}
			int emp;
			cout << "Select:" << endl;
			cin >> emp;
			employeMenu();
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
				employes[emp - 1]->selectProject(products);
				break;
			case 2:
				employes[emp - 1]->quitProject();
				break;
			case 3:
			{
				Transaction<Product> transaction(employes[emp-1]->getCurrenProduct());
				CreatorMod modificator(employes[emp - 1]->getCurrenProduct(), employes[emp - 1]->getRole());
				std::shared_ptr<Product> modification(modificator.start());
				transaction.begin(modification);
				transactions.push_back(transaction);
			}
				break;
			case 4:
				system("CLS");
				break;
			default:
				break;
			}

		}
			break;
		case 3:
			system("CLS");
			cout << "Bye";
			return 0;
			break;
		default:
			break;
		}
	} while (true);
}