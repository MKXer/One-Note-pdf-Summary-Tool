#pragma once
#include <QList>
#include "SummaryElement.h"

class Summary
{
public:

	Summary() = default;

	Summary& operator<<(SummaryElement* element);


	void saveToFile(QString const& filepath);




private:
	QList<SummaryElement*> summary;
};
