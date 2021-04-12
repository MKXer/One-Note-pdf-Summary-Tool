#pragma once

#include "HtmlElement.h"
#include <QColor>

namespace OneNote
{

	class List : public HtmlElement
	{
	public:
		List(QString const& list,
			float fontSize = 11.0f,
			 QColor const& color = QColor::fromRgb(255, 255, 255));

		const QString getHtml() const;

		const QString getListString() const;

		const QString getListElement(QString const& text) const;
		const QString getListElement() const;



	private:
		virtual QString const& getHtmlCode() const;

		const QString text;
		const QString htmlTag;
		const float fontSize;
		const QColor color;
	};

}
