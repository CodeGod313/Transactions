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
	system("CLS");
	int choice;
	do
	{
		menu();
		while (!(cin >> choice))
		{
			std::cin.clear();
			rewind(stdin);
			cout << "Wrong value" << endl;
		}
		switch (choice)
		{
		case 1:
		{
			do
			{
				system("CLS");
				chiefMenu();
				while (!(cin >> choice)) {
					cout << "Wrong value" << endl;
					cin.clear();
					rewind(stdin);
				}
				switch (choice)
				{
				case 1:
					chief->createProduct(products);
					system("pause");
					break;
				case 2:
					chief->employ(employes);
					system("pause");
					break;
				case 3:
					chief->commitTransaction(transactions);
					system("pause");
					break;
				case 4:
					chief->publish(products);
					system("pause");
					break;
				case 5:
					system("CLS");
					break;
				default:
					cout << "Wrong choice" << endl;
					system("pause");
					break;
				}
			} while (choice != 5);
		}
			break;
		case 2:
		{
			int c;
			do
			{
				system("CLS");
				if (employes.size() == 0)
				{
					cout << "No employes" << endl;
					system("pause");
					break;
				}
				for (int i = 0; i < employes.size(); i++)
				{
					cout << "Employe #" << i + 1 << endl;
					employes[i]->showInfo();
				}
				int emp;
				cout << "Select:" << endl;
				while (!(cin >> emp)) {
					cout << "Wrong value" << endl;
					cin.clear();
					rewind(stdin);
				}
				if (emp<1 || emp >employes.size()) {
					cout << "Employe not found" << endl;
					continue;
				}
				employeMenu();
				while (!(cin >> c)) {
					cout << "Wrong value" << endl;
					cin.clear();
					rewind(stdin);
				}
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
					if (employes[emp - 1]->getCurrenProduct() == NULL) {
						cout << "No selected project" << endl;
						system("pause");
						break;
					}
					bool err = false;
					for (int i = 0; i < transactions.size(); i++)
					{
						if (err = transactions[i].isUsed(employes[emp - 1]->getCurrenProduct()))
						{
							cout << "Acces denied" << endl;
							system("pause");
							break;
						}
					}
					if (err) break;
					Transaction<Product> transaction(employes[emp - 1]->getCurrenProduct());
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
					cout << "Wrong choice" << endl;
					system("pause");
					break;
				}
			} while (c != 4);
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

//I LOVE YOU
//I WANNA KISS YOU