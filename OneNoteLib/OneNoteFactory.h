#pragma once
#include "Headline.h"
#include "Image.h"
#include "ImportantText.h"
#include "onenotelib_global.h"
#include "List.h"

namespace OneNote
{
	class ONENOTELIB_EXPORT Factory
	{

	public:

		std::unique_ptr<HtmlElement> text(QString const& text, ushort fontSize = 11) const;
		std::unique_ptr<HtmlElement> list(QString const& list, ushort fontSize = 11) const;

		std::unique_ptr<HtmlElement> h1(QString const& text) const;
		std::unique_ptr<HtmlElement> h2(QString const& text) const;
		std::unique_ptr<HtmlElement> h3(QString const& text) const;

		std::unique_ptr<HtmlElement> image(QString const& imagePath, QSize const& size ) const;

		std::unique_ptr<HtmlElement> importantText(QString const& text) const;

		std::unique_ptr<HtmlElement> newLines(uchar count) const;
		static Factory const& factory();

	private:
		Factory() = default; 
	};


};
