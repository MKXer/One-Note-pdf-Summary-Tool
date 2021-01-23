#pragma once
#include <QString>
#include <QDebug>
#include "OneNoteElement.h"

namespace OneNote
{
	class Factory
	{
	public:

		std::unique_ptr<HtmlElement> h1(QString const& text) const
		{
			return std::make_unique<H1>(text);
		}

		std::unique_ptr<HtmlElement> h2(QString const& text) const
		{
			return std::make_unique<H2>(text);
		}

		std::unique_ptr<HtmlElement> h3(QString const& text) const
		{
			return std::make_unique<H3>(text);
		}

		std::unique_ptr<HtmlElement> importantText(QString const& text) const
		{
			return std::make_unique<ImportantText>(text);
		}

		static Factory const& factory()
		{
			static Factory factory;
			return factory;
		}

	private:
		Factory()
		{

		}
	};


};
