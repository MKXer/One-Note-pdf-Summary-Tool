#include "Summary.h"


Summary& Summary::operator<<(SummaryElement* element)
{
	summary << element;

	return *this;
}




void Summary::saveToFile(QString const& filepath)
{
	for (auto* item : summary)
	{
		
	}
}
