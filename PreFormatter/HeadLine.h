#pragma once

#include "SummaryElement.h"

class HeadLine : public SummaryElement
{
public:
	HeadLine(QString const& headline, double height);


	ushort getHeight() const;


private:
	const double height;
};