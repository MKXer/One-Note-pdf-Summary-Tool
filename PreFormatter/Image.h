#pragma once
#include "SummaryElement.h"
#include <QImage>

class Image : public SummaryElement
{
public:
	Image(QImage const& image) :
		data(image)
	{

	}

	operator QImage const& () {
		return data;
	}


private:
	const QImage data;

};
