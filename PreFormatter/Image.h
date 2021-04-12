#pragma once
#include "SummaryElement.h"
#include <QImage>

class Image : public SummaryElement
{
public:
	Image(QString const& imagePath, QSize const& imageSize) :
		SummaryElement(imagePath, SummaryElement::Type::IMAGE),
		imageSize(imageSize)
	{

	}


	QSize const& getSize() const {
		return imageSize;
	}

private:
	const QSize imageSize;
};
