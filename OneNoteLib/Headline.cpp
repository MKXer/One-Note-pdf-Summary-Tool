#include "Headline.h"

namespace OneNote
{
	H1::H1(QString const& text) : Text(text, "h1", 15, QColor("#1E4E79"))
	{

	}

	H2::H2(QString const& text) : Text(text, "h2", 14, QColor("#69A4D8"))
	{

	}


	H3::H3(QString const& text) : Text(text, "h3", 12, QColor("#5B9BD5"))
	{

	}
}