#include "List.h"

namespace OneNote
{
	List::List(QString const& text,
		float fontSize, QColor const& color) :
		HtmlElement(),
		text(text),
		fontSize(fontSize),
		color(color)
	{

	}

	const QString List::getHtml() const {

		return getHtmlCode().arg(getListString());
	}

	const QString List::getListString() const {
		QString listItems;

		for (auto const& item : text.split("\n\r")) {
			listItems += getListElement(item);
		}
		
		return listItems;
	}

	const QString List::getListElement(QString const& text) const {
		return QString("<li style='margin-top:0;margin-bottom:0;vertical-align:middle'>\
		<span style = 'font-family:Calibri;font-size:%1pt'>%2</span>\
		</li>").arg(fontSize).arg(text);
	}


	QString const& List::getHtmlCode() const {
		static const QString html = getDefaultHtmlCode().arg(
			"<!--StartFragment-->\
			<ul type=disc style='margin-left:.375in;direction:ltr;unicode-bidi:embed;margin-top:0in;margin-bottom:0in'>\
			%1</ul><!--EndFragment-->");

		return html;
	}

}