#include "OneNoteFactory.h"

namespace OneNote
{

	std::unique_ptr<HtmlElement> Factory::text(QString const& text, ushort fontSize ) const
	{
		return std::make_unique<Text>(text, "p", fontSize);
	}

	std::unique_ptr<OneNote::HtmlElement> Factory::list(QString const& list, ushort fontSize /*= 11*/) const
	{
		return std::make_unique<List>(list,  fontSize);
	}

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

	std::unique_ptr<OneNote::HtmlElement> Factory::image(QString const& imagePath, QSize const& size) const
	{
		return std::make_unique<Image>(imagePath, size);
	}

	std::unique_ptr<HtmlElement> Factory::importantText(QString const& text) const
	{
		return std::make_unique<ImportantText>(text);
	}

	std::unique_ptr<HtmlElement> Factory::newLines(uchar count) const
	{
		return std::make_unique<NewLines>(count);
	}

	Factory const& Factory::factory()
	{
		static Factory factory;
		return factory;
	}
}

