#include "Text.h"



namespace OneNote
{
	Text::Text(QString const& text, QString const& htmlTag, 
						float fontSize, QColor const& color) :
			HtmlElement(),
			text(text),
			htmlTag(htmlTag),
			fontSize(fontSize),
			color(color)
		{

		}

	const QString Text::getHtml() const {
		return getHtmlCode().arg(text).arg(htmlTag).arg(fontSize).arg(color.name());
	}


	QString const& Text::getHtmlCode() const {
		static const QString html = getDefaultHtmlCode().arg(
			"<%2 style='margin:0in;font-family:Calibri;font-size:%3pt;color:%4'>\
			<!--StartFragment-->%1<!--EndFragment--></%2>");

		return html;
	}

}