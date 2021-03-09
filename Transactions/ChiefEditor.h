#pragma once
#include "Employe.h"
#include <string>
#include <vector>
#include <iostream>
#include "LeadEditor.h"
#include "Corrector.h"

class ChiefEditor : public Employe
{
private:
	int commitedTransactions;
	int publishedProducts;
public:
	ChiefEditor(std::string name, std::string surName, std::string middleName);
	void commitTransaction();
	void publish();
	void employ(std::vector<std::shared_ptr<Employe>>& employes);
	void createProduct(std::vector<std::shared_ptr<Product>> &products);
	int getCommitedTransactions();
	int getPublishedProducts();
};