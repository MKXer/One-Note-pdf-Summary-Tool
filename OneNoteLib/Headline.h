#pragma once
#include "Text.h"


namespace OneNote
{

	class H1 : public Text
	{
	public:

		H1(QString const& text);
	};

	class H2 : public Text
	{
	public:

		H2(QString const& text);
	};

	class H3 : public Text
	{
	public:
		H3(QString const& text);

	};

}
