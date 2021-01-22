#pragma once
#include <QString>
#include <QColor>
#include <QImage>

namespace OneNote
{

	class HtmlElement
	{
	public:
		HtmlElement()
		{

		}

	protected:
		virtual QString const& getHtmlCode() const = 0;

		virtual QString const& getDefaultHtmlCode() const
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
			</body></html>").remove("\t");//remove t so it can be pretty formatted in source code...

			return html;
		}
	};



	class Image : public HtmlElement
	{
	public:

		Image(QString const& imagePath, ushort width, ushort height) : HtmlElement(),
			imagePath(imagePath),
			width(width),
			height(height)
		{

		}

		QString getHtml() const {
			return getHtmlCode().arg(imagePath).arg(width).arg(height);
		}


	private:
		virtual QString const& getHtmlCode() const {
			static const QString html = getDefaultHtmlCode().arg("<img src=\"%1\" width=%2 height=%3>");
			return html;
		}

		const QString imagePath;
		const ushort width;
		const ushort height;

	};

	class Text : public HtmlElement
	{
	public:
		Text(QString const& htmlTag = "p", float fontSize = 11.0f, QColor const& color = QColor::fromRgb(255, 255, 255)) :
			HtmlElement(),
			htmlTag(htmlTag),
			fontSize(fontSize),
			color(color)
		{

		}

		QString getHtml(QString const& text) const {
			return getHtmlCode().arg(text).arg(htmlTag).arg(fontSize).arg(color.name());
		}

	
	private:
		virtual QString const& getHtmlCode() const {
			static const QString html = getDefaultHtmlCode().arg(
				"<%2 style='margin:0in;font-family:Calibri;font-size:%3pt;color:%4'>\
				<!--StartFragment-->%1<!--EndFragment--></%2>");

			return html;
		}

		const QString htmlTag;
		const float fontSize;
		const QColor color;
	};


	class H1 : public Text
	{
	public:

		H1() : Text("h1", 15, QColor("#1E4E79"))
		{

		}
	};


	class H2 : public Text
	{
	public:

		H2() : Text("h2", 14, QColor("#69A4D8"))
		{

		}
	};

	class H3 : public Text
	{
	public:
		H3() : Text("h3", 12, QColor("#5B9BD5"))
		{

		}
	};

	class ImportantText : public Text
	{
	public:

		ImportantText() : Text("p", 16)
		{

		}
	};


}
