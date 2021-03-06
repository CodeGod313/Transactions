#pragma once
#include <string>
#include "Employe.h"

class Corrector : public Employe
{
private:
	int correctedProducts;
public:
	Corrector(std::string name, std::string surName, std::string middleName);
	int getCorrectedProducts();
	void correctProduct();
};

