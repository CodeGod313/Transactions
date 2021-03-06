// Transactions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>
#include "Product.h"

using namespace std;

int main()
{
	unique_ptr<Product> p(new Product("kaka"));
	shared_ptr<Product> p1 = std::move(p);
	cout << p1->getName();
}