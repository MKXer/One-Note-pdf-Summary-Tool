#include "HeadLine.h"


HeadLine::HeadLine(QString const& headline, double height) :
	data(headline),
	height(height)
{

}

ushort HeadLine::getHeight() const
{
	return height;
}

HeadLine::operator QString const& () {
	return data;
}

