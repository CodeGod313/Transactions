#pragma once
#include "Employe.h"
#include <string>

class LeadEditor : public Employe
{
private:
	int addedElements;
public:
	LeadEditor(std::string name, std::string surName, std::string middleName);
	void addElement();
	int getNumberOfAddedElements();
};

