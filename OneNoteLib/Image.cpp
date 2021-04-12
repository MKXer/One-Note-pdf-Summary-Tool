#include "Image.h"

namespace OneNote
{
	Image::Image(QString const& imagePath, QSize const& imageSize) : HtmlElement(),
			imagePath(imagePath),
			imageSize(imageSize)
	{

	}

	const QString Image::getHtml() const {
		return getHtmlCode().arg(imagePath).arg(imageSize.width()).arg(imageSize.height());
	}

	QString const& Image::getHtmlCode() const {
		static const QString html = getDefaultHtmlCode().arg("<img src=\"%1\" width=%2 height=%3>");
		return html;
	}

}