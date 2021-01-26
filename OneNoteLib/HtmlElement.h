#pragma once
#include <QString>

namespace OneNote
{

	class HtmlElement
	{
	public:
		HtmlElement() = default;
		virtual const QString getHtml() const = 0;


	protected:
		virtual QString const& getHtmlCode() const = 0;

		virtual QString const& getDefaultHtmlCode() const;
	};

}
