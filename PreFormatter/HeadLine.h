#pragma once

#include "SummaryElement.h"

class HeadLine : public SummaryElement
{
public:
	HeadLine(QString const& headline, double height);


	ushort getHeight() const;
	operator QString const& ();

private:
	const QString data;
	const double height;
};