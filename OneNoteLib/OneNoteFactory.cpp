#include "OneNoteFactory.h"

namespace OneNote
{
	std::unique_ptr<HtmlElement> Factory::h1(QString const& text) const
	{
		return std::make_unique<H1>(text);
	}

	std::unique_ptr<HtmlElement> Factory::h2(QString const& text) const
	{
		return std::make_unique<H2>(text);
	}

	std::unique_ptr<HtmlElement> Factory::h3(QString const& text) const
	{
		return std::make_unique<H3>(text);
	}

	std::unique_ptr<OneNote::HtmlElement> Factory::image(QString const& imagePath, ushort width, ushort height) const
	{
		return std::make_unique<Image>(imagePath,  width,  height);
	}

	std::unique_ptr<HtmlElement> Factory::importantText(QString const& text) const
	{
		return std::make_unique<ImportantText>(text);
	}

	Factory const& Factory::factory()
	{
		static Factory factory;
		return factory;
	}
}

