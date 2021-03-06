#pragma once
#include "Employe.h"
#include <string>

class ChiefEditor : public Employe
{
private:
	int commitedTransactions;
	int publishedProducts;
public:
	ChiefEditor(std::string name, std::string surName, std::string middleName);
	void commitTransaction();
	void makeModification();
	int getCommitedTransactions();
	int getPublishedProducts();
};