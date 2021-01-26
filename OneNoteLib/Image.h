#pragma once
#include "HtmlElement.h"

namespace OneNote
{

	class Image : public HtmlElement
	{
	public:
		Image(QString const& imagePath, ushort width, ushort height);

		const QString getHtml() const;


	private:
		virtual QString const& getHtmlCode() const;

		const QString imagePath;
		const ushort width;
		const ushort height;

	};

}