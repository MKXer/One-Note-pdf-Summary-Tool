#pragma once
#include <QString>
#include <QDebug>
#include "OneNoteElement.h"

namespace OneNote
{
	class Factory
	{
	public:

		std::unique_ptr<HtmlElement> h1() const
		{
			return std::make_unique<H1>();
		}

		std::unique_ptr<HtmlElement> h2() const
		{
			return std::make_unique<H2>();
		}

		std::unique_ptr<HtmlElement> h3() const
		{
			return std::make_unique<H3>();
		}

		std::unique_ptr<HtmlElement> importantText() const
		{
			return std::make_unique<ImportantText>();
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
