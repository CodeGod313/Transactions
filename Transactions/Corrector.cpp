#include "Corrector.h"

Corrector::Corrector(std::string name, std::string surName, std::string middleName) : Employe(name, surName, middleName, CORR)
{
	correctedProducts = 0;
}

int Corrector::getCorrectedProducts()
{
	return correctedProducts;
}
