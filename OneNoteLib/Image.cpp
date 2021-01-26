#include "Image.h"

namespace OneNote
{
	Image::Image(QString const& imagePath, ushort width, ushort height) : HtmlElement(),
			imagePath(imagePath),
			width(width),
			height(height)
	{

	}

	const QString Image::getHtml() const {
		return getHtmlCode().arg(imagePath).arg(width).arg(height);
	}

	QString const& Image::getHtmlCode() const {
		static const QString html = getDefaultHtmlCode().arg("<img src=\"%1\" width=%2 height=%3>");
		return html;
	}

}