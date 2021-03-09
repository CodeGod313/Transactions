// Transactions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>
#include <vector>
#include "Employe.h"
#include "ChiefEditor.h"
#include "Product.h"
#include "Transaction.h"

using namespace std;

int main()
{
	vector<shared_ptr<Employe>> employes;
	vector<shared_ptr<Product>> products;
	vector<shared_ptr<Transaction<Product>>> transactions;
	string name, surName, middleName;
	cout << "Enter chief's name, surname and middlename" << endl;
	cin >> name >> surName >> middleName;
	shared_ptr<ChiefEditor> chief(new ChiefEditor(name, surName, middleName));
	employes.resize(1);
	employes[0] = chief;

}