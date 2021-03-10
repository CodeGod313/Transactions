#pragma once
#include "Employe.h"
#include <string>
#include <vector>
#include <iostream>
#include "LeadEditor.h"
#include "Corrector.h"
#include "Book.h"
#include "Magazine.h"
#include"NewsPaper.h"
#include "Transaction.h"

class ChiefEditor : public Employe
{
private:
	int commitedTransactions;
	int publishedProducts;
public:
	ChiefEditor(std::string name, std::string surName, std::string middleName);
	void commitTransaction(std::vector<Transaction<Product>> &transactions);
	void publish(std::vector<std::shared_ptr<Product>> &products);// что нить с файликом
	void employ(std::vector<std::shared_ptr<Employe>>& employes);
	void createProduct(std::vector<std::shared_ptr<Product>> &products);
	int getCommitedTransactions();
	int getPublishedProducts();
};