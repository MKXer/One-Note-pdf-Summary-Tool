#pragma once
#include <QString>
#include "OneNoteFactory.h"


class SummaryElement
{
public:
	SummaryElement() = default;

	virtual std::unique_ptr<OneNote::HtmlElement> test()
	{
		return OneNote::Factory::factory().h1("test");
	}


};
