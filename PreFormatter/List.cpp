#include "List.h"


List::List() : SummaryElement("", SummaryElement::Type::LIST)
{

}


List& List::operator<<(QString const& listItem)
{


	QString trimmedItem = listItem.right(listItem.size() - 1);
		
	trimmedItem =	trimmedItem.trimmed();
	 
	QString itemList = getData();



	itemList += trimmedItem;
	itemList += "\n\r";

	this->changeData(itemList);

	return *this;
}

