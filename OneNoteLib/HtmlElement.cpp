#include "HtmlElement.h"



namespace OneNote
{
	QString const& HtmlElement::getDefaultHtmlCode() const
	{
		static const QString html = QString("<html\
			 xmlns:o=\"urn:schemas-microsoft-com:office:office\"\
			 xmlns:dt=\"uuid:C2F41010-65B3-11d1-A29F-00AA00C14882\"\
			 xmlns=\"http://www.w3.org/TR/REC-html40\">\
			<head>\
				<meta http-equiv=Content-Type content=\"text/html; charset=utf-8\">\
				<meta name=ProgId content=OneNote.File>\
				<meta name=Generator content=\"Microsoft OneNote 15\">\
			</head>\
			<body lang=de style='font-family:Calibri;font-size:11.0pt'>\
					%1\
			</body></html>").remove("\t");//remove tabs so it can be pretty formatted in source code...

		return html;
	}
}