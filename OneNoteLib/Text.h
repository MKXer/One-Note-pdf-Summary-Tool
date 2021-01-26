#pragma once

#include "HtmlElement.h"
#include <QColor>



namespace OneNote
{

	class Text : public HtmlElement
	{
	public:
		Text(	QString const& text,
				QString const& htmlTag = "p",
				float fontSize		   = 11.0f, 
				QColor const& color	   = QColor::fromRgb(255, 255, 255));

		const QString getHtml() const;



	private:
		virtual QString const& getHtmlCode() const;

		const QString text;
		const QString htmlTag;
		const float fontSize;
		const QColor color;
	};

}
