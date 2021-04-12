#pragma once
#include <QList>
#include "SummaryElement.h"

class Summary : protected QList<SummaryElement*>
{
public:

	Summary() = default;

	using QList<SummaryElement*>::operator<<;
	using QList<SummaryElement*>::begin;
	using QList<SummaryElement*>::end;

private:
	QList<SummaryElement*> summary;
};
