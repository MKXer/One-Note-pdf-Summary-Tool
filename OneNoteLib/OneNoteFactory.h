#pragma once
#include "Headline.h"
#include "Image.h"
#include "ImportantText.h"

namespace OneNote
{
	class Factory
	{

	public:
		std::unique_ptr<HtmlElement> h1(QString const& text) const;
		std::unique_ptr<HtmlElement> h2(QString const& text) const;
		std::unique_ptr<HtmlElement> h3(QString const& text) const;

		std::unique_ptr<HtmlElement> image(QString const& imagePath, ushort width, ushort height) const;

		std::unique_ptr<HtmlElement> importantText(QString const& text) const;

		static Factory const& factory();

	private:
		Factory()
		{

		}
	};


};
