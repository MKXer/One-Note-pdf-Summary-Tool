#pragma once
#include "HtmlElement.h"
#include <QSize>

namespace OneNote
{

	class Image : public HtmlElement
	{
	public:
		Image(QString const& imagePath, QSize const& size);

		const QString getHtml() const;


	private:
		virtual QString const& getHtmlCode() const;

		const QString imagePath;
		const QSize imageSize;

	};

}