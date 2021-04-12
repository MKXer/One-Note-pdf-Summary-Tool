#include "HeadLine.h"


HeadLine::HeadLine(QString const& headline, double height) :
	SummaryElement(headline, SummaryElement::Type::HEADLINE),
	height(height)
{

}

ushort HeadLine::getHeight() const
{
	return height;
}

