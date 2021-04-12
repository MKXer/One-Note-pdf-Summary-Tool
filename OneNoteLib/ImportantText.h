#pragma once
#include "Text.h"

namespace OneNote
{
	class ImportantText : public Text
	{
	public:
		ImportantText(QString const& text);
	
	};


	class NewLines : public HtmlElement
	{
	public:
		NewLines(uchar count) : count(count), newLinesString(createString())
		{
		}

		const QString getHtml() const {
			return getHtmlCode().arg(newLinesString);
		}


	private:
		QString createString(){
			QString retn = "";
			for (int i = 0 ; i < count; i++){
				retn += "<br>";
			}
			return retn;
		}

	
		const uchar count;
		const QString newLinesString;

		QString const& getHtmlCode() const {
			static const QString html = getDefaultHtmlCode().arg(
				"<!--StartFragment-->%1<!--EndFragment-->");

			return html;
		}

	};

}