#include "ChiefEditor.h"

ChiefEditor::ChiefEditor(std::string name, std::string surName, std::string middleName) : Employe(name, surName, middleName, CHIEF)
{
	commitedTransactions = 0;
	publishedProducts = 0;
}

int ChiefEditor::getCommitedTransactions()
{
	return commitedTransactions;
}

int ChiefEditor::getPublishedProducts()
{
	return publishedProducts;
}
