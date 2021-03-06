#include "LeadEditor.h"

LeadEditor::LeadEditor(std::string name, std::string surName, std::string middleName) : Employe(name, surName, middleName, LEAD)
{
	addedElements = 0;
}

int LeadEditor::getNumberOfAddedElements()
{
	return addedElements;
}
